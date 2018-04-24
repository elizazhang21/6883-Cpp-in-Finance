#ifndef Group_hpp
#define Group_hpp

#include <stdio.h>
#include "Equity.hpp"
#include <map>
#define SampleNum 40
using namespace std;

class Group{
public:
	map<string, Stock> Content;
	vector<string> Ticker;
	vector<double> AAR;
	vector<double> CAAR;
	
	void GenSurprise(vector<string> SPYDate, vector<double> SPYPrice);
	void GenAAR();
	void GenCAAR();
};

void RandSelect(Group& StockGroup, Group& Sample);

#endif /* Group_hpp */
