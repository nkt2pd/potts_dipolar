#include "MonteCarlo.hpp"

#include <string>
#include <iostream>
#include "Rand.hpp"
#include "Housekeeping.hpp"

//update_site and MC_sweep are both functions for the Metropolis Algorithm
//Metropolis_MC_Sim performs the Monte Carlo simulation using the Metropolis Algorithm



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

    int thermalize = 20000;
    int nsweep = 50;
    int ndata = 50000000;

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

    int system_check = 100000;

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

    print(L_name, E1, E2, PM1, PM2, PM4, beta, Ns);
}
