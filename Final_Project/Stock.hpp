#ifndef Stock_h
#define Stock_h

#include<string>
#include<vector>
#include<map>
#include<iostream>
#include"ExcelDriver\ExcelDriver.hpp"
#include"ExcelDriver\stdafx.h"
#include"ExcelDriver\BitsAndPieces\StringConversions.hpp"
#include"ExcelDriver\ExcelMechanisms.hpp"
#include"ExcelDriver\VectorsAndMatrices\NumericMatrix.cpp"
#include"ExcelDriver\ExceptionClasses\DatasimException.hpp"

#define DayNum 61
using namespace std;

class Stock
{
private:
	string StartTime;
	string EndTime;
	string Ticker;
	
public:
	string Est_EPS;
	string Act_EPS;
	vector<double> Price;
	vector<double> DailyReturn;
	vector<double> AbnormalReturn;
	vector<string> Date;
	Stock():Ticker("0"), StartTime("0"), EndTime("0"), Act_EPS(0), Est_EPS(0) {}
	Stock(string ticker, string startdate, string enddate, string act_eps, string est_eps)
	:Ticker(ticker), StartTime(startdate), EndTime(enddate), Act_EPS(act_eps), Est_EPS(est_eps) {}
	void SetTicker(string name);
	string GetTicker() const;
	void SetStartTime(char* source);
	string GetStartTime() const;
	void SetEndTime(char* source);
	string GetEndTime() const;
	void printInfo() const;
	
	void GenDailyReturn();
	void GenAbnormalReturn(vector<string> SPYDate, vector<double> SPYPrice);
	
	friend ostream& operator<<(ostream& os, const Stock& source);
};
#endif
