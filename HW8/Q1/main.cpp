//
//  main.cpp
//  Assignment8_q1
//
//  Created by Elizabeth Zhang on 3/23/18.
//  Copyright © 2018 Elizabeth Zhang. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include "Solver03.hpp"
using namespace std;

class F1
{
public:
	double Value(double x){return x*x -2;}
	double Deriv(double x){return 2*x;}
}MyF1;

class F2
{
private:
	double a;
public:
	F2(double a_){a=a_;}
	double Value(double x){return x*x-a;}
	double Deriv(double x){return 2*x;}
} MyF2(3.0);

int main() {
	cout << setiosflags(ios::fixed) << setprecision(4);
	double Acc=0.001;
	double LEnd=0.0, REnd=2.0;
	double Tgt=0.0;
	double Guess=1.0;
	
	cout << "Root of F1 by bisect: " << SolveByBisect(&MyF1, Tgt, LEnd, REnd, Acc) << endl;
	cout << "Root of F2 by bisect: " << SolveByBisect(&MyF2, Tgt, LEnd, REnd, Acc) << endl;
	cout << "Root of F1 by Newton-Raphson: " << SolveByNR(&MyF1, Tgt, Guess, Acc) << endl;
	cout << "Root of F2 by Newton-Raphson: " << SolveByNR(&MyF2, Tgt, Guess, Acc) << endl;

	return 0;
}

/*
 
Root of F1 by bisect: 1.4150
Root of F2 by bisect: 1.7314
Root of F1 by Newton-Raphson: 1.4142
Root of F2 by Newton-Raphson: 1.7321
Program ended with exit code: 0
 
 */
