#include <iostream>
#include <fstream>
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
    return y*L+x;
}

void set_coordinates(Site *spin, int Ns, int L) {
    int y = 0;
    int x = 0;
    for(int i=0; i<Ns; i++) {
        spin[i].lattice_pt[0] = x;
        spin[i].lattice_pt[1] = y;
        spin[i].idx = i;
        spin[i].x = (double)x + 0.5*(double)y;
        spin[i].y = 0.5*sqrt(3)*(double)y;
        x++;
        if (x%L == 0) {
            y++;
            x = 0;
        }
    }
}

void set_hex_coordinates(Site *spin, int Ns, int L) {
    std::ofstream coord_test;
    coord_test.open("hex_coords.dat", std::fstream::app);

    double x = 0, y = 0;
    int index = 0;
    for(int i = 0; i < L; i++) {

        y = sqrt(3)*(double)i/2.;

        for(int j = 0; j < 2*L-1-i; j++) {

            x = (-(2.*L-i-2.)/2.) + j;

            spin[index].x = x;
            spin[index].y = y;
            coord_test << index << ", " << x << ", " << y << std::endl;
            index++;

            if(y!=0) {
                spin[index].x = x;
                spin[index].y = -1*y;
                coord_test << index << ", " << x << ", " << -1*y << std::endl;
                index++;
            }

        }
    }
    coord_test.close();
}

void set_nn(Site *spin, int Ns, int L) { //sets the q nearest neighbors for each site in the system
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

//set nn process:
//check candidate nearest neighbor to see if its magnitude < R
//If it is, set it as NN and move on
//If it is not, move in the opposite direction until a point is reached
//Where magnitude > R, then go back a point and set the NN
//Repeat for all q NN for each of the Ns spins.

void set_hex_nn(Site *spin, int Ns, int L) {
    double R2 = pow(L-1, 2);
    double dx = 0, dy = 0;
    double new_x = 0, new_y = 0;
    int nn_idx = 0;

    for(int i = 0; i < Ns; i++) {
        for(int j = 0; j < (int)q; j++) {

            dx = cos(-1*PI*(double)i/3. + PI);
            dy = sin(-1*PI*(double)i/3. + PI);

            new_x = spin[i].x + dx;
            new_y = spin[i].y + dy;

            if (pow(new_x, 2) + pow(new_y, 2) <= R2) {
                for(int k = 0; k < Ns; k++) {
                    if(spin[k].x == new_x && spin[k].y == new_y) {
                        spin[i].nn1[j] = &spin[k];
                        break;
                    }
                }
            }
            else {
                hex_periodic(spin, Ns, L, i, R2, dx, dy, &new_x, &new_y);
                for(int k = 0; k < Ns; k++) {
                    if(spin[k].x == new_x && spin[k].y == new_y) {
                        spin[i].nn1[j] = &spin[k];
                        break;
                    }
                }
            }
        }
    }
}

void hex_periodic(Site *spin, int Ns, int L, int i, double R2, double dx, double dy, double *new_x, double *new_y) {
    dx *= -1;
    dy *= -1;

    *new_x += dx;
    *new_y += dy;

    if (pow(*new_x, 2) + pow(*new_y, 2) <= R2) {
        hex_periodic(spin, Ns, L, i, R2, dx, dy, new_x, new_y);
    }
    else {
        *new_x -= dx;
        *new_y -= dy;
    }
}


void set_cluster_tag(Site *spin, int Ns) {
    for (int i = 0; i < Ns; i++) {
        spin[i].cluster_tag = 0;
    }
}

