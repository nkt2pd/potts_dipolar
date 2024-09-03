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
    double D = 0.75;
    double T = 1.1;

    const int L = 48;
    const int Ns = L * L;

    const std::string region = "bwKT";

    const std::string L_name = std::to_string(L);


    const std::string D_name = std::to_string(D/J);
    const std::string T_name = std::to_string(T);

    //collect data for histogram

    for(int rot_num = 0; rot_num < 6; rot_num++) {

        std::string rotnum_name = std::to_string(rot_num);

        std::string file_name_in = "C:\\users\\quent\\Projects\\Research\\potts_dipolar\\potts_dipolar\\rot_configs\\DJ0.75_T1.1\\DJ0.750000_T" + T_name + "_rot" + rotnum_name + "_config.dat";

        std::string file_name_out = "C:\\users\\quent\\Projects\\Research\\potts_dipolar\\potts_dipolar\\highres_histograms\\hist_data_simmed\\9_2_24\\" + region + "_rot" + rotnum_name + "_hist_simmed.dat";

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
        int box_L = 8;
        int num_stamps = L/box_L;

        if(L % box_L != 0) {
            std::runtime_error("Box Size and Lattice Size are not compatible");
        }

        //need to write this code to get the x position and y position using the indices of for loop
        //then in a while loop, check the x position of each line until it matches. if it does,
        //see if the y position matches. if it does, we have our line and we can go on to get its potts variable


        config_in.clear();
        config_in.seekg(0);
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

    return 0;
}