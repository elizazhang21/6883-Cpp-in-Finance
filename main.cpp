//
//  main.cpp
//  Assignment9_q1
//
//  Created by Elizabeth Zhang on 3/26/18.
//  Copyright © 2018 Elizabeth Zhang. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include "PathDepOption01.hpp"

int main()
{
	cout << setiosflags(ios::fixed) << setprecision(4);
	double S0 = 106.0, r = 0.058, sigma = 0.46;
	BSModel Model(S0, r, sigma);
	
	double T = 9.0/12.0, K = 100.0;
	EurCall CallOption(T,K);
	EurPut PutOption(T,K);
	
	long N = 30000;
	cout << "Eur Call Price = " << CallOption.PriceByMC(Model, N) << endl;
	cout << "Eur Put Price = " << PutOption.PriceByMC(Model, N) << endl;
	
	return 0;

}

/*
 Eur Call Price = 21.7383
 Eur Put Price = 11.1856
 Program ended with exit code: 0
*/
