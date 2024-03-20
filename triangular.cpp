#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <list>
#include <fstream>
#include <random>
#include <chrono>
#include <string>
#include "Site.hpp" 
#define PI 3.1415926535897932384

using namespace std;

// Oct 4 2013 !!!
// version non-C3-symmetric

const int L = 60;

double J1 = 1;
double Dp = 0.15;

const int Ns = L*L;

Site spin[Ns];

const int N_potts = 6;
double V_clock[N_potts][N_potts];

int idx_m[N_potts][N_potts];

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

double rand1() {
    
    std::uniform_real_distribution<double> dis(0.0, 1.0);
    double rand1 = dis(rng);
    
    return rand1;
}

void init_basis(void) {

    for(int m=0; m<N_potts; m++)
        for(int n=0; n<N_potts; n++) {
            
            V_clock[m][n] = cos((m - n)*2.*PI/((double) N_potts));
        }
    
    idx_m[0][0] = 3;
    idx_m[0][1] = 2;
    idx_m[0][2] = 1;
    idx_m[0][3] = 0;
    idx_m[0][4] = 5;
    idx_m[0][5] = 4;
    
    idx_m[3][0] = 3;
    idx_m[3][1] = 2;
    idx_m[3][2] = 1;
    idx_m[3][3] = 0;
    idx_m[3][4] = 5;
    idx_m[3][5] = 4;
    
    idx_m[1][0] = 5;
    idx_m[1][1] = 4;
    idx_m[1][2] = 3;
    idx_m[1][3] = 2;
    idx_m[1][4] = 1;
    idx_m[1][5] = 0;
    
    idx_m[4][0] = 5;
    idx_m[4][1] = 4;
    idx_m[4][2] = 3;
    idx_m[4][3] = 2;
    idx_m[4][4] = 1;
    idx_m[4][5] = 0;
    
    idx_m[2][0] = 1;
    idx_m[2][1] = 0;
    idx_m[2][2] = 5;
    idx_m[2][3] = 4;
    idx_m[2][4] = 3;
    idx_m[2][5] = 2;
    
    idx_m[5][0] = 1;
    idx_m[5][1] = 0;
    idx_m[5][2] = 5;
    idx_m[5][3] = 4;
    idx_m[5][4] = 3;
    idx_m[5][5] = 2;

}

double pb[N_potts][N_potts][N_potts];

void set_pb(double beta) {
    
    for(int q=0; q<N_potts; q++)
        for(int m=0; m<N_potts; m++)
        for(int n=0; n<N_potts; n++) {
    
            double f1 = cos((m - q)*2.*PI/((double) N_potts));
            double f2 = cos((n - q)*2.*PI/((double) N_potts));
            
            pb[q][m][n] = 1. - exp(-2.*beta*J1*f1*f2);
            
        }
}

inline int index(int x, int y) {
    return x*L+y;
}

int mod(int x, int m) {
	if (x>=0 && x<m)
		return x;
	else if (x<0)
		return m-1-mod(-1-x,m);
	else
		return x%m;
}

void set_coordinates(void) {
    
    for(int x=0; x<L; x++)
    for(int y=0; y<L; y++) {
        
        int idx = index(x, y);
        spin[idx].lattice_pt[0] = x;
        spin[idx].lattice_pt[1] = y;
        spin[idx].idx = idx;
        
        spin[idx].x = x + 0.5*y;
        spin[idx].y = 0.5*sqrt(3.)*y;
        
    }
}

void set_nn(void) {
    
    int idx;
    
	for(int i=0; i<Ns; i++) {
		int x = spin[i].lattice_pt[0];
		int y = spin[i].lattice_pt[1];
        
        idx = index(mod(x+1, L), y);
        spin[i].nn1[0] = &spin[idx];
        
        idx = index(x, mod(y+1, L));
        spin[i].nn1[1] = &spin[idx];
        
        idx = index(mod(x-1, L), mod(y+1, L));
        spin[i].nn1[2] = &spin[idx];
        
        idx = index(mod(x-1, L), y);
        spin[i].nn1[3] = &spin[idx];
        
        idx = index(x, mod(y-1, L));
        spin[i].nn1[4] = &spin[idx];
        
        idx = index(mod(x+1, L), mod(y-1, L));
        spin[i].nn1[5] = &spin[idx];

    }
}

