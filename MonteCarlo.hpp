#ifndef MONTECARLO_HPP
#define MONTECARLO_HPP

#include <string>
#include "Measurements.hpp"
#include "Interactions.hpp"
#include "Properties.hpp"
#include "Site.hpp"

int update_site(Measurements main_measurements, Interactions main_interactions, Properties main_properties, int k, double beta, Site *spin, int Ns, int L);

double MC_sweep(Measurements main_measurements, Interactions main_interactions, Properties main_properties, double beta, Site *spin, int Ns, int L);

void Metropolis_MC_Sim(Interactions main_interactions, Measurements main_measurements, Properties main_properties, double beta, Site *spin, int Ns, int L, const std::string L_name);

int generate_cluster(Cluster main_cluster, Properties main_properties, Site *spin, int Ns);

int flip_cluster(Cluster main_cluster, Measurements main_measurements, Interactions main_interactions, Properties main_properties, Site *spin, int Ns, int L, double beta);

double sweep_cluster(Cluster main_cluster, Measurements main_measurements, Interactions main_interactions, Properties main_properties, Site *spin, int Ns, int L, double beta, double num_sweeps);

void Wolff_MC_Sim(Cluster main_cluster, Measurements main_measurements, Interactions main_interactions, Properties main_properties, Site *spin, int Ns, int L, double beta, const std::string L_name);

#endif