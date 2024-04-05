#include <iostream>
#include <fstream>
#include "Constants.hpp"
#include "Measurements.hpp"
#include "Interactions.hpp"
#include "Properties.hpp"
#include "Site.hpp"
#include "Setup_Lattice.hpp"
#include "MonteCarlo_timed.hpp"
#include "Housekeeping.hpp"
#include "Rand.hpp"

//If using this program, must clear files manually before running right now

int main(int argc, char *argv[]) {
    if (argc != 5) {
        std::cout << "Usage: ./potts_dipolar_Ising_singleTemp <Lattice Length> <Temp index> <D> <config_name>" << std::endl;
        return 1;
    }

    const int L = atof(argv[1]);
    double T_idx = atof(argv[2]);
    double T = T_idx*(1.5/40.) + 0.5;
    double D = atof(argv[3]);

    const int Ns = L*L;
    double J = 1.;

    Site* spin = new Site[Ns];
    Properties main_properties;
    Interactions main_interactions(L);
    Measurements main_measurements;

    const std::string L_name = std::to_string(L);
    const std::string T_name = std::to_string(T);
    const std::string D_name = std::to_string(D);
    const std::string config_name(argv[4]);
    const std::string dir_print_name = "highres_sim_singleTemp";

    main_interactions.compute_Vd(L, 200);

    // init potts and ising

    std::ifstream config(config_name);

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

    std::cout << "Thank you for choosing the Potts Model :)" << std::endl;

    std::cout << "Lattice Length = " << L << std::endl;
    std::cout << "T = " << T << std::endl;

    Metropolis_MC_Sim_timed(main_interactions, main_measurements, main_properties, 1./T, spin, Ns, L, L_name, D_name, dir_print_name, D, J);
    delete[] main_interactions.Vd;
    delete[] spin;

    return 0;
}
