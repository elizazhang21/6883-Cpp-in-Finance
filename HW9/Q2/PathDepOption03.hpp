//
//  PathDepOption03.hpp
//  Assignment9_q2
//
//  Created by Elizabeth Zhang on 3/26/18.
//  Copyright © 2018 Elizabeth Zhang. All rights reserved.
//

#ifndef PathDepOption03_hpp
#define PathDepOption03_hpp

#include <stdio.h>
#include "BSModel.hpp"

class PathDepOption
{
public:
	double T, Price, PricingError,delta, rho, vega, theta, gamma;
	int m;
	virtual double Payoff(SamplePath& S) = 0;
	double PriceByMC(BSModel Model, long N, double epsilon);
};

class ArthmAsianCall: public PathDepOption
{
public:
	double K;
	ArthmAsianCall(double T_, double K_, int m_){T=T_; K=K_; m=m_;}
	double Payoff(SamplePath& S);
};

class EurCall: public PathDepOption
{
public:
	double K;
	EurCall(double T_, double K_){T=T_, K=K_, m=1;}
	double Payoff(SamplePath& S);
};

class EurPut: public PathDepOption
{
public:
	double K;
	EurPut(double T_, double K_){T=T_, K=K_; m=1;}
	double Payoff(SamplePath& S);
};



#endif /* PathDepOption03_hpp */
