//
//  EurCall.hpp
//  Assignment9_q3
//
//  Created by Elizabeth Zhang on 3/27/18.
//  Copyright © 2018 Elizabeth Zhang. All rights reserved.
//

#ifndef EurCall_hpp
#define EurCall_hpp

#include <stdio.h>

class EurCall
{
public:
	double T, K;
	EurCall(double T_, double K_){T=T_; K=K_;}
	double d_plus(double S0, double sigma, double r);
	double d_minus(double S0, double sigma, double r);
	double PriceByBSFormula(double S0, double sigma, double r);
	double VegaByBSFormula(double S0, double sigma, double r);
	double DeltaByBSFormula(double S0, double sigma, double r);
};


#endif /* EurCall_hpp */
