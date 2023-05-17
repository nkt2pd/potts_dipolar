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
    
};

#endif