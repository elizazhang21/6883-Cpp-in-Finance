//
//  main.cpp
//  HW7
//
//  Created by Elizabeth Zhang on 3/2/18.
//  Copyright © 2018 Elizabeth Zhang. All rights reserved.
//

#include <iostream>
#include "BinModel02.hpp"
#include "Option09.hpp"
#include "BSModel.hpp"
using namespace std;

int main()
{
	double S0=106.0;
	double r=0.058;
	double sigma=0.46;
	double T=(double)9/12;
	double K=100.0;
	int N=8;
	
	cout << std::fixed << setprecision(5); // Set results' precision level.
	
	cout << "S0 =    " << S0 << endl;
	cout << "r  =    " << r << endl;
	cout << "sigma = " << sigma << endl;
	cout << "T =     " << T << endl;
	cout << "K =     " << K << endl;
	cout << "N =     " << N << endl;
	cout << endl;

	
	BSModel Model(S0, r, sigma); // Create a BS model.
	double h=T/N;
	BinModel ApproxModel=Model.ApproxBinModel(h);
	
	cout << "U =     " << ApproxModel.GetU() << endl;
	cout << "D =     " << ApproxModel.GetD() << endl;
	cout << "R =     " << ApproxModel.GetR() << endl;
	
	Call Option(N, K);
	BinLattice<double> PriceTree; // PriceTree is made of doubles.
	BinLattice<bool> StoppingTree; // Stopping Tree is made of bool values.
	
	Option.PriceBySnell(ApproxModel,PriceTree,StoppingTree);
	cout << "American call option price = "
	<< PriceTree.GetNode(0,0)
	<< endl << endl;
	
	return 0;
}


/*
 S0 =    106.00000
 r  =    0.05800
 sigma = 0.46000
 T =     0.75000
 K =     100.00000
 N =     8
 
 U =     0.14610
 D =     -0.13526
 R =     0.00545
 American call option price = 21.33399
 
 Program ended with exit code: 0
*/
