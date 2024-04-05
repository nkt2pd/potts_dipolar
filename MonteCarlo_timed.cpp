#include "MonteCarlo.hpp"

#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <filesystem>
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

//Metroplis Algorithm

//test a new state, accept or reject the state based on parameters. 
int update_site_timed(Measurements main_measurements, Interactions main_interactions, Properties main_properties, int k, double beta, Site *spin, int Ns, int L, double D, double J) {

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
    delE = (-1 * J * delPSpin) + (D * delISpin);

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

double MC_sweep_timed(Measurements main_measurements, Interactions main_interactions, Properties main_properties, double beta, Site *spin, int Ns, int L, double D, double J) {
    int hits = 0;
    for(int i=0; i<Ns; i++) {
        hits += update_site_timed(main_measurements, main_interactions, main_properties, i, beta, spin, Ns, L, D, J);
    }
    return ((double) hits)/((double) Ns);      // success rate
}

void Metropolis_MC_Sim_timed(Interactions main_interactions, Measurements main_measurements, Properties main_properties, double beta, Site *spin, int Ns, int L, const std::string L_name, const std::string D_name, const std::string dir_print_name, double D, double J) {

    clock_t t_start = clock();
    clock_t t_now = clock();
    double t_diff = 0;

    int nsweep = 10;

    //Run 1000 sweeps of the system to achieve equilibrium
    double accepted = 0;

    double fb[2];

    clock_t t_therm_start = clock();
    clock_t t_therm_now = clock();

    int n_therm = 0;

    std::cout << "start timer" << std::endl;

    while ((double)((t_therm_now - t_therm_start)/CLOCKS_PER_SEC) < 60) {

        accepted += MC_sweep_timed(main_measurements, main_interactions, main_properties, beta, spin, Ns, L, D, J);

        t_therm_now = clock();
        n_therm++;

        if(n_therm % 1000 == 0) {
            std::cout << "Thermalizing... n = " << n_therm << std::endl;
        }

    }

    std::cout << "spin update rate = " << accepted/((double) n_therm) << std::endl;

    const std::string T_val = std::to_string(1./beta);

    std::ofstream config;
    config.open("./" + dir_print_name + "/L=" + L_name + "/DJ" + D_name + "/T=" + T_val + "_config.dat", std::fstream::app);

    for(int i = 0; i < Ns; i++) {
        config << spin[i].x << ", " << spin[i].y << ", " << spin[i].potts << ", " << spin[i].Sz << std::endl;
    }

    config.close();

    //now start to collect data
    double E1 = 0, E2 = 0;
    double E_j = 0, E_d = 0;
    double E1_j = 0, E1_d = 0;
    double PM1 = 0, PM2 = 0, PM4 = 0;
    double IM1 = 0, IM2 = 0, IM4 = 0;
    double F1 = 0, F2 = 0, F4 = 0;
    double avg_accept = 0;
    
    clock_t t_data_start = clock();
    clock_t t_data_now = clock();

    int n = 0;

    while ((double)((t_data_now - t_data_start)/CLOCKS_PER_SEC) < 60) {

        accepted = 0;
        for (int r = 0; r < nsweep; r++) {

            accepted += MC_sweep_timed(main_measurements, main_interactions, main_properties, beta, spin, Ns, L, D, J);

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

        n++;

        t_data_now = clock();
    }

    std::ofstream n_config;
    n_config.open("./" + dir_print_name + "/L=" + L_name + "/DJ" + D_name + "/datapoints.dat", std::fstream::app);

    for(int i = 0; i < Ns; i++) {
        n_config << "T = " << T_val << ", n = " << n << std::endl;
    }

    n_config.close();

    t_now = clock();
    t_diff = (double)((t_now - t_start)/CLOCKS_PER_SEC);

    print(L_name, D_name, dir_print_name, E1, E2, E1_j, E1_d, PM1, PM2, PM4, IM1, IM2, IM4, F1, F2, F4, beta, Ns, t_diff);
}
