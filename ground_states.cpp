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

    const int L = 60;
    const int Ns = L*L;

    const double J = 1;

    Site* spin = new Site[Ns];
    Properties main_properties;
    Interactions main_interactions(L);
    Measurements main_measurements;

    std::ifstream Vd_read;
    Vd_read.open("Vd_file.dat");

    for(int y = 0; y < L; y++) {
        for(int x = 0; x < L; x++) {
            Vd_read >> main_interactions.Vd[y*L + x];
        }
    }

    Vd_read.close();

    set_coordinates(spin, Ns, L);
    set_nn(spin, Ns, L);

    std::vector<int> h_vec;

    for(int f=1; f<=(L/2); f++) {
        if(L%(2*f) == 0) {
            h_vec.push_back(f);
        }
    }

    h_vec.push_back(L);

    std::ofstream grounds_w;
    grounds_w.open("grounds.dat");

    for(int i = 0; i<=30; i++) {

        double D = (double)i*(2.5/30.);
        double ground_state = 0;
        double ground_energy = 0;
        double energy = 0;

        // const std::string DJ_val = std::to_string(D/J);
        // const std::string L_val  = std::to_string(L);
        // const std::string enrg_name = "DJ" + DJ_val + ".dat";

        // std::ofstream enrg;
        // enrg.open(enrg_name);

        // enrg << "test" << std::endl;

        for(int j = 0; j < h_vec.size(); j++) {

            if(h_vec[j]==L) {
                init_uniform(main_measurements, main_interactions, spin, Ns, L);
            } else{
                init_stripe(main_measurements, main_interactions, spin, Ns, L, h_vec[j]);
            }

            energy = main_measurements.E_tot_var(main_interactions, main_properties, spin, Ns, L, J, D);

            if(j == 0) {
                ground_energy = energy;
                ground_state = h_vec[j];
            } else {
                if(energy < ground_energy) {
                    ground_energy = energy;
                    ground_state = h_vec[j];
                }
            }
            // enrg << h_vec[j] << "\t" << energy << std::endl;

            if(j == h_vec.size() - 1) {
                // enrg << "Ground State: h = " << ground_state << std::endl;
                grounds_w << D/J << ", " << ground_state << std::endl;
            }
        }
        // enrg.close();
    }

    grounds_w.close();

    delete[] main_interactions.Vd;
    delete[] spin;

    return 0;
} 