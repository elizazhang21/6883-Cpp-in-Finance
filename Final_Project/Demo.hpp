//
//  Demo.hpp
//  Final Project
//
//  Created by Elizabeth Zhang on 4/24/18.
//  Copyright © 2018 Elizabeth Zhang. All rights reserved.
//

#ifndef Demo_hpp
#define Demo_hpp

#include"ExcelDriver\ExcelDriver.hpp"
#include"ExcelDriver\stdafx.h"
#include"ExcelDriver\BitsAndPieces\StringConversions.hpp"
#include"ExcelDriver\ExcelMechanisms.hpp"
#include"ExcelDriver\VectorsAndMatrices\NumericMatrix.cpp"
#include"ExcelDriver\ExceptionClasses\DatasimException.hpp"
#include"Group.hpp"
using namespace std;

void Menu(const Group& Beat, const Group& Meet, const Group& Miss, const vector<vector<vector<double>>>& ReturnMatrix);

void StockInfo(const Group& Beat, const Group& Meet, const Group& Miss);
void StatsInfo(const vector<vector<vector<double>>>& ReturnMatrix);
void PicDemo(const vector<vector<vector<double>>>& ReturnMatrix);

#endif /* Demo_hpp */