double Vd[L][L];
void compute_Vd(int N_max) {

    double dr0[2], dr[2];
    
    for(int x=0; x<L; x++)
    for(int y=0; y<L; y++) {
        
        if(x == 0 && y == 0) Vd[x][y] = 0;
        else {
        
            Vd[x][y] = 0;
            
            dr0[0] = x + 0.5*y;
            dr0[1] = 0.5*sqrt(3.)*y;
            
            for(int m=-N_max; m<=N_max; m++)
            for(int n=-N_max; n<=N_max; n++) {
                
                dr[0] = dr0[0] + L*(m + 0.5*n);
                dr[1] = dr0[1] + L*(0.5*sqrt(3.)*n);
                
                double r2 = pow(dr[0], 2) + pow(dr[1], 2);
                
                Vd[x][y] += 1./pow(r2, 1.5);
                
                
            }
        }
    }
}

inline double Ud(int i, int j) {
    int dx = spin[j].lattice_pt[0] - spin[i].lattice_pt[0];
    int dy = spin[j].lattice_pt[1] - spin[i].lattice_pt[1];
    
    return 0.5*(Vd[mod(dx, L)][mod(dy, L)] + Vd[mod(-dx, L)][mod(-dy, L)]);
}

double E_clock(void) {
    
    double sum = 0;
    for(int i=0; i<Ns; i++) {
        
        for(int j=0; j<6; j++) {
                        
            sum += V_clock[spin[i].potts][spin[i].nn1[j]->potts];
            
        }
    }
    
    return -0.5*J1*sum;
}

double E_dip(void) {
    
    double sum = 0;
    for(int i=0; i<Ns; i++) {
    
        for(int j=0; j<Ns; j++) sum += Ud(i, j)*spin[i].Sz*spin[j].Sz;
    }
    
    return 0.5*Dp*sum;
}

inline double E_tot(void) {
    
    return E_clock() + E_dip();
}

double Ed_curr;
int spin_flip(int t, double beta) {
	
    double delta_E;
    
    int p_new = (int) (rand1()*N_potts);
    int sz_new = (p_new % 2 == 0) ? 1 : -1;
    
    double dn = 0;
    for(int j=0; j<6; j++) {
        
        dn += -J1*(V_clock[p_new][spin[t].nn1[j]->potts] - V_clock[spin[t].potts][spin[t].nn1[j]->potts]);
        
    }
	
	double dv = 0;
    if(sz_new == spin[t].Sz) dv = 0;
    else {
        for(int j=0; j<Ns; j++) {
            
            dv += (sz_new - spin[t].Sz)*spin[j].Sz*Ud(t, j);
        }
    }
    
	delta_E = J1*dn + Dp*dv;
	
	/*
    spin[t].potts = p_new;
    spin[t].sz = sz_new;
    double E_new = E_tot();
    printf("%10.8f\t %10.8f\t\t %10.8f\t %10.8f\n", delta_E, E_new - E_curr, J1*dn, Dp*dv);
    return 1;
    */
	
	double r = rand1();
	if(r<exp(-beta*delta_E)) {
        
        spin[t].potts = p_new;
        spin[t].Sz = sz_new;
        
		Ed_curr += Dp*dv;
        
		return 1;
        
	} else {
		return 0;
	}
	
}

double sweep(double beta) {
	int hits = 0;
	for(int i=0; i<Ns; i++) {
		hits += spin_flip(i, beta);
	}
	return ((double) hits)/((double) Ns);
}

list<int> cluster;
int _qr;

int generate_cluster(void) {
 
    cluster.clear();
    
    _qr = (int) (rand1()*N_potts);
    int s0 = (int) (rand1()*Ns);
    
    //std::cout << "_qr = " << _qr << endl;
    
    cluster.push_back(s0);
    spin[s0].cluster_tag = 1;
    
    list<int> lst_1;
    list<int> lst_2;

    lst_1.push_back(s0);
    list<int>::const_iterator m;

    //std::cout << spin[s0].potts << endl;
    
    int i, j;
    
    while(lst_1.size() > 0) {
        
        lst_2.clear();

        for(m = lst_1.begin(); m != lst_1.end(); ++m) {
            
            i = (*m);
            for(int k=0; k<6; k++) {
                j = spin[i].nn1[k]->idx;
                
                if( (spin[j].cluster_tag == 0) && (rand1() < pb[_qr][spin[i].potts][spin[j].potts]) ) {
                    
                    cluster.push_back(j);
                    spin[j].cluster_tag = 1;
                    
                    //std::cout << spin[j].potts << endl;
                    
                    lst_2.push_back(j);
                }
            }
            
        }
        
        lst_1 = lst_2;
    }
    
    return cluster.size();
}

