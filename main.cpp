//
//  main.cpp
//  HW2
//
//  Created by Elizabeth Zhang on 1/31/18.
//  Copyright © 2018 Elizabeth Zhang. All rights reserved.
//

#include "BinModel01.hpp"
#include "Options03.hpp"
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double S0,U,D,R;
    if (GetInputData(S0,U,D,R)==1) return 1;
    double K;   //strike price
    int N;      	//steps to expiry
    //computing call option price and digital call option price
    cout << "Enter call option data:" << endl;
    GetInputData(N,K);
    cout << "European call option price = "<< PriceByCRR(S0,U,D,R,N,K,CallPayoff)<< endl << endl;
    cout << "European digital call option price = " << PriceByCRR(S0,U,D,R,N,K,DigitalCallPayoff)<<endl<<endl;
    
    //computing put option price and digital put option price
    cout << "Enter put option data:" << endl;
    GetInputData(N,K);
    cout << "European put option price =  " << PriceByCRR(S0,U,D,R,N,K,PutPayoff)<< endl << endl;
    cout << "European digital put option price = " << PriceByCRR(S0,U,D,R,N,K,DigitalPutPayoff)<<endl<<endl;
    return 0;
}

/*
 Enter S0: 106
 Enter U: 0.15125
 Enter D: -0.13138
 Enter R: 0.00545
 
 Input data checked
 There is no arbitrage
 
 Enter call option data:
 Enter steps to expiry N: 8
 Enter strike price K:    100
 
 European call option price = 21.6811
 
 European digital call option price = 0.575897
 
 Enter put option data:
 Enter steps to expiry N: 8
 Enter strike price K:    100
 
 European put option price =  11.4261
 
 European digital put option price = 0.381553
 
 Program ended with exit code: 0
*/
