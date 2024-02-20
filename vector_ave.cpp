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

int main(int argc, char* argv[]) {

    //get new configuration

    double J = 1.;
    double D = 0.675;
    double T = 1.25;

    const int L = 60;
    const int Ns = L * L;

    Site* spin = new Site[Ns];
    Properties main_properties;
    Interactions main_interactions(L);
    Measurements main_measurements;

    const std::string L_name = std::to_string(L);
    
    std::ifstream Vd_read;
    Vd_read.open("Vd_file.dat");

    for(int y = 0; y < L; y++) {
        for(int x = 0; x < L; x++) {
            Vd_read >> main_interactions.Vd[y*L + x];
        }
    }

    Vd_read.close();

    const std::string new_dir_name = "figs\\configs";
    const std::string D_name = std::to_string(D/J);
    const std::string T_name = std::to_string(T);

    init_stripe(main_measurements, main_interactions, spin, Ns, L, 3);

    set_coordinates(spin, Ns, L);
    
    set_nn(spin, Ns, L);

    double thermalize = 10000;
    double accepted = 0;
    double beta = 1./T;

    for (int i = 0; i < thermalize; i++) {
        if(i%100 == 0) {
            std::cout << i/100 << "%" << std::endl;
        }
        accepted += MC_sweep(main_measurements, main_interactions, main_properties, beta, spin, Ns, L);
    }
    std::cout << "spin update rate = " << accepted/((double) thermalize) << std::endl;

    std::ofstream config("C:\\users\\quent\\Projects\\Research\\potts_dipolar\\figs\\hist_configs\\L=" + L_name + "\\DJ" + D_name + "\\T=" + T_name + "thermed_config.dat");

    for(int i = 0; i < Ns; i++) {
        config << spin[i].x << ", " << spin[i].y << ", " << spin[i].potts << ", " << spin[i].Sz << std::endl;
    }

    config.close();

    //collect data for histogram

    std::string file_name_in = "C:\\users\\quent\\Projects\\Research\\potts_dipolar\\figs\\hist_configs\\L=" + L_name + "\\DJ" + D_name + "\\T=" + T_name + "thermed_config.dat";

    std::string file_name_out = "C:\\users\\quent\\Projects\\Research\\potts_dipolar\\figs\\hist_configs\\bwKT_2_hist.dat";

    std::ifstream config_in(file_name_in);
    std::ofstream config_out(file_name_out);

    if (config_in.fail()) {
        throw std::runtime_error("Failed to open input");
    }

    std::string buffer = "";

    double p = 0, px = 0, py = 0;
    int idx_x = 0, idx_y = 0;
    double x = 0, y = 0;


    double sum_x = 0, sum_y = 0;
    double ave_x = 0, ave_y = 0;
    double count = 0;

    //need to write this code to get the x position and y position using the indices of for loop
    //then in a while loop, check the x position of each line until it matches. if it does,
    //see if the y position matches. if it does, we have our line and we can go on to get its potts variable


    config_in.clear();
    config_in.seekg(0);
        for(int i = 0; i < 11; i++) { //x position of lower left corner of box
            for(int j = 0; j < 11; j++) { //y position of lower left corner of box
                count = 0;
                sum_x = 0;
                sum_y = 0;
                ave_x = 0;
                ave_y = 0;

                for(int k = 0; k < 10; k++) { //y position within box from left
                    for(int l = 0; l < 10; l++) { //x position within box from bottom

                        idx_x = 5*i + l;
                        idx_y = 5*j + k;

                        x = (double)idx_x + 0.5*(double)idx_y;
                        y = 0.5*sqrt(3)*(double)idx_y;

                        while(!config_in.eof()){
                            config_in >> buffer;

                            if(stod(buffer) <= x + 0.1 && stod(buffer) >= x - 0.1) {
                                config_in >> buffer;
                                if(stod(buffer) <= y + 0.1 && stod(buffer) >= y - 0.1) {
                                    config_in >> buffer;

                                    p = stod(buffer);
                                    px = cos(PI*p/3);
                                    py = sin(PI*p/3);
                                
                                    sum_x += px;
                                    sum_y += py;
                                    count++;

                                    config_in.clear();
                                    config_in.seekg(0);
                                    break;

                                } else {
                                    config_in >> buffer;
                                    config_in >> buffer;

                                }
                            } else {
                                config_in >> buffer;
                                config_in >> buffer;
                                config_in >> buffer;

                            }
                        }

                    }
                }
                ave_x = sum_x/count;
                ave_y = sum_y/count;
                config_out << ave_x << ", " << ave_y << std::endl;
            }
        }
    config_in.close();
    config_out.close();

    return 0;
}