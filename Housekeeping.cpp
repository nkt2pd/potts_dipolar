#include "Housekeeping.hpp"
#include <string>
#include <fstream>

void clear_files(const std::string L_name) {
    std::ofstream clear1, clear2, clear3, clear4, clear5;
    
    clear1.open(L_name + "_energy.dat", std::fstream::trunc);
    clear2.open(L_name + "_heat.dat", std::fstream::trunc);
    clear3.open(L_name + "_m.dat", std::fstream::trunc);
    clear4.open(L_name + "_susceptibility.dat", std::fstream::trunc);
    clear5.open(L_name + "_binder4.dat", std::fstream::trunc);

    clear1.close();
    clear2.close();
    clear3.close();
    clear4.close();
    clear5.close();

}

void print(const std::string L_name, double E1, double E2, double M1, double M2, double M4, double beta, int Ns) {
    
        std::ofstream energy;
        energy.open(L_name + "_energy.dat", std::fstream::app);
        std::ofstream heat;
        heat.open(L_name + "_heat.dat", std::fstream::app);
        std::ofstream m;
        m.open(L_name + "_m.dat", std::fstream::app);
        std::ofstream susceptibility;
        susceptibility.open(L_name + "_susceptibility.dat", std::fstream::app);
        std::ofstream binder4;
        binder4.open(L_name + "_binder4.dat", std::fstream::app);

        energy << 1./beta << ", " << E1/((double) Ns) << std::endl;
        heat << 1./beta << ", " << pow(beta, 2) * (E2 - E1*E1) / ((double) Ns) << std::endl;
        m << 1./beta << ", " << M1 << std::endl;
        susceptibility << 1./beta << ", " << beta*(M2 - M1*M1) << std::endl;
        binder4 << 1./beta << ", " << 1. - (M4/(3 * pow(M2, 2))) << std::endl;

        m.close();
        susceptibility.close();
        binder4.close();
        energy.close();
        heat.close();

}