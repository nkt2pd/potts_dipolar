#include <cstdio>
#include <map>
#include <fstream>
#include <string>
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
#include "MonteCarlo_var.hpp"

int main () {

    const int L = 36;
    const int Ns = L*L;

    std::string L_name = std::to_string(L);
    std::string new_dir_name = "smoothed";

    double D = 0.75;
    const double J = 1.;

    Properties main_properties;
    Interactions main_interactions(L);
    Measurements main_measurements;

    main_interactions.compute_Vd(L, 200);

    std::string buffer = "";

    Site* spin = new Site[Ns];

    std::string D_name = std::to_string(D);
    std::string file_name = "C:\\users\\quent\\Projects\\Research\\potts_dipolar\\potts_dipolar\\smoothed\\L=" + L_name + "\\DJ" + D_name + "\\init_config.dat";

    std::ifstream config(file_name);

    if (config.fail()) {
        throw std::runtime_error("Failed to open config");
    }

    int iter = 0;

    set_coordinates(spin, Ns, L);
    set_nn(spin, Ns, L);

    while(!config.eof()) { //feed in potts and ising of each config
        config >> buffer;
        if(config.eof()) {
            break;
        }

        config >> buffer;

        config >> buffer;
        buffer.erase(buffer.size()-1);
        spin[iter].potts = std::stoi(buffer);

        config >> buffer;
        spin[iter].Sz = std::stoi(buffer);

        iter++;
    }
    std::cout << "Done Setting up. Now smoothing for D/J = " << D << std::endl;
    //simulate configuration and save in new directory
        
    double T = 0.05;
    Metropolis_MC_Sim_var(main_interactions, main_measurements, main_properties, 1./T, spin, Ns, L, L_name, D_name, new_dir_name, D, J);

    config.close();
    
    return 0;
}