int flip_cluster(double beta) {
    
    list<int>::const_iterator m;

    for(m = cluster.begin(); m != cluster.end(); ++m) {
        
        int i = (*m);
        
        spin[i].new_potts = idx_m[_qr][spin[i].potts];
        spin[i].new_Sz = (spin[i].new_potts % 2 == 0) ? 1 : -1;
    }
    
    double sum1 = 0;
    double sum2 = 0;
    
    for(m = cluster.begin(); m != cluster.end(); ++m) {

        int i = (*m);
        
        for(int j=0; j<Ns; j++) {
            
            if(spin[j].cluster_tag == 0) {
                
                sum1 += (spin[i].new_Sz - spin[i].Sz)*spin[j].Sz*Ud(i, j);
            
            } else {
                
                sum2 += (spin[i].new_Sz*spin[j].new_Sz - spin[i].Sz*spin[j].Sz)*Ud(i, j);
                
            }
        }
    }
    
    double delta_E = Dp*(sum1 + 0.5*sum2);

    /*
    for(m = cluster.begin(); m != cluster.end(); ++m) {
        int i = (*m);
        
        spin[i].potts = spin[i].new_potts;
        spin[i].sz = spin[i].new_sz;
        
        spin[i].cluster_tag = 0;
    }
    double Ed_new = E_dip();
    std::cout << (Ed_new - Ed_curr) << "\t : \t" << delta_E << endl;
    */
    
    
    double r = rand1();
	if(r<exp(-beta*delta_E)) {
        
        for(m = cluster.begin(); m != cluster.end(); ++m) {
            int i = (*m);
            
            spin[i].potts = spin[i].new_potts;
            spin[i].Sz = spin[i].new_Sz;
            
            spin[i].cluster_tag = 0;
        }
        
        Ed_curr += delta_E;
        
		return 1;
        
	} else {
        
        for(m = cluster.begin(); m != cluster.end(); ++m) {
            int i = (*m);
            
            spin[i].cluster_tag = 0;
        }
        
		return 0;
	}

}

double avg_size;
double avg_flip;

double sweep_cluster(double beta, int nx) {
 
    int hits = 0;
    int s1 = 0, s2 = 0;
    
    for(int r=0; r<nx; r++) {
        int cls = generate_cluster();
        
        s1 += cls;
        
        int hs = flip_cluster(beta);
        if(hs == 1) {
            hits++;
            s2 += cls;
        }
    }
    
    avg_size = ((double) s1)/((double) nx);
    avg_flip = (hits == 0) ? 0 : ((double) s2)/((double) hits);
    
    return ((double) hits)/((double) nx);
}

void init_lattice(void) {
	set_coordinates();
    set_nn();
    
    for(int i=0; i<Ns; i++) spin[i].cluster_tag = 0;
}

void init_uniform(void) {
    for(int i=0; i<Ns; i++) {
        spin[i].potts = 0;
        spin[i].Sz = 1;
    }
    Ed_curr = E_dip();
}

void init_random(void) {
    for(int i=0; i<Ns; i++) {
        spin[i].potts = (int) (rand1()*6);
        
        spin[i].Sz = (spin[i].potts % 2 == 0) ? 1 : -1;
    }
    Ed_curr = E_dip();

}

void init_stripe(int h) {
    for(int x=0; x<L; x++) {
        int r = x % h;
        int p = (int) ((x-r)/h);
        
        for(int y=0; y<L; y++) {
            
            int i = index(x, y);
            //spin[i].potts = mofd(p, N_potts);
            spin[i].potts = mod(p, 2);
            
            spin[i].Sz = (spin[i].potts % 2 == 0) ? 1 : -1;
            
        }
    }
    
    Ed_curr = E_dip();
    
}

double fb[2];
int Nb_x[3];

double compute_fb(void) {
    
    for(int k=0; k<3; k++) Nb_x[k] = 0;
    
    for(int i=0; i<Ns; i++) {
        
        for(int k=0; k<3; k++) {
            
            if(spin[i].Sz != spin[i].nn1[2*k]->Sz) Nb_x[k]++;
            
        }
    }
    
    int sum = Nb_x[0] + Nb_x[1] + Nb_x[2];
    
    fb[0] = ((double) (Nb_x[1] + Nb_x[2] - 2*Nb_x[0]))/((double) sum)/sqrt(6.);
    fb[1] = ((double) (Nb_x[1] - Nb_x[2]))/((double) sum)/sqrt(2.);
 
    return ((double) sum)/((double) 3*Ns);
}

