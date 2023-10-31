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

    std::map<double, int> stripe_map = {{0, 60}, {1.*0.5/30., 60}, {2.*0.5/30., 60}, {3.*0.5/30., 60}, {4.*0.5/30., 60},
                                        {5.*0.5/30., 30}, {6.*0.5/30., 30}, {7.*0.5/30., 15}, {8.*0.5/30., 10}, {9.*0.5/30., 6},
                                        {10.*0.5/30., 5}, {11.*0.5/30., 5}, {12.*0.5/30., 3}, {13.*0.5/30., 3}, {14.*0.5/30., 3},
                                        {15.*0.5/30., 3}, {16.*0.5/30., 2}, {17.*0.5/30., 2}, {18.*0.5/30., 2}, {19.*0.5/30., 2},
                                        {20.*0.5/30., 2}, {21.*0.5/30., 2}, {22.*0.5/30., 2}, {23.*0.5/30., 2}, {24.*0.5/30., 2},
                                        {25.*0.5/30., 2}, {26.*0.5/30., 1}, {27.*0.5/30., 1}, {28.*0.5/30., 1}, {29.*0.5/30., 1},
                                        {30.*0.5/30., 1}};

    int diag = 1;
    double T = 1.;

    for(int i = 0; i<=30; i++) {

        double D = (double)i*(.5/30.);
        const std::string D_name = std::to_string(D);

        std::ofstream grounds_w;
        grounds_w.open("./stateflips/D=" + D_name + ".dat");
        double ground_state = 0;
        double ground_energy = 0;
        double energy = 0;

        auto it = stripe_map.find(D/J);
        int h = it->second;
        
        double init_energy = 0;

        init_dstripe(main_measurements, main_interactions, spin, Ns, L, h);
        init_energy = main_measurements.E_tot_var(main_interactions, main_properties, spin, Ns, L, J, D);

        for(int k = 0; k < h_vec.size(); k++) {
            double diag_energy = 0;

            init_dstripe(main_measurements, main_interactions, spin, Ns, L, h_vec[k]);
            diag_energy = main_measurements.E_tot_var(main_interactions, main_properties, spin, Ns, L, J, D);

            grounds_w << "D/J = " << D/J << "T = 0.1 Prob to flip from Diagonal h = " << h << " to Diagonal h = " << h_vec[k] << ": " << 100*exp(-1.*(diag_energy - init_energy)/T) << "%" << std:: endl;
        }

        for(int l = 0; l < h_vec.size(); l++) {
            double hz_energy = 0;

            init_stripe(main_measurements, main_interactions, spin, Ns, L, h_vec[l]); 
            hz_energy = main_measurements.E_tot_var(main_interactions, main_properties, spin, Ns, L, J, D);

            grounds_w << "D/J = " << D/J << "T = 0.1 Prob to flip from Diagonal h = " << h << " to Horizontal h = " << h_vec[l] << ": " << 100*exp(-1.*(hz_energy - init_energy)/T) << "%" << std:: endl;

        }
        grounds_w.close();
    }

    delete[] main_interactions.Vd;
    delete[] spin;

    return 0;
} 