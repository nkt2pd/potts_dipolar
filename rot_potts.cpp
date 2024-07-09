#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
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


int main() {

    //D = 0.025, T = 0.5, a2KT
    //D = 0.75, T = 0.8, bwKT
    //D = 0.75, T = 0.2, bwFOnKT
    //D = 0.75, T = 0.07, aFO

    double J = 1.;
    double D = 0.75;
    double T = 0.07;

    const int L = 48;
    const int Ns = L * L;

    const std::string L_name = std::to_string(L);

    const std::string D_name = std::to_string(D/J);
    const std::string T_name = std::to_string(T);

    const std::string region = "aFO";

    int rot_num = 1;
    const std::string rotnum_name = std::to_string(rot_num);
    

    std::string file_name_in =  "C:\\users\\quent\\Projects\\Research\\potts_dipolar\\potts_dipolar\\DJ 0.75 rot configs\\DJ0.750000_rot0_config.dat";
    std::string file_name_out = "C:\\users\\quent\\Projects\\Research\\potts_dipolar\\potts_dipolar\\DJ 0.75 rot configs\\DJ0.750000_rot" + rotnum_name + "_config.dat";
    
    std::ifstream config_in(file_name_in);
    std::ofstream config_out(file_name_out);

    std::string buffer = "";

    while(!config_in.eof()) { //feed in potts and ising of each config
        config_in >> buffer;
        if(config_in.eof()) {
            break;
        }
        config_out << stod(buffer) << ", ";

        config_in >> buffer;
        config_out << stod(buffer) << ", ";

        config_in >> buffer;
        config_out << mod(stoi(buffer) + rot_num, 6) << ", ";

        if(mod(stoi(buffer) + rot_num, 6) == 0 || mod(stoi(buffer) + rot_num, 6) == 2 || mod(stoi(buffer) + rot_num, 6) == 4) {
            config_out << "1" << std::endl;
        } else {
            config_out << "-1" << std::endl;
        }

        config_in >> buffer;
        
    }

    return 0;
}