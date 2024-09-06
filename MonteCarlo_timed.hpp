#ifndef MONTECARLO_VAR_HPP
#define MONTECARLO_VAR_HPP

#include <string>
#include "Measurements.hpp"
#include "Interactions.hpp"
#include "Properties.hpp"
#include "Site.hpp"
#include "Cluster.hpp"

int update_site_timed(Measurements main_measurements, Interactions main_interactions, Properties main_properties, int k, double beta, Site *spin, int Ns, int L, double D, double J);

double MC_sweep_timed(Measurements main_measurements, Interactions main_interactions, Properties main_properties, double beta, Site *spin, int Ns, int L, double D, double J);

void Metropolis_MC_Sim_timed(Interactions main_interactions, Measurements main_measurements, Properties main_properties, double beta, Site *spin, int Ns, int L, const std::string L_name, const std::string D_name, const std::string new_dir_name, double D, double J, double T_idx);

#endif