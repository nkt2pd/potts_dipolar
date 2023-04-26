#include "MonteCarlo.hpp"

#include <string>
#include <iostream>
#include <ctime>
#include "Constants.hpp"
#include "Measurements.hpp"
#include "Interactions.hpp"
#include "Properties.hpp"
#include "Site.hpp"
#include "Rand.hpp"
#include "Housekeeping.hpp"
#include "Cluster.hpp"

//update_site and MC_sweep are both functions for the Metropolis Algorithm
//Metropolis_MC_Sim performs the Monte Carlo simulation using the Metropolis Algorithm

//generate_cluster, flip_cluster, and sweep_cluster are all functions for the
//Wolff Cluster Algorithm
//Wolff_MC_Sim performs the Monte Carlo simulation using the Wolff Cluster Algorithm

//Metroplis Algorithm

//test a new state, accept or reject the state based on parameters. 
int update_site(Measurements main_measurements, Interactions main_interactions, Properties main_properties, int k, double beta, Site *spin, int Ns, int L) {

    int p_new = (int) (rand1() * (double)q);
    int Sz_new = (p_new % 2 == 0) ? 1 : -1;

    double delPSpin = 0;
    double delISpin = 0;
    double delE = 0;

    for(int l=0; l<N_nn1; l++) {
        delPSpin += (main_properties.V_clock[p_new][spin[k].nn1[l]->potts] - main_properties.V_clock[spin[k].potts][spin[k].nn1[l]->potts]);
    }

    if (Sz_new = spin[k].Sz) {
        delISpin = 0;
    } else {
        for (int m = 0; m < Ns; m++) {
            delISpin += (Sz_new - spin[k].Sz)*spin[k].Sz*main_interactions.Ud(spin, k, m, L);
        }
    }

    //change in energy when spin is flipped
    delE = (-Jnn * Jnn * delPSpin) + (Dp * delISpin);

    double r = rand1();

    if (delE == 0) {
        //if there is no change in the energy, coin flip to see if accepted
        if (r < 0.5) {
            spin[k].potts = p_new;
            spin[k].Sz = Sz_new;
            main_measurements.Ed_curr += Dp * delISpin;

            return 1;
        } else return 0;
    } else {
        if (r < exp(-delE * beta)) {
            spin[k].potts = p_new;
            spin[k].Sz = Sz_new;
            main_measurements.Ed_curr += Dp * delISpin;

            return 1;
        } else {
        return 0;
        }
    }
}

double MC_sweep(Measurements main_measurements, Interactions main_interactions, Properties main_properties, double beta, Site *spin, int Ns, int L) {
    int hits = 0;
    for(int i=0; i<Ns; i++) {
        hits += update_site(main_measurements, main_interactions, main_properties, i, beta, spin, Ns, L);
    }
    return ((double) hits)/((double) Ns);      // success rate
}

void Metropolis_MC_Sim(Interactions main_interactions, Measurements main_measurements, Properties main_properties, double beta, Site *spin, int Ns, int L, const std::string L_name) {

    clock_t t_start = clock();
    clock_t t_now;
    double t_diff = 0;

    int thermalize = 2000;
    int nsweep = 50;
    int ndata = 500000;

    //Run 5000 sweeps of the system to achieve equilibrium
    double accepted = 0;
    
    for (int i = 0; i < thermalize; i++) {
        accepted += MC_sweep(main_measurements, main_interactions, main_properties, beta, spin, Ns, L);
    }
    std::cout << "spin update rate = " << accepted/((double) thermalize) << std::endl;

    //now start to collect data
    double E1 = 0, E2 = 0;
    double PM1 = 0, PM2 = 0, PM4 = 0;
    double IM1 = 0, IM2 = 0, IM4 = 0;
    double avg_accept = 0;

    int system_check = 1000;

    for (int n = 0; n < ndata; n++) {

        if(n % system_check == 0) std::cout << "n = " << n << std::endl;

        accepted = 0;
        for (int r = 0; r < nsweep; r++) {

            accepted += MC_sweep(main_measurements, main_interactions, main_properties, beta, spin, Ns, L);

        }
        accepted /= ((double) nsweep);
        avg_accept = (n * avg_accept + accepted) / (n + 1.);

        double e = main_measurements.clock_energy(main_properties, spin, Ns, L) + main_measurements.Ed_curr;

        E1 = (n * E1 + e) / (n + 1.);
        E2 = (n * E2 + e*e) / (n + 1.);

        double potts_mag = main_measurements.potts_magnetization(main_properties, spin, Ns, L);

        PM1 = (n * PM1 + potts_mag) / (n + 1.);
        PM2 = (n * PM2 + pow(potts_mag, 2)) / (n + 1.);
        PM4 = (n * PM4 + pow(potts_mag, 4)) / (n + 1.);

        double ising_mag = main_measurements.ising_magnetization(spin, Ns);

        IM1 = (n * IM1 + ising_mag) / (n + 1.);
        IM2 = (n * IM2 + pow(ising_mag, 2)) / (n + 1.);
        IM4 = (n * IM4 + pow(ising_mag, 4)) / (n + 1.);
    }

    t_now = clock();
    t_diff = (double)((t_now - t_start)/CLOCKS_PER_SEC);

    print(L_name, E1, E2, PM1, PM2, PM4, beta, Ns, t_diff);
}


