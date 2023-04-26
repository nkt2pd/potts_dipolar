#ifndef PROPERTIES_HPP
#define PROPERTIES_HPP

#define q 6
#define Jnn -1

#include <cmath>
#include <vector>
#include <iostream>
#include "Constants.hpp"

class Properties {
    public:
    int idx_m[q][q];
    double V_clock[q][q];
    double theta[q];
    double pb[q][q][q];

    Properties() {

        for (int i = 0; i < q; i++) {
            for (int j = 0; j < q; j++) {
                V_clock[i][j] = cos((i - j)*2.*PI/((double)q));
            }
        }

        for (int k = 0; k < q; k++) {
            theta[q] = (2 * PI * (double)k) / (double)q;
        }

        idx_m[0][0] = 3;
        idx_m[0][1] = 2;
        idx_m[0][2] = 1;
        idx_m[0][3] = 0;
        idx_m[0][4] = 5;
        idx_m[0][5] = 4;
        
        idx_m[3][0] = 3;
        idx_m[3][1] = 2;
        idx_m[3][2] = 1;
        idx_m[3][3] = 0;
        idx_m[3][4] = 5;
        idx_m[3][5] = 4;
        
        idx_m[1][0] = 5;
        idx_m[1][1] = 4;
        idx_m[1][2] = 3;
        idx_m[1][3] = 2;
        idx_m[1][4] = 1;
        idx_m[1][5] = 0;
        
        idx_m[4][0] = 5;
        idx_m[4][1] = 4;
        idx_m[4][2] = 3;
        idx_m[4][3] = 2;
        idx_m[4][4] = 1;
        idx_m[4][5] = 0;
        
        idx_m[2][0] = 1;
        idx_m[2][1] = 0;
        idx_m[2][2] = 5;
        idx_m[2][3] = 4;
        idx_m[2][4] = 3;
        idx_m[2][5] = 2;
        
        idx_m[5][0] = 1;
        idx_m[5][1] = 0;
        idx_m[5][2] = 5;
        idx_m[5][3] = 4;
        idx_m[5][4] = 3;
        idx_m[5][5] = 2;
    }

    void set_pb(double beta) {
        for(int i=0; i<q; i++) {
            for(int j=0; j<q; j++) {
                for(int k=0; k<q; k++) {
    
                    double f1 = cos((j - i)*2.*PI/((double) q));
                    double f2 = cos((k - i)*2.*PI/((double) q));
            
                    pb[i][j][k] = 1. - exp(2.*beta*Jnn*f1*f2);
                }
            }
        }
    }
};

#endif