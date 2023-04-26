#ifndef INTERACTIONS_HPP
#define INTERACTIONS_HPP

#define _USE_MATH_DEFINES

#include <cmath>
#include "Site.hpp"
#include "Housekeeping.hpp"

class Interactions {
    public:
    double *Vd;

    Interactions(int L) {
        
        Vd = new double[L*L];
    }

    void compute_Vd(int L, int N_max) {
        double dr0[2], dr[2];
    
        for(int x=0; x<L; x++)
            for(int y=0; y<L; y++) {
        
            if(x == 0 && y == 0) { 
                Vd[x*L + y] = 0;
            } else {
        
                Vd[x*L + y] = 0;
            
                dr0[0] = x + 0.5*y;
                dr0[1] = 0.5*sqrt(3.)*y;
            
                for(int m=-N_max; m<=N_max; m++)
                for(int n=-N_max; n<=N_max; n++) {
                
                    dr[0] = dr0[0] + L*(m + 0.5*n);
                    dr[1] = dr0[1] + L*(0.5*sqrt(3.)*n);
                
                    double r2 = pow(dr[0], 2) + pow(dr[1], 2);
                
                    Vd[x*L + y] += 1./pow(r2, 1.5);
                
                
                }
            }
        }
    }

    /*void compute_Ud(Site *spin, int Ns, int L) {
        for(int i = 0; i < Ns; i++) {
            for(int j = 0; j < Ns; j++) {
                int dx = spin[j].lattice_pt[0] - spin[i].lattice_pt[0];
                int dy = spin[j].lattice_pt[1] - spin[i].lattice_pt[1];

                Ud[i*L + j] = 0.5*(this->Vd[mod(dx, L)*L + mod(dy, L)] + this->Vd[mod(-dx, L)*L + mod(-dy, L)]);
            }
        }
    }*/

    inline double Ud(Site *spin, int i, int j, int L) {
        int dx = spin[j].lattice_pt[0] - spin[i].lattice_pt[0];
        int dy = spin[j].lattice_pt[1] - spin[i].lattice_pt[1];
    
        return 0.5*(this->Vd[mod(dx, L)*L + mod(dy, L)] + this->Vd[mod(-dx, L)*L + mod(-dy, L)]);
    }
};

#endif