#include <iostream>
#include <fstream>
#include <map>
#include "Constants.hpp"
#include "Measurements.hpp"
#include "Interactions.hpp"
#include "Properties.hpp"
#include "Site.hpp"
#include "Setup_Lattice.hpp"
#include "MonteCarlo.hpp"
#include "Housekeeping.hpp"
#include "Rand.hpp"
#include "MonteCarlo_var.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: ./potts_dipolar_Ising <D> " << std::endl;
        return 1;
    }

    double J = 1.;
    double D = atof(argv[1])/100.;

    std::map<double, int> stripe_map = {{0, 120}, {0.01, 120}, {0.02, 120}, {0.03, 120}, {0.04, 60}, {0.05, 30}, {0.06, 20}, 
                                       {0.07, 12}, {0.08, 10}, {0.09, 6}, {0.10, 6}, {0.11, 5}, {0.12, 4}, {0.13, 4},
                                        {0.14, 3}, {0.15, 3}, {0.16, 3}, {0.17, 3}, {0.18, 2}, {0.19, 2}, {0.20, 2},
                                        {0.21, 2}, {0.22, 2}, {0.23, 2}, {0.24, 2}, {0.25, 2}, {0.26, 2}, {0.27, 2},
                                        {0.28, 2}, {0.29, 2}, {0.30, 2}, {0.31, 2}, {0.32, 1}, {0.33, 1}};

    auto it = stripe_map.find(D/J);
    int h = it->second;

    int print_config = 0;
    int config_count = 0;

    const int L = 120;
    const int Ns = L * L;

    Site* spin = new Site[Ns];
    Properties main_properties;
    Interactions main_interactions(L);
    Measurements main_measurements;

    const std::string L_size(argv[1]);
    const std::string L_name = "Dipolar_Stripe" + L_size;
    
    std::ifstream Vd_read;
    Vd_read.open("Vd_file.dat");

    for(int y = 0; y < L; y++) {
        for(int x = 0; x < L; x++) {
            Vd_read >> main_interactions.Vd[y*L + x];
        }
    }

    Vd_read.close();

    init_stripe(main_measurements, main_interactions, spin, Ns, L, h);
    
    set_coordinates(spin, Ns, L);
    
    set_nn(spin, Ns, L);

    double del_T = 0.005;

    std::cout << "Thank you for choosing the Potts Model :)" << std::endl;
    std::cout << "Lattice Length = " << L << std::endl;

    for(double T = 0; T<=4; T += del_T) {

        if(config_count%5 == 0) {
            print_config = 1;
        } else {
            print_config = 0;
        }

        std::cout << "T = " << T << std::endl;
    
        Metropolis_MC_Sim_var(main_interactions, main_measurements, main_properties, 1./T, spin, Ns, L, L_name, print_config, D, J);
        
        if(T>=0.1) {
            del_T = 0.05;
        }
        if(T>=1) {
            del_T = 0.25;
        }
        config_count++;
    }

    delete[] main_interactions.Vd;
    delete[] spin;

    return 0;
} 