//
//  main.cpp
//  HW6
//
//  Created by Elizabeth Zhang on 2/28/18.
//  Copyright © 2018 Elizabeth Zhang. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include "BinModel02.hpp"
#include "BinLattice02.hpp"
#include "Option09.hpp"
#include <fstream>
using namespace std;

int main()
{
	BinModel Model;

	if (Model.GetInputData()==1) return 1;
	
	ofstream fout;
	fout.open("Results_Eli_Zhang.txt");
	
	Call Option1;
	Option1.GetInputData();
	BinLattice<double> PriceTree1;
	BinLattice<double> XTree1;
	BinLattice<double> YTree1;
	
	fout << "S0 = " << Model.GetS0()<<endl
	<< "U = " << Model.GetU() << endl
	<< "D = " << Model.GetD() << endl
	<< "R = " << Model.GetR() << endl;
	
	fout <<"N = " << Option1.GetN() <<endl
	<< "K = " << Option1.GetK() << endl;

	fout << "European call prices by PriceByCRR: " << Option1.PriceByCRR(Model) << endl << endl;
	fout << "European call prices by PriceByCRRHW6: " << Option1.PriceByCRRHW6(Model, PriceTree1, XTree1, YTree1) << endl << endl;
	// PriceTree1.Display(cout);
	
	fout << "Stock positions in replicating strategy:" << endl << endl;
	XTree1.Display(fout);
	fout << "Money market account positions in replicating strategy:" << endl << endl;
	YTree1.Display(fout);
	

	Put Option2;
	Option2.GetInputData();
	BinLattice<double> PriceTree2;
	BinLattice<double> XTree2;
	BinLattice<double> YTree2;
	fout <<"N = " << Option2.GetN() <<endl
	<< "K = " << Option2.GetK() << endl;
	fout << "European put prices by PriceByCRR: " << Option2.PriceByCRR(Model) << endl << endl;
	fout << "European put prices by PriceByCRRHW6: " << Option2.PriceByCRRHW6(Model, PriceTree2, XTree2, YTree2) << endl << endl;
	// PriceTree2.Display(fout);
	fout << "Stock positions in replicating strategy:" << endl << endl;
	XTree2.Display(fout);
	fout << "Money market account positions in replicating strategy:" << endl << endl;
	YTree2.Display(fout);

	fout.close();
	cout << "Results has been presented in the txt file: Results_Eli_Zhang.txt" << endl;

	return 0;
}


/*
 Enter S0: 106
 Enter U:  0.15125
 Enter D:  -0.13138
 Enter R:  0.00545
 
 Enter call option data:
 Enter steps to expiry N:8
 Enter strike price K:	100
 
 Enter put option data:
 Enter steps to expiry N: 8
 Enter strike price K:	 100
 
 Results has been presented in the txt file: Results_Eli_Zhang.txt
 Program ended with exit code: 0
 */
