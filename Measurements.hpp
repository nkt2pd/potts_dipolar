#ifndef MEASUREMENTS_HPP
#define MEASUREMENTS_HPP

#define _USE_MATH_DEFINES

#include <cmath>
#include "Site.hpp"
#include "Interactions.hpp"
#include "Properties.hpp"
#include "Constants.hpp"

class Measurements {
    public:
    double Ed_curr = 0;

    double clock_energy(Properties main_properties, Site *spin, int Ns, int L) {
        double sum = 0;
        for(int i=0; i<Ns; i++) {
           for(int k=0; k<N_nn1; k++) {
               sum += main_properties.V_clock[spin[i].potts][spin[i].nn1[k]->potts];
           }
     }
        return 0.5 * Jnn * sum;
    }

    double dipolar_energy(Interactions main_interactions, Site *spin, int Ns, int L) {
    
        double sum = 0;
        for(int i=0; i<Ns; i++) {
    
            for(int j=0; j<Ns; j++) {
                sum += main_interactions.Ud(spin, i, j, L)*spin[i].Sz*spin[j].Sz;
            }
        }
    
        return 0.5 * Dp * sum;
    }

    inline double E_tot(Interactions main_interactions, Properties main_properties, Site *spin, int Ns, int L) {
    
        return this->clock_energy(main_properties, spin, Ns, L) + this->dipolar_energy(main_interactions, spin, Ns, L);
    }

    double clock_energy_var(Properties main_properties, Site *spin, int Ns, int L, double J) {
        double sum = 0;
        for(int i=0; i<Ns; i++) {
           for(int k=0; k<N_nn1; k++) {
               sum += main_properties.V_clock[spin[i].potts][spin[i].nn1[k]->potts];
           }
     }
        return -0.5 * J * sum;
    }

    double dipolar_energy_var(Interactions main_interactions, Site *spin, int Ns, int L, double D) {
    
        double sum = 0;
        for(int i=0; i<Ns; i++) {
    
            for(int j=0; j<Ns; j++) {
                sum += main_interactions.Ud(spin, i, j, L)*spin[i].Sz*spin[j].Sz;
            }
        }
    
        return 0.5 * D * sum;
    }

    inline double E_tot_var(Interactions main_interactions, Properties main_properties, Site *spin, int Ns, int L, double J, double D) {
    
        return this->clock_energy_var(main_properties, spin, Ns, L, J) + this->dipolar_energy_var(main_interactions, spin, Ns, L, D);
    }

    double potts_magnetization(Properties main_properties, Site *spin, int Ns, int L) {
    
        double xsum = 0, ysum = 0, sum = 0;

        for (int i = 0; i < Ns; i++) {
            xsum += cos(main_properties.theta[spin[i].potts]);
            ysum += sin(main_properties.theta[spin[i].potts]);
        }
        xsum /= (double) Ns;
        ysum /= (double) Ns;

        sum = sqrt((xsum*xsum) + (ysum*ysum));

        return sum;
    }

    double ising_magnetization(Site *spin, int Ns) {
        int sum = 0;
    
        for(int i=0; i<Ns; i++) {
        
            sum += spin[i].Sz;
        }
    
        return ((double) sum)/((double) Ns);
    }

    double compute_fb(Site *spin, double *fb, int Ns) {
    
        int Nb_x[3];

        for(int k=0; k<3; k++) Nb_x[k] = 0;
        
        for(int i=0; i<Ns; i++) {
            
            for(int k=0; k<3; k++) {
                
                if(spin[i].Sz != spin[i].nn1[2*k]->Sz) Nb_x[k]++;
            
            }
        }
        
        int sum = Nb_x[0] + Nb_x[1] + Nb_x[2];
        
        fb[0] = ((double) (Nb_x[1] + Nb_x[2] - 2*Nb_x[0]))/((double) sum)/sqrt(6.);
        fb[1] = ((double) (Nb_x[1] - Nb_x[2]))/((double) sum)/sqrt(2.);
    
        return ((double) sum)/((double) 3*Ns);
}
    
};

#endif