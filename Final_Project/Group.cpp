#include "Group.hpp"
#include "YeMatrix.hpp"
#include<algorithm>
#include<numeric>
#include<time.h>

# define DayNum 61
using namespace std;

void RandSelect(Group& StockGroup, Group& Sample)
{
	vector<int> index_(StockGroup.Ticker.size());
	iota(index_.begin(), index_.end(), 0);
	srand(time(NULL));
	random_shuffle(index_.begin(), index_.end());
	for (unsigned int i = 0; i < SampleNum; i++)
	{
		
		map<string, Stock>::iterator itr = StockGroup.Content.find(StockGroup.Ticker[index_[i]]);
		if (itr != StockGroup.Content.end())
			Sample.Content.insert(pair<string, Stock>(StockGroup.Ticker[i], itr->second));
	}
}

void Group::GenAAR()
{
	Vector_d W(DayNum, 0);
	map<string, Stock>::iterator it;
	for (it = Content.begin(); it != Content.end(); it++)
		W = W + it->second.GetSurprise();
	W = W / SampleNum;
	AAR = W;
}

void Group::GenCAAR()
{
	CAAR = Cumsum(AAR);
}


void Group::GenSurprise(vector<string> SPYDate, vector<double> SPYPrice)
{
	for (map<string, Stock>::iterator itr = Content.begin(); itr != Content.end(); )
	{
		itr->second.GenDailyReturn();
		itr->second.GenAbnormalReturn(SPYDate, SPYPrice);
		itr++;
	}
	
}
