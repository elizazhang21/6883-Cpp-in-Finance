//
//  GmtrAsianCall.hpp
//  Assignment9_q3
//
//  Created by Elizabeth Zhang on 3/27/18.
//  Copyright © 2018 Elizabeth Zhang. All rights reserved.
//

#ifndef GmtrAsianCall_hpp
#define GmtrAsianCall_hpp

#include <stdio.h>
#include "PathDepOption04.hpp"


class GmtrAsianCall: public PathDepOption
{
public:
	double K;
	GmtrAsianCall(double T_, double K_, int m_)
	{T=T_; K=K_; m=m_;}
	double Payoff(SamplePath& S);
	double PriceByBSFormula(BSModel Model);
	double DeltaByBSFormula(BSModel Model);
};

#endif /* GmtrAsianCall_hpp */
