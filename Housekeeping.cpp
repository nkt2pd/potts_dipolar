#include "Housekeeping.hpp"
#include <cmath>
#include <string>
#include <fstream>
#include <vector>

void clear_files(const std::string L_name) {
    std::ofstream clear1, clear2, clear3, clear4, clear5, clear6, clear7;
    
    clear1.open(L_name + "_energy.dat", std::fstream::trunc);
    clear2.open(L_name + "_heat.dat", std::fstream::trunc);
    clear3.open(L_name + "Potts_m.dat", std::fstream::trunc);
    clear4.open(L_name + "Ising_m.dat", std::fstream::trunc);
    clear5.open(L_name + "_susceptibility.dat", std::fstream::trunc);
    clear6.open(L_name + "_binder4.dat", std::fstream::trunc);
    clear7.open(L_name + "_time.dat", std::fstream::trunc);

    clear1.close();
    clear2.close();
    clear3.close();
    clear4.close();
    clear5.close();
    clear6.close();
    clear7.close();

}

void print(const std::string L_name, double E1, double E2, double E1_j, double E1_d, double PM1, double PM2, double PM4, 
           double IM1, double IM2, double IM4, double beta, int Ns, int t_diff) {

        std::ofstream energy;
        energy.open(L_name + "_energy.dat", std::fstream::app);
        std::ofstream energy_parts;
        energy_parts.open(L_name + "_energyParts.dat", std::fstream::app);
        std::ofstream heat;
        heat.open(L_name + "_heat.dat", std::fstream::app);
        std::ofstream Potts_m;
        Potts_m.open(L_name + "Potts_m.dat", std::fstream::app);
        std::ofstream Ising_m;
        Ising_m.open(L_name + "Ising_m.dat", std::fstream::app);
        std::ofstream susceptibility;
        susceptibility.open(L_name + "_susceptibility.dat", std::fstream::app);
        std::ofstream binder4;
        binder4.open(L_name + "_binder4.dat", std::fstream::app);

        energy << 1./beta << ", " << E1/((double) Ns) << std::endl;
        energy_parts << 1./beta << ", " << E1_j/((double) Ns) << ", " << E1_d/((double) Ns) << std::endl;
        heat << 1./beta << ", " << pow(beta, 2) * (E2 - E1*E1) / ((double) Ns) << std::endl;
        Potts_m << 1./beta << ", " << PM1 << std::endl;
        Ising_m << 1./beta << ", " << IM1 << std::endl;
        susceptibility << 1./beta << ", " << beta*(PM2 - PM1*PM1) << std::endl;
        binder4 << 1./beta << ", " << 1. - (PM4/(3 * pow(PM2, 2))) << std::endl;

        Potts_m.close();
        Ising_m.close();
        susceptibility.close();
        binder4.close();
        energy.close();
        energy_parts.close();
        heat.close();

        std::ofstream time;
        time.open(L_name + "_time.dat", std::fstream::app);

        time << 1./beta << ", " << t_diff << std::endl;

        time.close();

}

int mod(int x, int m) {
	if (x>=0 && x<m)
		return x;
	else if (x<0)
		return m-1-mod(-1-x,m);
	else
		return x%m;
}