#include <iostream>
#include <fstream>
#include "Constants.hpp"
#include "Measurements.hpp"
#include "Interactions.hpp"
#include "Properties.hpp"
#include "Site.hpp"
#include "Setup_Lattice.hpp"
#include "MonteCarlo.hpp"
#include "Housekeeping.hpp"
#include "Rand.hpp"

int main() {

    const int L = 120;
    const int Ns = L*L;

    Site* spin = new Site[Ns];
    Properties main_properties;
    Interactions main_interactions(L);
    Measurements main_measurements;

    std::ifstream Vd_read;
    Vd_read.open("Vd_file.dat");

    double Vd_test[L*L];

    for(int y = 0; y < L; y++) {
        for(int x = 0; x < L; x++) {
            Vd_read >> Vd_test[y*L + x];
        }
    }

    for(int i = 0; i<=30; i++) {
        double D = (double)i*(5./30.);
    }

    const std::string L_name = "Potts_Metrop";
    
    main_interactions.compute_Vd(L, 200);

    for(int y = 0; y < L; y++) {
        for(int x = 0; x < L; x++) {
            if(Vd_test[y*L + x] != main_interactions.Vd[y*L + x]) {
                std::cout << "Uh oh boss";
            }
        }
    }
    
    // set_coordinates(spin, Ns, L);
    
    // set_nn(spin, Ns, L);

    delete[] main_interactions.Vd;
    delete[] spin;

    return 0;
} 