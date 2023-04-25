#include <iostream>
#include "Measurements.hpp"
#include "Interactions.hpp"
#include "Site.hpp"
#include "Setup_Lattice.hpp"
#include "Rand.hpp"

void init_uniform(Measurements main_measurements, Interactions main_interactions, Site *spin, int Ns, int L) {
    for (int i=0; i < Ns; i++) {
        spin[i].Sz = 1;
        spin[i].potts = 0;
    }
    main_measurements.Ed_curr = main_measurements.dipolar_energy(main_interactions, spin, Ns, L);
}

void init_random(Measurements main_measurements, Interactions main_interactions, Site *spin, int Ns, int L) {
    for (int i = 0; i < Ns; i++) {
        spin[i].potts = (int) (rand1() * 6);
        spin[i].Sz = (spin[i].potts % 2 == 0) ? 1 : -1;
    }
    main_measurements.Ed_curr = main_measurements.dipolar_energy(main_interactions, spin, Ns, L);
}

inline int index(int x, int y, int L) {
    return x*L+y;
}

void set_coordinates(Site *spin, int Ns, int L) {
    int y = 0;
    int x = 0;
    for(int i=0; i<Ns; i++) {
        spin[i].lattice_pt[0] = x;
        spin[i].lattice_pt[1] = y;
        spin[i].idx = i;
        spin[i].x = x + 0.5*y;
        spin[i].y = 0.5*sqrt(3)*y;
        x++;
        if (x%L == 0) {
            y++;
            x = 0;
        }
    }
}

void set_nn(Site *spin, int Ns, int L) { //sets the 2*D nearest neighbors for each site in the system
    int k;
    int x, y;
    for(int i=0; i<Ns; i++) { 
        x = spin[i].lattice_pt[0];
		y = spin[i].lattice_pt[1];

        k = index(mod(x+1, L), y, L);
        spin[i].nn1[0] = &spin[k];
        
        k = index(x, mod(y+1, L), L);
        spin[i].nn1[1] = &spin[k];
        
        k = index(mod(x-1, L), mod(y+1, L), L);
        spin[i].nn1[2] = &spin[k];
        
        k = index(mod(x-1, L), y, L);
        spin[i].nn1[3] = &spin[k];
        
        k = index(x, mod(y-1, L), L);
        spin[i].nn1[4] = &spin[k];
        
        k = index(mod(x+1, L), mod(y-1, L), L);
        spin[i].nn1[5] = &spin[k];

    }
}

void set_cluster_tag(Site *spin, int Ns) {
    for (int i = 0; i < Ns; i++) {
        spin[i].cluster_tag = 0;
    }
}

