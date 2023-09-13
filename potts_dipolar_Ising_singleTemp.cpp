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
    if (argc != 3) {
        std::cout << "Usage: ./potts_dipolar_Ising_singleTemp <Lattice Length> <Temp>" << std::endl;
        return 1;
    }

    const int L = atof(argv[1]);
    double T = atof(argv[2]);
    const int Ns = pow(L, 3) - pow(L - 1, 3);

    Site* spin = new Site[Ns];
    Properties main_properties;
    Interactions main_interactions(L);
    Measurements main_measurements;

    const std::string L_size(argv[1]);
    const std::string L_name = "Potts_Metrop" + L_size;
    
    main_interactions.compute_Vd(L, 200);
    
    init_uniform(main_measurements, main_interactions, spin, Ns, L);
    
    // set_coordinates(spin, Ns, L);

    set_hex_coordinates(spin, Ns, L);

    set_hex_nn(spin, Ns, L);
    
    // set_nn(spin, Ns, L);
    
    init_random(main_measurements, main_interactions, spin, Ns, L);

    std::cout << "Thank you for choosing the Potts Model :)" << std::endl;

    std::cout << "Lattice Length = " << L << std::endl;
    std::cout << "T = " << T << std::endl;

    main_properties.set_pb(1./T);
    
    Metropolis_MC_Sim(main_interactions, main_measurements, main_properties, 1./T, spin, Ns, L, L_name);

    delete[] main_interactions.Vd;
    delete[] spin;

    return 0;
} 
