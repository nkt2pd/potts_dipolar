#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

int main(int argc, char* argv[]) {

    std::string file_name_in = "./smoothed/L=60/DJ0.675000/T=4.000000_config.dat";
    std::string file_name_out = "./figs/disordered_hist.dat";

    std::ifstream config_in(file_name_in);
    std::ofstream config_out(file_name_out);

    std::string buffer = "";

    double p = 0, px = 0, py = 0;
    const double PI = 3.14159265358979323846264338327950288419;
    int L = 60;
    int x = 0, y = 0;

    //need to write this code to get the x position and y position using the indices of for loop
    //then in a while loop, check the x position of each line until it matches. if it does,
    //see if the y position matches. if it does, we have our line and we can go on to get its potts variable

    for(int i = 0; i < 10; i++) { //x position of lower left corner of box
        for(int j = 0; j < 10; j++) { //y position of lower left corner of box
            for(int k = 0; k < 10; k++) { //x position within box from left
                for(int l = 0; l < 10; l++) { //y position within box from bottom

                    x = 5*i + k;
                    y = 5*j + l;

                    while(!config_in.eof()){
                        config_in >> buffer;
                        if(stoi(buffer) == x) {
                            config_in >> buffer;
                            if(stoi(buffer) == y) {
                                config_in >> buffer;

                                p = stod(buffer);
                                px = cos(PI*p/3);
                                py = sin(PI*p/3);
                                config_out << px << ", " << py;
                                break;
                            } else {
                                config_in >> buffer;
                                config_in >> buffer;
                            }
                        }
                    }

                }
            }
        }
    }

    return 0;
}