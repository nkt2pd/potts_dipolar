#ifndef SITE_HPP
#define SITE_HPP

#define N_nn1 6

class Site {
public:
    int idx;    // index 0, 1, 2, ... Ns-1
    int x, y;   // coordinates
    int Sz;     // Ising spins
    int potts;
    int Ns;
    int L;
    int lattice_pt[2];
    int cluster_tag;
    // idx of its four neighbors
    Site *nn1[N_nn1];

};

#endif
