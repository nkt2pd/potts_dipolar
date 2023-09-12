#ifndef SITE_HPP
#define SITE_HPP

#define N_nn1 6

class Site {
public:
    int idx;    // index 0, 1, 2, ... Ns-1
    double x, y;   // coordinates
    int Sz;     // Ising spins
    int new_Sz;
    int potts;
    int new_potts;
    int lattice_pt[2];
    int cluster_tag;
    // idx of its four neighbors
    Site *nn1[N_nn1];

};

#endif