double r_p[2];
double compute_potts_order(void) {
    
    double sum1 = 0, sum2 = 0;
    for(int i=0; i<Ns; i++) {
        
        double phase = 2.*PI*((double) spin[i].potts)/((double) N_potts);
        
        sum1 += cos(phase);
        sum2 += sin(phase);
    }
    
    r_p[0] = sum1/((double) Ns);
    r_p[1] = sum2/((double) Ns);
    
    return sqrt(pow(r_p[0], 2) + pow(r_p[1], 2));
    
}

double compute_ising_order(void) {
    int sum = 0;
    
    for(int i=0; i<Ns; i++) {
        
        sum += spin[i].Sz;
    }
    
    return ((double) sum)/((double) Ns);
}

void plot_spin(void) {
    
    // double sv = 0.35;
    
    FILE *fp = fopen("p.dat","w");
    FILE *fp1 = fopen("sp.dat", "w");
    FILE *fp2 = fopen("sm.dat", "w");

    for(int i=0; i<Ns; i++) {
        int px = spin[i].potts;
        fprintf(fp, "%f\t %f\t %f\t %f\n", spin[i].x, spin[i].y, cos(2.*PI*px/N_potts), sin(2.*PI*px/N_potts));
        
        if(spin[i].Sz == 1) fprintf(fp1, "%f\t %f\n", spin[i].x, spin[i].y);
        else fprintf(fp2, "%f\t %f\n", spin[i].x, spin[i].y);
    }
    fclose(fp);
    
    fclose(fp1);
    fclose(fp2);
}

void test(void) {
    
    for(int p1 = 0; p1<N_potts; p1++)
    for(int p2 = 0; p2 < N_potts; p2++) {
            
    
        std::cout << "(" << p1 << ", " << p2 << "):\t" << "\t " << V_clock[p1][p2] << endl;
    }
    
    FILE *fp = fopen("v.dat", "w");
    for(int x=0; x<L; x++) {
        int i = index(0, 0);
        int j = index(x, 0);
        fprintf(fp, "%d\t %12.10f\n", x, Ud(i, j));
    }
    fclose(fp);
    
    /*
    init_random();
    spin_flip((int) (rand1()*Ns), 1./10000.);
    */
    
    exit(1);
}

void test2(void) {
    
    FILE *fp = fopen("spin.dat", "r");
    
    for(int i=0; i<Ns; i++) {
        int p;
        fscanf(fp, "%d\n", &p);
        
        spin[i].potts = p;
        spin[i].Sz = (p % 2 == 0) ? 1 : -1;
    }
    
    fclose(fp);
    
    fp = fopen("pz.dat", "w");
    for(int i=0; i<Ns; i++) fprintf(fp, "%f\t %f\t %d\n", spin[i].x, spin[i].y, spin[i].potts);
    fclose(fp);

    fp = fopen("sz.dat", "w");
    for(int i=0; i<Ns; i++) fprintf(fp, "%f\t %f\t %d\n", spin[i].x, spin[i].y, spin[i].Sz);
    fclose(fp);

    exit(1);
}

void test3(void) {
    
    // set_pb(1./0.1);
    //init_random();
    init_stripe(3);
    
    ofstream stripe;
    stripe.open("chernstripe.dat");

    for(int i = 0; i < Ns; i++) {
        stripe << spin[i].x << ", " << spin[i].y << ", " << spin[i].Sz << endl;
    }

    stripe.close();

    // int cls = generate_cluster();
    
    // std::cout << "cluster size = " << cls << endl;
    
    // int hs = flip_cluster(1./2);
    
    exit(1);
}

void compare_energy(void) {
    
    FILE *fp;
    
    /*
    //init_uniform();
    init_stripe(66);
    fp = fopen("pz.dat", "w");
    for(int i=0; i<Ns; i++) fprintf(fp, "%f\t %f\t %d\n", spin[i].position[0], spin[i].position[1], spin[i].potts);
    fclose(fp);
    
    fp = fopen("sz.dat", "w");
    for(int i=0; i<Ns; i++) fprintf(fp, "%f\t %f\t %d\n", spin[i].position[0], spin[i].position[1], spin[i].sz);
    fclose(fp);
    
    std::cout << "E (uniform) = " << E_curr << "\t E_J1 = " << E_j << "\t E_d = " << E_d << endl;

    exit(1);
    */
    
    
    fp = fopen("eg.dat", "w");

    for(int h=1; h<66; h++) {
        
        //std::cout << "h = " << h << endl;
        
        init_stripe(h);
        
        double E_j = E_clock();
        double E_d = Ed_curr;
        
        fprintf(fp, "%d\t %20.18f\t %20.18f\t %20.18f\n", h, E_j + E_d, E_j, E_d);
    }
    
    fclose(fp);
    
    //exit(1);
}

