#ifndef SETUP_LATTICE_HPP
#define SETUP_LATTICE_HPP

#include "Site.hpp"
//#include "Interactions.hpp"
class Interactions;
#include "Measurements.hpp"

void init_uniform(Measurements main_measurements, Interactions main_interactions, Site *spin, int Ns, int L);

void init_random(Measurements main_measurements, Interactions main_interactions, Site *spin, int Ns, int L);

void init_stripe(Measurements main_measurements, Interactions main_interactions, Site *spin, int Ns, int L, int h);

inline int index(int x, int y, int L);

void set_coordinates(Site *spin, int Ns, int L);

void set_hex_coordinates(Site *spin, int Ns, int L);

void set_nn(Site *spin, int Ns, int L);

void set_hex_nn(Site *spin, int Ns, int L);

void hex_periodic(Site *spin, int Ns, int L, int i, double R2, double dx, double dy, double *nn_x, double *nn_y, int flip);

void set_cluster_tag(Site *spin, int Ns);



#endif