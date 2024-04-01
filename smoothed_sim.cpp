#include <iostream>
#include <fstream>
#include <map>
#include <filesystem>
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
    double D = atof(argv[1])*0.75/30.;

    const int L = 60;
    const int Ns = L * L;

    Site* spin = new Site[Ns];
    Properties main_properties;
    Interactions main_interactions(L);
    Measurements main_measurements;

    const std::string L_name = std::to_string(L);

    std::ifstream Vd_read;
    Vd_read.open("Vd_file.dat");

    for(int y = 0; y < L; y++) {
        for(int x = 0; x < L; x++) {
            Vd_read >> main_interactions.Vd[y*L + x];
        }
    }

    const std::string new_dir_name = "phasediagram_sims";
    const std::string D_name = std::to_string(D/J);
    std::filesystem::create_directories("./" + new_dir_name + "/L=" + L_name + "/DJ" + D_name);
    
    Vd_read.close();

    //init potts and ising

    std::string file_name = "./smoothed/L=60/DJ" + D_name + "/T=0.200000_config.dat";

    std::ifstream config(file_name);

    if (config.fail()) {
        throw std::runtime_error("Failed to open config");
    }

    int iter = 0;
    std::string buffer = "";

    while(!config.eof()) { //feed in potts and ising of each config
        config >> buffer;
        if(config.eof()) {
            break;
        }

        config >> buffer;

        config >> buffer;
        // buffer.erase(buffer.size()-1);
        spin[iter].potts = std::stoi(buffer);

        config >> buffer;
        spin[iter].Sz = std::stoi(buffer);

        iter++;
    }

    config.close();
    
    set_coordinates(spin, Ns, L);
    
    set_nn(spin, Ns, L);

    double del_T = 0.005;

    std::cout << "Thank you for choosing the Potts Model :)" << std::endl;
    std::cout << "Lattice Length = " << L << std::endl;

    for(double T = 0; T<=4; T += del_T) {

        if(T == 0) {
            std::ofstream config_out;
            config_out.open("./" + new_dir_name + "/L=" + L_name + "/DJ" + D_name + "/init_config.dat", std::fstream::app);

            for(int i = 0; i < Ns; i++) {
                config_out << spin[i].x << ", " << spin[i].y << ", " << spin[i].potts << ", " << spin[i].Sz << std::endl;
            }

            config_out.close();
        }

        std::cout << "T = " << T << std::endl;
    
        Metropolis_MC_Sim_var(main_interactions, main_measurements, main_properties, 1./T, spin, Ns, L, L_name, D_name, new_dir_name, D, J);
        
        if(T>=0.1) {
            del_T = 0.05;
        }
        if(T>=1) {
            del_T = 0.25;
        }
    }

    delete[] main_interactions.Vd;
    delete[] spin;

    return 0;
} 
