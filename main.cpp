//
//  main.cpp
//  HW3
//
//  Created by Elizabeth Zhang on 2/7/18.
//  Copyright © 2018 Elizabeth Zhang. All rights reserved.
//

#include <iostream>
using namespace std;

class DefInt
{
private:
    double a, b;
    double (*f)(double x);
public:
    DefInt(double a_, double b_, double (*f_)(double x))
    {a = a_; b = b_; f = f_;}
    double ByTrapezoid(int N);
    double BySimpson(int N);
};

double DefInt::ByTrapezoid(int N)
{
    double h=(b - a) / N;
    double Result=0.5 * f(a);
    for (int k = 1; k < N; k++) Result += f(a + k * h);
    Result += 0.5 * f(b);
    return Result * h;
}

double DefInt::BySimpson(int N)
{
    double h=(b-a)/N;
    double Result=f(a);
    for (int k = 1; k < N; k++) Result += 4 * f(a + k*h - 0.5*h) + 2*f(a + k*h);
    Result += 4 * f(b - 0.5*h) + f(b);
    return Result * h/6;
}

//Verify the integration result, such as f(x) = x*x*x + x*x + 1, a = 1.0 and b = 2.0
double f(double x){return x*x*x-x*x+1;}

int main()
{
    double a=1.0;
    double b=2.0;
    DefInt MyInt(a,b,f);
    int N=10;
    cout << "Trapeziodal approximation = "
    << MyInt.ByTrapezoid(N) << endl;
    cout << "Simpson approximation     = "
    << MyInt.BySimpson(N) << endl;
    return 0;
}
