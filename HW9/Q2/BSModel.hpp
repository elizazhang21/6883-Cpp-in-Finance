//
//  BSModel.hpp
//  Assignment9_q1
//
//  Created by Elizabeth Zhang on 3/26/18.
//  Copyright © 2018 Elizabeth Zhang. All rights reserved.
//

#ifndef BSModel_hpp
#define BSModel_hpp

#include <cmath>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

typedef vector<double> SamplePath;

class BSModel
{
public:
	double S0, r, sigma;
	BSModel(double S0_, double r_, double sigma_){S0=S0_; r=r_; sigma=sigma_;srand((unsigned int)time(NULL));}
	void GenerateSamplePath(double T, int m, SamplePath& S);
};

#endif /* BSModel_hpp */