//Wolff Cluster Algorithm

int generate_cluster(Cluster main_cluster, Properties main_properties, Site *spin, int Ns) {
    
    main_cluster.new_cluster.clear();

    main_cluster.new_pSpin_cluster = (int)(rand1() * q);
    int initial_site = (int)(rand1() * Ns);

    main_cluster.new_cluster.push_back(initial_site);
    spin[initial_site].cluster_tag = 1;

    main_cluster.prev_additions.push_back(initial_site);

    std::vector<int>::const_iterator i;

    int curr_site = 0;
    int curr_neighbor = 0;
    while(main_cluster.prev_additions.size() > 0) {
        
        main_cluster.new_additions.clear();

        for(i = main_cluster.prev_additions.begin(); i != main_cluster.prev_additions.end(); ++i) {
            
            curr_site = (*i);

            for(int j = 0; j < N_nn1; j++) {
                
                curr_neighbor = spin[curr_site].nn1[j]->idx;

                if(spin[curr_neighbor].cluster_tag == 0 && 
                   rand1() < main_properties.pb[main_cluster.new_pSpin_cluster][spin[curr_site].potts][spin[curr_neighbor].potts]) {
                    main_cluster.new_cluster.push_back(curr_neighbor);
                    spin[curr_neighbor].cluster_tag = 1;

                    main_cluster.new_additions.push_back(curr_neighbor);
                }
            }
        }
        main_cluster.prev_additions = main_cluster.new_additions;
    }
    return main_cluster.new_cluster.size();
}

int flip_cluster(Cluster main_cluster, Measurements main_measurements, Interactions main_interactions, Properties main_properties, Site *spin, int Ns, int L, double beta) {
    std::vector<int>::const_iterator i;

    int curr_site = 0;

    for(i = main_cluster.new_cluster.begin(); i != main_cluster.new_cluster.end(); ++i) {
        
        curr_site = (*i);

        spin[curr_site].new_potts = main_properties.idx_m[main_cluster.new_pSpin_cluster][spin[curr_site].potts];
        spin[curr_site].new_Sz = (spin[curr_site].new_potts % 2 == 0) ? 1 : -1;
    }

    double excluded_sum = 0;
    double included_sum = 0;

    for(i = main_cluster.new_cluster.begin(); i != main_cluster.new_cluster.end(); ++i) {

        curr_site = (*i);

        for(int j = 0; j < Ns; j++) {

            if(spin[j].cluster_tag == 0) {

                excluded_sum += (spin[curr_site].new_Sz - spin[curr_site].Sz)*spin[j].Sz*main_interactions.Ud(spin, curr_site, j, L);

            } else {

                included_sum += (spin[curr_site].new_Sz*spin[j].new_Sz - spin[curr_site].Sz*spin[j].Sz)*main_interactions.Ud(spin, curr_site, j, L);

            }
        }
    }

    double delE = Dp*(excluded_sum + 0.5*included_sum);


    double r = rand1();
    if(r < exp(-beta*delE)) {

        for(i = main_cluster.new_cluster.begin(); i != main_cluster.new_cluster.end(); ++i) {
            curr_site = (*i);

            spin[curr_site].potts = spin[curr_site].new_potts;
            spin[curr_site].Sz = spin[curr_site].new_Sz;

            spin[curr_site].cluster_tag = 0;
        }

        main_measurements.Ed_curr += delE;

        return 1;

    } else {

        for(i = main_cluster.new_cluster.begin(); i != main_cluster.new_cluster.end(); ++i) {
            curr_site = (*i);

            spin[curr_site].cluster_tag = 0;
        }

        return 0;
    }
}

