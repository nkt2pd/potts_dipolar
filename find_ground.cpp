#include <iostream>
#include <fstream>
#include "Constants.hpp"
#include "Measurements.hpp"
#include "Interactions.hpp"
#include "Properties.hpp"
#include "Site.hpp"
#include "Setup_Lattice.hpp"
#include "MonteCarlo.hpp"
#include "Housekeeping.hpp"
#include "Rand.hpp"

//If using this program, must clear files manually before running right now

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: ./potts_dipolar_Ising_singleTemp <Lattice Length>" << std::endl;
        return 1;
    }

    const int L = atof(argv[1]);
    const int Ns = L*L;

    Site* spin = new Site[Ns];
    Properties main_properties;
    Interactions main_interactions(L);
    Measurements main_measurements;

    const std::string L_size(argv[1]);
    const std::string L_name = "Potts_Metrop" + L_size;
    
    main_interactions.compute_Vd(L, 200);
    
    set_coordinates(spin, Ns, L);
    
    set_nn(spin, Ns, L);

    double ground_energy = 0;

    std::ofstream enrg;
    enrg.open("ground_energy.dat");

    for(int i = 0; i < 6; i++) {
        double h_arr[6] = {1, 2, 3, 4, 6, 12};

        const std::string h_val = std::to_string(int(h_arr[i]));
        const std::string stripe_name = "stripe_h" + h_val + "_.dat";

        std::ofstream stripe_config;
        stripe_config.open(stripe_name);

        init_stripe(main_measurements, main_interactions, spin, Ns, L, h_arr[i]);

        ground_energy = main_measurements.E_tot(main_interactions, main_properties, spin, Ns, L);

        enrg << h_arr[i] << ", " << ground_energy << std::endl;

        for(int j = 0; j < Ns; j++) {
            stripe_config << spin[j].x << ", " << spin[j].y << ", " << spin[j].potts << ", " << spin[j].Sz << std::endl;
        }

        stripe_config.close();
    }
    
    enrg.close();

    delete[] main_interactions.Vd;
    delete[] spin;

    return 0;
} 