int main(int argc, char* argv[]) {
    std::cout << "test" << std::endl;
    init_lattice();

    // double _T0 = argc > 1 ? atof(argv[1]) : 1;
    double _T0 = 0.5;
    std::cout << "T = " << _T0 << endl;
    
    // int rand_s0 = argc > 2 ? atoi(argv[2]) : 0;

    int h0 = 5;
    
    std::cout << "h0 = " << h0 << endl;
    
    std::cout << "L = " << L << endl;
    
    // FILE *fp;
    
    init_basis();
	init_lattice();

    std::cout << "Computing Vd" << std::endl;
    compute_Vd(200);
    std::cout << "Done Computing Vd" << std::endl;

    //test();
    //test2();
    //test3();
    
    compare_energy();
    
    double E_j, E_d;

    init_uniform();
    E_j = E_clock();
    E_d = Ed_curr;
    std::cout << "E (uniform) = " << E_j + E_d << "\t E_J1 = " << E_j << "\t E_d = " << E_d << endl;
    
    // init_random();

    std::string file_name = "./smoothed/L=60/DJ0.150000/T=init_config.dat";

    std::ifstream config(file_name);

    if (config.fail()) {
        throw std::runtime_error("Failed to open config");
    }

    int iter = 0;
    std::string buffer = "";

    while(!config.eof()) { //feed in potts and ising of each config
        config >> buffer;
        if(config.eof()) {
            break;
        }

        config >> buffer;

        config >> buffer;
        buffer.erase(buffer.size()-1);
        spin[iter].potts = std::stoi(buffer);

        config >> buffer;
        spin[iter].Sz = std::stoi(buffer);

        iter++;
    }

    config.close();

    E_j = E_clock();
    E_d = Ed_curr;
    std::cout << "E (random) = " << E_j + E_d << "\t E_J1 = " << E_j << "\t E_d = " << E_d << endl;

    
    int ntherm = 100;
    int nth_sweep = 2;
    int nth_cls = 2;
	int nth_save = 100;
	
	long int npts = 500;
	int nsweep = 10;
    int nsweep_cls = 2;
	
	int n_save = 100;
	double hits = 0;
    double hits_cls = 0;
    
    init_stripe(h0);
    E_j = E_clock();
    E_d = Ed_curr;
    std::cout << "E (stripe-" << h0 << ") = " << E_j + E_d << "\t E_J1 = " << E_j << "\t E_d = " << E_d << endl;
    
    double del_T = 0.05;

    for(double _T = _T0; _T < 2.5; _T += del_T) {
		
	    double beta = 1./_T;
		std::cout << "beta = " << beta << ",  thermalizing ..." << endl;
		
        set_pb(beta);
        
		hits = 0;
        hits_cls = 0;
		for(int n=0; n < ntherm; n++) {
			
			if(n % nth_save == 0) {

				std::cout << "n = " << n << std::endl;
			}
			
            for(int r=0; r<nth_sweep; r++) hits += sweep(beta);
			hits_cls += sweep_cluster(beta, nth_cls);
		}
		std::cout << "average spin hits: " << hits/((double) ntherm*nth_sweep) << endl;
        std::cout << "average cls  hits: " << hits_cls/((double) ntherm) << endl;
		
		// ------------------ take data: ----------------------------
		std::cout << "gathering data ..." << endl;
		
		double E1 = 0, E2 = 0;
        double E1_J1 = 0, E1_Dp = 0;
        
        double ld = 0;
        double F1 = 0, F2 = 0, F4 = 0;
        double P1 = 0, P2 = 0, P4 = 0;
        double S1 = 0, S2 = 0, S4 = 0;
        
        double p_spin = 0;
        double p_cls = 0;
        double p_size = 0;
        double p_flip = 0;

        // clock_t t_start = clock();
        // clock_t t_now;

        
		for(long int n=0; n < npts; n++) {
			
			hits = 0;
			for(int m=0; m<nsweep; m++) hits += sweep(beta);
            p_spin = (n*p_spin + hits/((double) nsweep))/(n + 1.);

            hits_cls = sweep_cluster(beta, nsweep_cls);
            p_cls = (n*p_cls + hits_cls)/(n + 1.);
            
            p_size = (n*p_size + avg_size)/(n + 1.);
            p_flip = (n*p_flip + avg_flip)/(n + 1.);
			
            E_j = E_clock();
            E_d = Ed_curr;
			double e = E_j + E_d; // E_tot();
            
			E1 = (n*E1 + e)/(n + 1.);
			E2 = (n*E2 + e*e)/(n + 1.);
            
            E1_J1 = (n*E1_J1 + E_j)/(n + 1.);
            E1_Dp = (n*E1_Dp + E_d)/(n + 1.);
            
            double lx = compute_fb();
            
            ld = (n*ld + lx)/(n + 1.);
            
            double fm2 = pow(fb[0], 2) + pow(fb[1], 2);
            
            F1 = (n*F1 + sqrt(fm2))/(n + 1.);
            F2 = (n*F2 + fm2)/(n + 1.);
            F4 = (n*F4 + pow(fm2, 2))/(n + 1.);
            
            double px = compute_potts_order();
            
            P1 = (n*P1 + px)/(n + 1.);
            P2 = (n*P2 + pow(px, 2))/(n + 1.);
            P4 = (n*P4 + pow(px, 4))/(n + 1.);
            
            double sx = compute_ising_order();
            
            S1 = (n*S1 + fabs(sx))/(n + 1.);
            S2 = (n*S2 + pow(sx, 2))/(n + 1.);
            S4 = (n*S4 + pow(sx, 4))/(n + 1.);
            
			if(n % n_save == 0) {
				
				std::cout << "n = " << n << std::endl;

 			}
			
		}
        std::ofstream energy;
        energy.open("./cherncompare_sim/L=60/DJ0.150000/energy.dat", std::fstream::app);
        std::ofstream energy_parts;
        energy_parts.open("./cherncompare_sim/L=60/DJ0.150000/energyParts.dat", std::fstream::app);
        std::ofstream heat;
        heat.open("./cherncompare_sim/L=60/DJ0.150000/heat.dat", std::fstream::app);
        std::ofstream Potts_m;
        Potts_m.open("./cherncompare_sim/L=60/DJ0.150000/Potts_m.dat", std::fstream::app);
        std::ofstream Ising_m;
        Ising_m.open("./cherncompare_sim/L=60/DJ0.150000/Ising_m.dat", std::fstream::app);
        std::ofstream susceptibility;
        susceptibility.open("./cherncompare_sim/L=60/DJ0.150000/susceptibility.dat", std::fstream::app);
        std::ofstream binder4;
        binder4.open("./cherncompare_sim/L=60/DJ0.150000/binder4.dat", std::fstream::app);
        std::ofstream fb;
        fb.open("./cherncompare_sim/L=60/DJ0.150000/fb.dat", std::fstream::app);

        energy << 1./beta << ", " << E1/((double) Ns) << std::endl;
        energy_parts << 1./beta << ", " << E_j/((double) Ns) << ", " << E_d/((double) Ns) << std::endl;
        heat << 1./beta << ", " << pow(beta, 2) * (E2 - E1*E1) / ((double) Ns) << std::endl;
        Potts_m << 1./beta << ", " << P1 << std::endl;
        Ising_m << 1./beta << ", " << S1 << std::endl;
        susceptibility << 1./beta << ", " << beta*(P2 - P1*P1) << std::endl;
        binder4 << 1./beta << ", " << 1. - (P4/(3 * pow(P2, 2))) << std::endl;
        fb << 1./beta << ", " << F1 << ", " << F2 << ", " << F4 << std::endl;

        Potts_m.close();
        Ising_m.close();
        susceptibility.close();
        binder4.close();
        energy.close();
        energy_parts.close();
        heat.close();
        fb.close();

        std::ofstream config;
        config.open("./cherncompare_sim/L=60/DJ0.150000/T=" + std::to_string(1./beta) + "_config.dat", std::fstream::app);

        for(int i = 0; i < Ns; i++) {
            config << spin[i].x << ", " << spin[i].y << ", " << spin[i].potts << ", " << spin[i].Sz << std::endl;
        }

        config.close();
		
        if(_T <= 0.1) {
            del_T = 0.01;
        }
        
	}
}
