#ifndef GetYahooData_hpp
#define GetYahooData_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include <vector>
#include <locale>
#include <iomanip>
#include "Group.hpp"
#include "curl/curl.h"

using namespace std;

void GetAllData(Group& Beat, Group& Meet, Group& Miss, string* fileList);
size_t write_data(void *ptr, int size, int nmemb, FILE *stream);
void *myrealloc(void *ptr, size_t size);
size_t write_data2(void *ptr, size_t size, size_t nmemb, void *data);
string getTimeinSeconds(string Time);
int GetStockPrice(Group& StockList);
int GetSPYPrice(Stock& SPY);

#endif /* GetYahooData_hpp */
