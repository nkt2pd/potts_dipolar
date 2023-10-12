#include "MonteCarlo.hpp"

#include <string>
#include <iostream>
#include <fstream>
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
int update_site_var(Measurements main_measurements, Interactions main_interactions, Properties main_properties, int k, double beta, Site *spin, int Ns, int L, double D, double J) {

    int p_new = (int) (rand1() * (double)q);
    int Sz_new = (p_new % 2 == 0) ? 1 : -1;

    double delPSpin = 0;
    double delISpin = 0;
    double delE = 0;

    for(int l=0; l<N_nn1; l++) {
        delPSpin += (main_properties.V_clock[p_new][spin[k].nn1[l]->potts] - main_properties.V_clock[spin[k].potts][spin[k].nn1[l]->potts]);
    }

    if (Sz_new == spin[k].Sz) {
        delISpin = 0;
    } else {
        for (int m = 0; m < Ns; m++) {
            delISpin += (Sz_new - spin[k].Sz)*spin[m].Sz*main_interactions.Ud(spin, k, m, L);
        }
    }

    //change in energy when spin is flipped
    delE = (J * delPSpin) + (D * delISpin);

    //spin flip or not
    double r = rand1();

    if (delE == 0) {
        //if there is no change in the energy, coin flip to see if accepted
        if (r < 0.5) {
            spin[k].potts = p_new;
            spin[k].Sz = Sz_new;

            return 1;
        } else {
            return 0;
        }
    } else {
        if (r < exp(-delE * beta)) {
            spin[k].potts = p_new;
            spin[k].Sz = Sz_new;

            return 1;
        } else {
            return 0;
        }
    }
}

double MC_sweep_var(Measurements main_measurements, Interactions main_interactions, Properties main_properties, double beta, Site *spin, int Ns, int L, double D, double J) {
    int hits = 0;
    for(int i=0; i<Ns; i++) {
        hits += update_site_var(main_measurements, main_interactions, main_properties, i, beta, spin, Ns, L, D, J);
    }
    return ((double) hits)/((double) Ns);      // success rate
}

void Metropolis_MC_Sim_var(Interactions main_interactions, Measurements main_measurements, Properties main_properties, double beta, Site *spin, int Ns, int L, const std::string L_name, int print_config, double D, double J) {

    clock_t t_start = clock();
    clock_t t_now;
    double t_diff = 0;

    int thermalize = 1000;
    int nsweep = 1;
    int ndata = 5000;

    //Run 20000 sweeps of the system to achieve equilibrium
    double accepted = 0;

    double fb[2];

    std::cout << "Thermalizing..." << std::endl;
    
    for (int i = 0; i < thermalize; i++) {
        if(i%100 == 0) {
            std::cout << "i = " << i << std::endl;
        }
        accepted += MC_sweep_var(main_measurements, main_interactions, main_properties, beta, spin, Ns, L, D, J);
    }
    std::cout << "spin update rate = " << accepted/((double) thermalize) << std::endl;

    //now start to collect data
    double E1 = 0, E2 = 0;
    double E_j = 0, E_d = 0;
    double E1_j = 0, E1_d = 0;
    double PM1 = 0, PM2 = 0, PM4 = 0;
    double IM1 = 0, IM2 = 0, IM4 = 0;
    double F1 = 0, F2 = 0, F4 = 0;
    double avg_accept = 0;

    const std::string T_val = std::to_string(1./beta);
    const std::string DJ_val = std::to_string(D/J);
    

    for (int n = 0; n < ndata; n++) {

        if(n % 1000 == 0 && print_config == 1) {
            const std::string n_val = std::to_string(n);
            const std::string config_name = "config_T" + T_val + "_DJ" + DJ_val + "_n" + n_val;

            std::ofstream config;
            config.open(".\\DJsims\\configs\\" + config_name + ".dat", std::fstream::app);

            for(int i = 0; i < Ns; i++) {
                config << spin[i].x << ", " << spin[i].y << ", " << spin[i].potts << ", " << spin[i].Sz << std::endl;
            }

            config.close();

            std::cout << "n = " << n << std::endl;
        }

        accepted = 0;
        for (int r = 0; r < nsweep; r++) {

            accepted += MC_sweep_var(main_measurements, main_interactions, main_properties, beta, spin, Ns, L, D, J);

        }
        accepted /= ((double) nsweep);
        avg_accept = (n * avg_accept + accepted) / (n + 1.);

        E_j = main_measurements.clock_energy_var(main_properties, spin, Ns, L, J);
        E_d = main_measurements.dipolar_energy_var(main_interactions, spin, Ns, L, D);

        double e = E_j + E_d;

        E1 = (n * E1 + e) / (n + 1.);
        E2 = (n * E2 + e*e) / (n + 1.);

        E1_j = (n * E1_j + E_j) / (n + 1.);
        E1_d = (n * E1_d + E_d) / (n + 1.);

        double potts_mag = main_measurements.potts_magnetization(main_properties, spin, Ns, L);

        PM1 = (n * PM1 + potts_mag) / (n + 1.);
        PM2 = (n * PM2 + pow(potts_mag, 2)) / (n + 1.);
        PM4 = (n * PM4 + pow(potts_mag, 4)) / (n + 1.);

        double ising_mag = fabs(main_measurements.ising_magnetization(spin, Ns));

        IM1 = (n * IM1 + ising_mag) / (n + 1.);
        IM2 = (n * IM2 + pow(ising_mag, 2)) / (n + 1.);
        IM4 = (n * IM4 + pow(ising_mag, 4)) / (n + 1.);

        main_measurements.compute_fb(spin, fb, Ns);

        double fm2 = pow(fb[0], 2) + pow(fb[1], 2);
            
        F1 = (n*F1 + sqrt(fm2))/(n + 1.);
        F2 = (n*F2 + fm2)/(n + 1.);
        F4 = (n*F4 + pow(fm2, 2))/(n + 1.);

    }

    t_now = clock();
    t_diff = (double)((t_now - t_start)/CLOCKS_PER_SEC);

    print(L_name, E1, E2, E1_j, E1_d, PM1, PM2, PM4, IM1, IM2, IM4, F1, F2, F4, beta, Ns, t_diff);
}