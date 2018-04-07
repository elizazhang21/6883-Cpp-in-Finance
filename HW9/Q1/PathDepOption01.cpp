//
//  PathDepOption01.cpp
//  Assignment9_q1
//
//  Created by Elizabeth Zhang on 3/26/18.
//  Copyright © 2018 Elizabeth Zhang. All rights reserved.
//

#include "PathDepOption01.hpp"
#include <cmath>

double PathDepOption::PriceByMC(BSModel Model, long N)
{
	double H = 0.0;
	SamplePath S(m);
	for (long i = 0; i<N; i++)
	{
		Model.GenerateSamplePath(T,m,S);
		H = (i*H + Payoff(S))/(i+1);
	}
	return exp(-Model.r*T) * H;
}

double ArthmAsianCall::Payoff(SamplePath& S)
{
	double Ave = 0.0;
	for (int k=0; k<m; k++) Ave = (k*Ave + S[K])/(k+1);
	if (Ave<K) return 0;
	return Ave - K;
}

double EurCall::Payoff(SamplePath& S)
{
	if (S[0] < K) return 0.0;
	return S[0] - K;
}

double EurPut::Payoff(SamplePath& S)
{
	if (K<S[0]) return 0.0;
	return K-S[0];
}
