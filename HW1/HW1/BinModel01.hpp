//
//  BinModel01.hpp
//  HW1
//
//  Created by Elizabeth Zhang on 1/24/18.
//  Copyright © 2018 Elizabeth Zhang. All rights reserved.
//

#ifndef BinModel01_hpp
#define BinModel01_hpp

#include <stdio.h>

//computing risk-neutral probability
double RiskNeutProb(double U, double D, double R);

//computing the stock price at node n, i
double S(double S0, double U, double D, int n, int i);

//inputting, displaying and checking model data
int GetInputData(double& S0, double& U, double& D, double& R);
#endif /* BinModel01_hpp */
