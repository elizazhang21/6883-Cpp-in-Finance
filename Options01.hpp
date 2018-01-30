//
//  Options01.hpp
//  HW1
//
//  Created by Elizabeth Zhang on 1/24/18.
//  Copyright © 2018 Elizabeth Zhang. All rights reserved.
//

#ifndef Options01_hpp
#define Options01_hpp

#include <stdio.h>

//inputting and displaying option data
int GetInputData(int& N, double& K);

//pricing European option
double PriceByCRR(double S0, double U, double D, double R, int N, double K);

//computing call payoff
double CallPayoff(double z, double K);
#endif /* Options01_hpp */
