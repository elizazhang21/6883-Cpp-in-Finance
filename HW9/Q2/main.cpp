//
//  main.cpp
//  Assignment9_q2
//
//  Created by Elizabeth Zhang on 3/27/18.
//  Copyright © 2018 Elizabeth Zhang. All rights reserved.
//

#include <iostream>
#include "PathDepOption03.hpp"

using namespace std;

int main() {
	double S0 = 100.0, r = 0.03, sigma=0.2;
	BSModel Model(S0, r, sigma);
	
	double T=1.0/12.0, K=100.0;
	int m = 30;
	
	long N = 30000;
	double epsilon = 0.001;
	
	ArthmAsianCall Option(T,K,m);
	Option.PriceByMC(Model, N, epsilon);
	cout << "Asian Option Price = " << Option.Price << endl;
	cout << "     Pricing Error = " << Option.PricingError << endl;
	cout << "			  delta = " << Option.delta << endl;
	cout << "			  gamma = " << Option.gamma << endl;

	return 0;
	
}

/*
 Asian Option Price = 1.43695
 Pricing Error = 0.0121071
 delta = 0.52698
 gamma = 0.115928
 Program ended with exit code: 0
 */