double sweep_cluster(Cluster main_cluster, Measurements main_measurements, Interactions main_interactions, Properties main_properties, Site *spin, int Ns, int L, double beta, double num_sweeps) {
    int hits = 0;
    int total_sites = 0;
    int total_accepted_sites = 0;
    int cluster_size = 0;

    for (int i = 0; i < num_sweeps; i++) {
        cluster_size = generate_cluster(main_cluster, main_properties, spin, Ns);

        total_sites += cluster_size;

        int accepted = flip_cluster(main_cluster, main_measurements, main_interactions, main_properties, spin, Ns, L, beta);
        if (accepted == 1) {
            hits++;
            total_accepted_sites += cluster_size;
        }
    }

    main_cluster.avg_size = ((double)total_sites / (double)num_sweeps);
    main_cluster.avg_flipped_size = (hits == 0) ? 0 : ((double)total_accepted_sites / (double)hits);

    return ((double)hits / (double)num_sweeps);
}

void Wolff_MC_Sim(Cluster main_cluster, Measurements main_measurements, Interactions main_interactions, Properties main_properties, Site *spin, int Ns, int L, double beta, const std::string L_name) {
    
    clock_t t_start = clock();
    clock_t t_now;
    double t_diff = 0;
    
    main_properties.set_pb(beta);

    double hits = 0;
    double thermalize = 2000;
    double sweep_therm = 2;
    int npts = 500000;

    double E1 = 0, E2 = 0;
    double PM1 = 0, PM2 = 0, PM4 = 0;
    double IM1 = 0, IM2 = 0, IM4 = 0;

    //thermalize the system
    for(int i = 0; i < thermalize; i++) {
        hits += sweep_cluster(main_cluster, main_measurements, main_interactions, main_properties, spin, Ns, L, beta, sweep_therm);
    }
    std::cout << "Cluster acceptance rate: " << (hits*100) / (double)thermalize << "% " << std::endl;
    std::cout << "Cluster Average Size: " << main_cluster.avg_size << std::endl;
    //Collect data
    std::cout << "gathering data... " << std::endl;

    int system_check = 100000;

    for(int n = 0; n < npts; n++) {

        if (n % system_check == 0) std::cout << "n = " << n << std::endl;

        hits = sweep_cluster(main_cluster, main_measurements, main_interactions, main_properties, spin, Ns, L, beta, sweep_therm);

        double e = main_measurements.clock_energy(main_properties, spin, Ns, L) + main_measurements.Ed_curr;

        E1 = (n*E1 + e) / (n + 1.);
        E2 = (n*E2 + e*e) / (n + 1.);

        double potts_mag = main_measurements.potts_magnetization(main_properties, spin, Ns, L);

        PM1 = (n * PM1 + potts_mag) / (n + 1.);
        PM2 = (n * PM2 + pow(potts_mag, 2)) / (n + 1.);
        PM4 = (n * PM4 + pow(potts_mag, 4)) / (n + 1.);

        double ising_mag = main_measurements.ising_magnetization(spin, Ns);

        IM1 = (n * IM1 + ising_mag) / (n + 1.);
        IM2 = (n * IM2 + pow(ising_mag, 2)) / (n + 1.);
        IM4 = (n * IM4 + pow(ising_mag, 4)) / (n + 1.);
    }

    t_now = clock();
    t_diff = (double)((t_now - t_start)/CLOCKS_PER_SEC);

    print(L_name, E1, E2, PM1, PM2, PM4, beta, Ns, t_diff);
}
