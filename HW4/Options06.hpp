//
//  Options06.hpp
//  HW4
//
//  Created by Elizabeth Zhang on 2/18/18.
//  Copyright © 2018 Elizabeth Zhang. All rights reserved.
//

#ifndef Options06_hpp
#define Options06_hpp

#include "BinModel02.hpp"

class EurOption
{
private:
    int N; //steps to expiry
public:
    void SetN(int N_){N=N_;}
    //Payoff defined to return 0.0
    //for pedagogical purposes.
    //To use a pure virtual function replace by
    //virtual double Payoff(double z)=0;
    virtual double Payoff(double z){return 0.0;}
    //pricing European option
    double PriceByCRR(BinModel Model);
};

class Call: public EurOption
{
private:
    double K; //strike price
public:
    void SetK(double K_){K=K_;}
    int GetInputData();
    double Payoff(double z);
};

class Put: public EurOption
{
private:
    double K; //strike price
public:
    void SetK(double K_){K=K_;}
    int GetInputData();
    double Payoff(double z);
};

class BullSpread: public EurOption
{
private:
    double K1; //parameter 1
    double K2; //parameter 2
public:
    int GetInputData();
    double Payoff(double z);
};

class BearSpread: public EurOption
{
private:
    double K1; //parameter 1
    double K2; //parameter 2
public:
    int GetInputData();
    double Payoff(double z);
};

#endif

