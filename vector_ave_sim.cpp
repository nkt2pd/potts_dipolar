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

    //D = 0.025, T = 0.5, a2KT
    //D = 0.75, T = 0.8, bwKT
        //try T = 1.1 for next bwKT histogram w singlTemp_4 data
    //D = 0.75, T = 0.2, bwFOnKT
    //D = 0.75, T = 0.07, aFO

    double J = 1.;
    double D = 0.75;
    double T = 0.07;

    const int L = 48;
    const int Ns = L * L;

    //sim configs

    std::string hist_type = "";
    std::string hist_name = "";

    Site* spin = new Site[Ns];
    Properties main_properties;
    Interactions main_interactions(L);
    Measurements main_measurements;

    main_interactions.compute_Vd(L, 200);

    int box_L = 8;
    int num_stamps = L/box_L;

    if(L % box_L != 0) {
        std::runtime_error("Box Size and Lattice Size are not compatible");
    }

    for(int m = 0; m < 6; m++) {
        std::cout << "m = " << m << std::endl;
        std::string rotnum_name = std::to_string(m);
        for(int n = 0; n < 1; n++) {
            if(n == 0) {
                hist_type = "a2KT";
            } else if(n == 1) {
                hist_type = "bwKT";
            } else if (n == 2) {
                hist_type = "bwFOnKT";
            } else {
                hist_type = "aFO";
            }

            //hist_type override
            hist_type = "bwKT";
            hist_name = hist_type + "_rot" + rotnum_name;

            if(hist_type == "a2KT") {
                T = 0.5;
                D = 0.025;
            } else if(hist_type == "bwKT") {
                T = 1.1;
                D = 0.75;
            } else if(hist_type == "bwFOnKT"){
                T = 0.2;
                D = 0.75;
            } else{
                T = 0.07;
                D = 0.75;
            }

            std::cout << "Simulating for " << hist_type << " and m = " << m << std::endl;

            std::string D_name = std::to_string(D);
            std::string T_name = std::to_string(T);

            std::string file_name_in = "C:\\users\\quent\\Projects\\Research\\potts_dipolar\\potts_dipolar\\rot_configs\\DJ0.75_T1.1\\DJ0.750000_T" + T_name + "_rot" + rotnum_name + "_config.dat";

            std::string file_name_out = "C:\\users\\quent\\Projects\\Research\\potts_dipolar\\potts_dipolar\\highres_histograms\\hist_configs_simmed\\9_2_24\\" + hist_name + "_config_simmed.dat";

            std::ifstream sim_in(file_name_in);
            std::ofstream sim_out(file_name_out);

            if (sim_in.fail()) {
                throw std::runtime_error("Failed to open input 1");
            }

            // std::ifstream Vd_read;
            // Vd_read.open("Vd_file.dat");

            // for(int y = 0; y < L; y++) {
            //     for(int x = 0; x < L; x++) {
            //         Vd_read >> main_interactions.Vd[y*L + x];
            //     }
            // }

            // Vd_read.close();

            int iter = 0;
            std::string buffer = "";

            while(!sim_in.eof()) { //feed in potts and ising of each config
                sim_in >> buffer;
                if(sim_in.eof()) {
                    break;
                }

                sim_in >> buffer;

                sim_in >> buffer;
                buffer.erase(buffer.size()-1);
                spin[iter].potts = std::stoi(buffer);

                sim_in >> buffer;
                spin[iter].Sz = std::stoi(buffer);

                iter++;
            }

            set_coordinates(spin, Ns, L);
            
            set_nn(spin, Ns, L);

            int thermalize = 1000;
            int accepted = 0;
            double therm_T = 1.1;

            // std::cout << "Thermalizing at higher Temp. T = " << therm_T << std::endl;
            // for(int i = 0; i < thermalize ; i++) {
            //     if(i%100 == 0) {
            //         std::cout << "Simulating... i = " << i << std::endl;
            //     }
            //     accepted += MC_sweep_var(main_measurements, main_interactions, main_properties, 1./therm_T, spin, Ns, L, D, J);
            // }

            std::cout << "Thermalizing at T = " << T << std::endl;
            for (int i = 0; i < thermalize; i++) {
                if(i%100 == 0) {
                    std::cout << "Simulating... i = " << i << std::endl;
                }
                accepted += MC_sweep_var(main_measurements, main_interactions, main_properties, 1./T, spin, Ns, L, D, J);
            }

            std::cout << "spin update rate = " << accepted/((double) thermalize) << std::endl; 

            for(int i = 0; i < Ns; i++) {
                sim_out << spin[i].x << ", " << spin[i].y << ", " << spin[i].potts << ", " << spin[i].Sz << std::endl;
            }

            sim_in.close();
            sim_out.close();

            //collect data for histogram
            std::cout << "Collecting Hist Data for " << hist_type << " and m = " << m << std::endl;

            file_name_in = file_name_out;

            file_name_out = "C:\\users\\quent\\Projects\\Research\\potts_dipolar\\potts_dipolar\\highres_histograms\\hist_data_simmed\\9_2_24\\" + hist_name + "_hist_simmed.dat";

            std::ifstream config_in(file_name_in);
            std::ofstream config_out(file_name_out);\

            if (config_in.fail()) {
                throw std::runtime_error("Failed to open input 2");
            }

            double p = 0, px = 0, py = 0;
            int idx_x = 0, idx_y = 0;
            double x = 0, y = 0;


            double sum_x = 0, sum_y = 0;
            double ave_x = 0, ave_y = 0;
            double count = 0;

            //need to write this code to get the x position and y position using the indices of for loop
            //then in a while loop, check the x position of each line until it matches. if it does,
            //see if the y position matches. if it does, we have our line and we can go on to get its potts variable

            for(int i = 0; i < num_stamps; i++) { //x position of lower left corner of box
                for(int j = 0; j < num_stamps; j++) { //y position of lower left corner of box
                    count = 0;
                    sum_x = 0;
                    sum_y = 0;
                    ave_x = 0;
                    ave_y = 0;

                    for(int k = 0; k < box_L; k++) { //y position within box from left
                        for(int l = 0; l < box_L; l++) { //x position within box from bottom

                            idx_x = box_L*i + l;
                            idx_y = box_L*j + k;

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
        }
    }

    return 0;
}