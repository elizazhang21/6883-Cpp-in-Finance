//
//  main.cpp
//  HW4
//
//  Created by Elizabeth Zhang on 2/18/18.
//  Copyright © 2018 Elizabeth Zhang. All rights reserved.
//

#include <iostream>
#include <cmath>
#include "BinModel02.hpp"
#include "Options06.hpp"

using namespace std;

int main()
{
    BinModel Model;
    
    if (Model.GetInputData()==1) return 1;
    
    Call Option1;
    Option1.GetInputData();
    cout << "European call option price = "
    << Option1.PriceByCRR(Model)
    << endl << endl;
    
    Put Option2;
    Option2.GetInputData();
    cout << "European put option price = "
    << Option2.PriceByCRR(Model)
    << endl << endl;
    
    BullSpread Option3;
    Option3.GetInputData();
    cout << "European bull spread price = "
    << Option3.PriceByCRR(Model)
    << endl << endl;
    
    BearSpread Option4;
    Option4.GetInputData();
    cout << "European bear spread price = "
    << Option4.PriceByCRR(Model)
    << endl << endl;
    
    return 0;
}

/*
 Enter S0: 106
 Enter U:  0.15125
 Enter D:  -0.13138
 Enter R:  0.00545
 
 Input data checked
 There is no arbitrage
 
 Enter call option data:
 Enter steps to expiry N: 8
 Enter strike price K:    100
 
 European call option price = 21.6811
 
 Enter put option data:
 Enter steps to expiry N: 8
 Enter strike price K:    100
 
 European put option price = 11.4261
 
 Enter European bull spread data:
 Enter steps to expiry N: 8
 Enter parameter K1:      100
 Enter parameter K2:      110
 
 European bull spread price = 4.71584
 
 Enter European bear spread data:
 Enter steps to expiry N: 8
 Enter parameter K1:      100
 Enter parameter K2:      110
 
 European bear spread price = 4.85866
 
 Program ended with exit code: 0
 */
