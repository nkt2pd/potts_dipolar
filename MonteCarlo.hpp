#ifndef MONTECARLO_HPP
#define MONTECARLO_HPP

#include <string>
#include "Measurements.hpp"

int update_site(Measurements main_measurements, Interactions main_interactions, Properties main_properties, int k, double beta, Site *spin, int Ns, int L);

double MC_sweep(Measurements main_measurements, Interactions main_interactions, Properties main_properties, double beta, Site *spin, int Ns, int L);

void Metropolis_MC_Sim(Interactions main_interactions, Measurements main_measurements, Properties main_properties, double beta, Site *spin, int Ns, int L, const std::string L_name);

#endif