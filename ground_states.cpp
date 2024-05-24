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

    const int L = 48;
    const int Ns = L*L;

    const double J = 1;

    Site* spin = new Site[Ns];
    Properties main_properties;
    Interactions main_interactions(L);
    Measurements main_measurements;

    // std::ifstream Vd_read;
    // Vd_read.open("Vd_file.dat");

    // for(int y = 0; y < L; y++) {
    //     for(int x = 0; x < L; x++) {
    //         Vd_read >> main_interactions.Vd[y*L + x];
    //     }
    // }

    // Vd_read.close();

    main_interactions.compute_Vd(L, 200);

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
    grounds_w.open("grounds_L48_manyD2.dat");

    int diag = 1;

    for(int i = 0; i<50; i++) {

        double D = (0.32/50.)*(double)i;
        double ground_state = 0;
        double ground_energy = 0;
        double energy = 0;

        for(int j = 0; j < h_vec.size(); j++) {

            if(h_vec[j]==L) {
                init_uniform(main_measurements, main_interactions, spin, Ns, L);
            } else{
                init_dstripe(main_measurements, main_interactions, spin, Ns, L, h_vec[j]);
            }

            energy = main_measurements.E_tot_var(main_interactions, main_properties, spin, Ns, L, J, D);

            if(j == 0) {
                ground_energy = energy;
                ground_state = h_vec[j];
                diag = 1;
            } else {
                if(energy < ground_energy) {
                    ground_energy = energy;
                    ground_state = h_vec[j];
                    diag = 1;
                }
            }

            if(h_vec[j]==L) {
                init_uniform(main_measurements, main_interactions, spin, Ns, L);
            } else{
                init_stripe(main_measurements, main_interactions, spin, Ns, L, h_vec[j]);
            }

            energy = main_measurements.E_tot_var(main_interactions, main_properties, spin, Ns, L, J, D);

            if(energy < ground_energy) {
                ground_energy = energy;
                ground_state = h_vec[j];
                diag = 0;
            }

            if (diag == 1) {
                if(j == h_vec.size() - 1) {
                    grounds_w << D/J << ", " << ground_state << ", Diagonal" << std::endl;
                }
            } else {
                if(j == h_vec.size() - 1) {
                    grounds_w << D/J << ", " << ground_state << ", Horizontal" << std::endl;
                }
            }
            
        }
    }

    grounds_w.close();

    delete[] main_interactions.Vd;
    delete[] spin;

    return 0;
} 