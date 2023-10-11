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

    for(int i = 31; i<=33; i++) {

        double h_arr[13] = {1, 2, 3, 4, 5, 6, 10, 12, 15, 20, 30, 60, 120};
        double D = (double)i*(0.3/30.);
        double ground_state = 0;
        double ground_energy = 0;
        double energy = 0;

        const std::string DJ_val = std::to_string(D/J);
        const std::string enrg_name = "DJ" + DJ_val + ".dat";

        std::ofstream enrg;
        enrg.open(enrg_name);

        for(int j = 0; j < 13; j++) {

            if(h_arr[j]==120) {
                init_uniform(main_measurements, main_interactions, spin, Ns, L);
            } else{
                init_stripe(main_measurements, main_interactions, spin, Ns, L, h_arr[j]);
            }

            energy = main_measurements.E_tot_var(main_interactions, main_properties, spin, Ns, L, J, D);

            if(j == 0) {
                ground_energy = energy;
                ground_state = h_arr[j];
            } else {
                if(energy < ground_energy) {
                    ground_energy = energy;
                    ground_state = h_arr[j];
                }
            }
            enrg << h_arr[j] << "\t" << energy << std::endl;

            if(j == 12) {
                enrg << "Ground State: h = " << ground_state << std::endl;
            }
        }
        enrg.close();
    }

    delete[] main_interactions.Vd;
    delete[] spin;

    return 0;
} 