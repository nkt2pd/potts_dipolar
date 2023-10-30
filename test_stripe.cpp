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

int main() {

    const int L = 60;
    const int Ns = L * L; 

    Site* spin = new Site[Ns];
    Properties main_properties;
    Interactions main_interactions(L);
    Measurements main_measurements;

    init_dstripe(main_measurements, main_interactions, spin, Ns, L, 3);

    set_coordinates(spin, Ns, L);
    
    set_nn(spin, Ns, L);

    std::ofstream config;
    config.open("config_dtest.dat");

    for(int i = 0; i < Ns; i++) {
        config << spin[i].x << ", " << spin[i].y << ", " << spin[i].potts << ", " << spin[i].Sz << std::endl;
    }

    config.close();

    return 0;
}