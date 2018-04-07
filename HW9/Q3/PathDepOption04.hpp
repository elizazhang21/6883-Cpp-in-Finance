//
//  PathDepOption04.hpp
//  Assignment9_q3
//
//  Created by Elizabeth Zhang on 3/27/18.
//  Copyright © 2018 Elizabeth Zhang. All rights reserved.
//

#ifndef PathDepOption04_hpp
#define PathDepOption04_hpp

#include <stdio.h>
#include "BSModel.hpp"

class PathDepOption
{
public:
	double T, Price, PricingError, delta;
	int m;
	virtual double Payoff(SamplePath& S) = 0;
	double PriceByMC(BSModel Model, long N, double epsilon);
	double PriceByVarRedMC(BSModel Model, long N, PathDepOption& CVOption, double epsilon);
	virtual double PriceByBSFormula(BSModel Model)  {return 0.0;}
	virtual double DeltaByBSFormula(BSModel Model)  {return 0.0;}
};

class DifferenceOfOptions: public PathDepOption
{
public:
	PathDepOption *ptr1;
	PathDepOption *ptr2;
	DifferenceOfOptions(double T_, int m_, PathDepOption *ptr1_, PathDepOption *ptr2_)
	{
		T=T_; m=m_;ptr1=ptr1_; ptr2=ptr2_;
	}
	double Payoff(SamplePath& S)
	{
		return ptr1 -> Payoff(S) - ptr2 -> Payoff(S);
	}
};

class ArthmAsianCall: public PathDepOption
{
public:
	double K;
	ArthmAsianCall(double T_, double K_, int m_){T=T_; K=K_; m=m_;}
	double Payoff(SamplePath& S);
};

#endif /* PathDepOption04_hpp */
