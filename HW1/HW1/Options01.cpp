//
//  Options01.cpp
//  HW1
//
//  Created by Elizabeth Zhang on 1/24/18.
//  Copyright © 2018 Elizabeth Zhang. All rights reserved.
//

#include "Options01.hpp"
#include "BinModel01.hpp"
#include <iostream>
#include <cmath>
using namespace std;

int GetInputData(int& N, double& K){
    cout << "Enter steps to expiry N: "; cin >> N;
    cout << "Enter strike price K: "; cin >> K;
    cout << endl;
    return 0;
}

double CallPayoff(double z, double K)
{
    if (z>K) return z-K;
    return 0.0;
}

//define Binomial Coefficient
double BinCo(int N, int i){
    if (i<0 || i>N) return 0;
    double result=1;
    for (int n=1; n<=i; n++) result=result*(N-i+n)/n;
    return result;
}


double PriceByCRR(double S0, double U, double D, double R, int N, double K)
{
    double q=RiskNeutProb(U,D,R);
    double Price = 0;
    for (int i=0; i<=N; i++)
    {
        Price=Price + BinCo(N,i) * pow(q,i)*pow(1-q,N-i)
        *CallPayoff(S(S0,U,D,N,i),K)/pow(1+R,N);
    }
    return Price;
}

