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

    const int L = 48;
    const int Ns = L*L;

    const double J = 1;
    const double D = 0.15;
    int h = 3;

    Site* spin = new Site[Ns];
    Properties main_properties;
    Interactions main_interactions(L);
    Measurements main_measurements;

    set_coordinates(spin, Ns, L);
    set_nn(spin, Ns, L);
    init_dstripe(main_measurements, main_interactions, spin, Ns, L, h);

    std::string config_name = "ground_L" + std::to_string(L) + "_D" + std::to_string(D) + ".dat";
    std::ofstream config(config_name);

    // for(int i = 0; i < L; i++) {
    //     if(spin[i*h].potts == 0) {
    //         random_potts = 2*(int)(3*rand1());
    //     } else if(spin[i*h].potts == 1) {
    //         random_potts = 1 + 2*(int)(3*rand1());
    //     }
    //     for(int j = 0; j < h; j++) {
    //         config << spin[h*i + j].x << ", " << spin[h*i + j].y << ", " << random_potts << ", " << spin[h*i + j].Sz << std::endl;
    //     }
    // }
    int layer = 1;
    int random_potts = 2*(int)(3*rand1());

    for(int y = 0; y < L; y++) {
        for(int x = 0; x < L; x++) {
            config << spin[y*L + x].x << ", " << spin[y*L + x].y << ", " << random_potts << ", " << spin[y*L + x].Sz << std::endl;
        }
        if(layer%h == 0) {
            if(rand1() < 0.5) {
                random_potts += 1;
            }else {
                random_potts -= 1;
            }
            random_potts = mod(random_potts, q);
            layer = 1;
        } else{
            layer++;
        }
    }

    config.close();

    return 0;
}