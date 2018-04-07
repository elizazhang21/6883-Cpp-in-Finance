//
//  main.cpp
//  Assignment9_q3
//
//  Created by Elizabeth Zhang on 3/26/18.
//  Copyright © 2018 Elizabeth Zhang. All rights reserved.
//

#include <iostream>
#include "PathDepOption04.hpp"
#include "GmtrAsianCall.hpp"


int main()
{
	double S0=100.0, r=0.03, sigma=0.2;
	BSModel Model(S0,r,sigma);
	
	double T=1.0/12.0, K=100.0;
	int m=30;
	long N =30000;
	double epsilon=0.001;
	
	ArthmAsianCall Option(T,K,m);
	GmtrAsianCall CVOption(T,K,m);
	
	Option.PriceByVarRedMC(Model, N, CVOption, epsilon);
	cout << "Arithmetic call price = " << Option.Price << endl
	<< "Error = " << Option.PricingError<<endl
	<< "delta = " << Option.delta << endl << endl;
	
	Option.PriceByMC(Model, N, epsilon);
	cout << "Price by direct MC = " << Option.Price << endl
	<<"Error = " << Option.PricingError << endl
	<< "delta = " << Option.delta << endl;
 
	return 0;
}


/*
 Arithmetic call price = 1.42606
 Error = 0.000138811
 delta = 0.52012
 
 Price by direct MC = 1.41515
 Error = 0.0119681
 delta = 0.524226
 Program ended with exit code: 0
*/
