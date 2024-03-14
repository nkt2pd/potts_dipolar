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
        std::cout << "Usage: ./potts_dipolar_varL <L> " << std::endl;
        return 1;
    }

    double J = 1.;
    double D = 0.025;

    const int L = 36 + 12*atoi(argv[1]);
    const int Ns = L * L;

    Site* spin = new Site[Ns];
    Properties main_properties;
    Interactions main_interactions(L);
    Measurements main_measurements;

    const std::string L_name = std::to_string(L);
    const std::string D_name = std::to_string(D);
    const std::string new_dir_name = "highres_sim";
    
    main_interactions.compute_Vd(L, 200);

    // std::ifstream Vd_read;
    // Vd_read.open("Vd_file.dat");

    // for(int y = 0; y < L; y++) {
    //     for(int x = 0; x < L; x++) {
    //         Vd_read >> main_interactions.Vd[y*L + x];
    //     }
    // }
    
    // Vd_read.close();

    //init potts and ising

    // std::string file_name = "C::\\users\\quent\\Projects\\Research\\potts_dipolar\\potts_dipolar\\" + new_dir_name + "\\L=" + L_name + "\\DJ0.025000\\init_config.dat";

    // std::ifstream config(file_name);

    // if (config.fail()) {
    //     throw std::runtime_error("Failed to open config");
    // }

    // int iter = 0;
    // std::string buffer = "";

    // while(!config.eof()) { //feed in potts and ising of each config
    //     config >> buffer;
    //     if(config.eof()) {
    //         break;
    //     }

    //     config >> buffer;

    //     config >> buffer;
    //     buffer.erase(buffer.size()-1);
    //     spin[iter].potts = std::stoi(buffer);

    //     config >> buffer;
    //     spin[iter].Sz = std::stoi(buffer);

    //     iter++;
    // }

    set_coordinates(spin, Ns, L);
    
    set_nn(spin, Ns, L);

    init_uniform(main_measurements, main_interactions, spin, Ns, L);

    double del_T = 0.02;

    std::cout << "Thank you for choosing the Potts Model :)" << std::endl;
    std::cout << "Lattice Length = " << L << std::endl;

    for(double T = 0.5; T<=2.5; T += del_T) {

        // if(T == 0) {
        //     std::ofstream config;
        //     config.open("./" + new_dir_name + "/L=" + L_name + "/DJ0.025000/init_config.dat", std::fstream::app);

        //     for(int i = 0; i < Ns; i++) {
        //         config << spin[i].x << ", " << spin[i].y << ", " << spin[i].potts << ", " << spin[i].Sz << std::endl;
        //     }

        //     config.close();
        // }

        std::cout << "T = " << T << std::endl;
    
        Metropolis_MC_Sim_var(main_interactions, main_measurements, main_properties, 1./T, spin, Ns, L, L_name, D_name, new_dir_name, D, J);
    }

    delete[] main_interactions.Vd;
    delete[] spin;

    return 0;
} 
