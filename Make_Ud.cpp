#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "Setup_Lattice.hpp"
#include "Interactions.hpp"
#include "Site.hpp"

int main() {

    int L = 15;
    int Ns = L*L;

    Site* spin = new Site[Ns];
    Interactions matrices(L);

    set_coordinates(spin, Ns, L);

    std::cout << "Computing Matrix..." << std::endl;

    matrices.compute_Vd(L, 20000);

    std::ofstream Vd_file;
    std::ofstream Ud_file;

    Vd_file.open("Vd_matrix_20000.dat", std::fstream::app);

    Vd_file << std::fixed << std::setprecision(7);

    for(int i = 0; i < L; i++) {
        for(int j = 0; j < L; j++) {
            Vd_file << matrices.Vd[i*L + j] << "\t";
        }
        Vd_file << std::endl;
    }

    std::cout << "Done!" << std::endl;

    Vd_file.close();

    return 0;
}