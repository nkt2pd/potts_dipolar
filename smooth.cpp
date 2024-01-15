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

    const int L = 60;
    const int Ns = L*L;

    std::string L_name = std::to_string(L);
    std::string new_dir_name = "smoothed";

    //for all 31 values of D/J
    //1. initialize the config before the first order transition
    //2. simulate the configuration at low temperature for a while, maybe 5000 sweeps? maybe T = .03?
    //3. save the configuration in a new folder
    //config format: x, y, potts, ising

    std::map<double, double> stripe_map = {{0, 0}, {1.*0.75/30., 0}, {2.*0.75/30., 0.15}, {3.*0.75/30., 0.4}, {4.*0.75/30., 0.4},
                                        {5.*0.75/30., 0.4}, {6.*0.75/30., 0.4}, {7.*0.75/30., 0.3}, {8.*0.75/30., 0.3}, {9.*0.75/30., 0.35},
                                        {10.*0.75/30., 0.35}, {11.*0.75/30., 0.35}, {12.*0.75/30., 0.35}, {13.*0.75/30., 0.35}, {14.*0.75/30., 0.35},
                                        {15.*0.75/30., 0.35}, {16.*0.75/30., 0.35}, {17.*0.75/30., 0.35}, {18.*0.75/30., 0.4}, {19.*0.75/30., 0.3},
                                        {20.*0.75/30., 0.4}, {21.*0.75/30., 0.4}, {22.*0.75/30., 0.35}, {23.*0.75/30., 0.25}, {24.*0.75/30., 0.2},
                                        {25.*0.75/30., 0.2}, {26.*0.75/30., 0.2}, {27.*0.75/30., 0.2}, {28.*0.75/30., 0.35}, {29.*0.75/30., 0.3},
                                        {30.*0.75/30., 0.3}};

    double D = 0;
    const double J = 1.;

    Properties main_properties;
    Interactions main_interactions(L);
    Measurements main_measurements;

    std::ifstream Vd_read;
    Vd_read.open("C:\\users\\quent\\Projects\\Research\\potts_dipolar\\potts_dipolar\\Vd_file.dat");

    if (Vd_read.fail()) {
        throw std::runtime_error("Failed to open Vd_read");
    }

    for(int y = 0; y < L; y++) {
        for(int x = 0; x < L; x++) {
            Vd_read >> main_interactions.Vd[y*L + x];
        }
    }

    std::string buffer = "";

    //still need to set the other parts of each lattice point like nearest neighbors
    //and lattice point
    //Can just call set_coordinates and set_nn, and then just get the potts and ising
    //vars in the while loop

    for(int i = 0; i <= 30; i++) { //for loop to smooth out each configuration
        
        Site* spin = new Site[Ns];
        D = (double)i*0.75/30.;

        auto it = stripe_map.find(D/J);
        double T = it->second;

        std::string D_name = std::to_string(D);
        std::string T_name = std::to_string(T);
        std::string file_name = "C:\\users\\quent\\Projects\\Research\\potts_dipolar\\potts_dipolar\\heatsims3\\L=60\\DJ" + D_name + "\\T=" + T_name + "_config.dat";

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
        
        T = 0.2;
        Metropolis_MC_Sim_var(main_interactions, main_measurements, main_properties, 1./T, spin, Ns, L, L_name, D_name, new_dir_name, D, J);

        config.close();
    }
    
    return 0;
}