#ifndef HOUSEKEEPING_HPP
#define HOUSEKEEPING_HPP

#include <string>

void clear_files(const std::string L_name);

void print(const std::string L_name, const std::string D_name, const std::string T_val, double E1, double E2, 
           double E1_j, double E1_d, double PM1, double PM2, double PM4, double IM1, double IM2, double IM4, 
           double F1, double F2, double F4, double beta, int Ns, int t_diff);

int mod(int x, int m);

#endif