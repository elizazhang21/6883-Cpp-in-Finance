//
//  main.cpp
//  HW5
//
//  Created by Elizabeth Zhang on 2/18/18.
//  Copyright © 2018 Elizabeth Zhang. All rights reserved.
//

#include "BinModel02.hpp"
#include "Options06.hpp"
#include "DoubDigitOpt.hpp"
#include "SpreadOptions.hpp"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    BinModel Model;
    
    if (Model.GetInputData() == 1) return 1;
    
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
    
    DoubDigitOpt Option3;
    Option3.GetInputData();
    cout << "European double-digital option price = "
    << Option3.PriceByCRR(Model)
    << endl << endl;
    
    StrangleOpt Option4;
    Option4.GetInputData();
    cout << "European strangle spread option price = "
    << Option4.PriceByCRR(Model)
    << endl << endl;
    
    ButterflyOpt Option5;
    Option5.GetInputData();
    cout << "European butterfly spread option price = "
    << Option5.PriceByCRR(Model)
    << endl << endl;
    
    return 0;
}

/*
 Enter S0: 106
 Enter U:  0.1525
 Enter D:  -0.13138
 Enter R:  0.00545
 
 Input data checked
 There is no arbitrage
 
 Enter call option data:
 Enter steps to expiry N: 8
 Enter strike price K:    100
 
 European call option price = 21.7726
 
 Enter put option data:
 Enter steps to expiry N: 8
 Enter strike price K:    100
 
 European put option price = 11.5176
 
 Enter double-digital option data:
 Enter steps to expiry N: 8
 Enter parameter K1:      100
 Enter parameter K2:      110
 
 European double-digital option price = 0.260448
 
 Enter European strangle option data:
 Enter steps to expiry N: 8
 Enter parameter K1:      100
 Enter parameter K2:      110
 
 N  = 8
 K1 = 100
 K2 = 110
 
 European strangle spread option price = 28.4991
 
 Enter European butterfly spread option data:
 Enter steps to expiry N: 8
 Enter parameter K1:      100
 Enter parameter K2:      110
 
 N  = 8
 K1 = 100
 K2 = 110
 
 European butterfly spread option price = 0.921831
 
 Program ended with exit code: 0
 */
