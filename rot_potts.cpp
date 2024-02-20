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

    double J = 1.;
    double D = 0.025;
    double T = 0.7;

    const int L = 60;
    const int Ns = L * L;

    const std::string L_name = std::to_string(L);

    const std::string D_name = std::to_string(D/J);
    const std::string T_name = std::to_string(T);

    std::string file_name_in =  "C:\\users\\quent\\Projects\\Research\\potts_dipolar\\potts_dipolar\\smoothed\\L=" + L_name + "\\DJ" + D_name + "\\T=" + T_name + "_config.dat";
    std::string file_name_out = "C:\\users\\quent\\Projects\\Research\\potts_dipolar\\potts_dipolar\\figs\\hist_configs\\a2KT_rot5_hist.dat";
    
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
        config_out << mod(stoi(buffer) + 5, 6) << ", ";

        config_in >> buffer;
        config_out << buffer << std::endl;
    }

    return 0;
}