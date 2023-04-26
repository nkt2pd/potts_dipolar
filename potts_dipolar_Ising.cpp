#include <iostream>
#include "Constants.hpp"
#include "Measurements.hpp"
#include "Interactions.hpp"
#include "Properties.hpp"
#include "Site.hpp"
#include "Setup_Lattice.hpp"
#include "MonteCarlo.hpp"
#include "Housekeeping.hpp"
#include "Rand.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: ./potts_dipolar_Ising <Lattice Length>" << std::endl;
        return 1;
    }

    const int L = atof(argv[1]);
    const int Ns = L * L;

    Site* spin = new Site[Ns];
    Properties main_properties;
    Interactions main_interactions(L);
    Measurements main_measurements;

    const std::string L_size(argv[1]);
    const std::string L_name = "Potts_ising" + L_size;
    
    main_interactions.compute_Vd(L, 200);
    
    clear_files(L_name);

    init_uniform(main_measurements, main_interactions, spin, Ns, L);
    
    set_coordinates(spin, Ns, L);

    std::cout << "test" << std::endl;
    
    set_nn(spin, Ns, L);
    
    init_random(main_measurements, main_interactions, spin, Ns, L);

    double del_T = 0.1;

    std::cout << "Thank you for choosing the Potts Model :)" << std::endl;
            
    for(double T = 1.5; T>0; T -= del_T) {

        std::cout << "Lattice Length = " << L << std::endl;
        std::cout << "T = " << T << std::endl;

        main_properties.set_pb(1./T);
    
        Metropolis_MC_Sim(main_interactions, main_measurements, main_properties, 1./T, spin, Ns, L, L_name);
        
    }

    delete[] main_interactions.Vd;
    delete[] spin;

    return 0;
} 