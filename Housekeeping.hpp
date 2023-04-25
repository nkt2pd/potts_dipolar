#ifndef HOUSEKEEPING_HPP
#define HOUSEKEEPING_HPP

#include <string>

void clear_files(const std::string L_name);

void print(const std::string L_name, double E1, double E2, double M1, double M2, double M4, double beta, int Ns, int t_diff);

int mod(int x, int m);

#endif