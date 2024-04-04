#include <cstdio>
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

int main() {

    const int L = 60;
    const int Ns = L * L;

    Site* spin = new Site[Ns];
    Properties main_properties;
    Interactions main_interactions(L);
    Measurements main_measurements;

    std::string file_name = "C:\\users\\quent\\Projects\\Research\\potts_dipolar\\potts_dipolar\\smoothed\\L=60\\DJ0.750000\\init_config.dat";

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
        buffer.erase(buffer.size()-1);
        spin[iter].potts = std::stoi(buffer);

        config >> buffer;
        spin[iter].Sz = std::stoi(buffer);

        iter++;
    }

    config.close();

    set_coordinates(spin, Ns, L);
    
    set_nn(spin, Ns, L);

    std::ofstream L48("C:\\users\\quent\\Projects\\Research\\potts_dipolar\\potts_dipolar\\smoothed\\L=48\\DJ0.750000\\init_config.dat");
    std::ofstream L36("C:\\users\\quent\\Projects\\Research\\potts_dipolar\\potts_dipolar\\smoothed\\L=36\\DJ0.750000\\init_config.dat");

    for(int j = 0; j < L; j++) {
        for(int i = 0; i < L; i++) {
            int idx = index(i, j, L);
            
            if(spin[idx].lattice_pt[0] < 36 && spin[idx].lattice_pt[1] < 36) {
                L36 << spin[idx].x << ", " << spin[idx].y << ", " << spin[idx].potts << ", " << spin[idx].Sz << std::endl;
                L48 << spin[idx].x << ", " << spin[idx].y << ", " << spin[idx].potts << ", " << spin[idx].Sz << std::endl;
            } else if(spin[idx].lattice_pt[0] < 48 && spin[idx].lattice_pt[1] < 48) {
                L48 << spin[idx].x << ", " << spin[idx].y << ", " << spin[idx].potts << ", " << spin[idx].Sz << std::endl;
            }
        }
    }

    L48.close();
    L36.close();

    //want to cut off all x and y values above a certain value, which I think we can do using the lattice_pt[] array
    //If a lattice_pt[] array val < certain value, print that point to new data file. Otherwise skip it.
    //This will give me configurations to smooth out and eventually run

    return 0;
}