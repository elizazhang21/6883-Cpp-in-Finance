#include"Stock.h"
#include"YeMatrix.h"
#include<algorithm>
#include<sstream>
using namespace std;
ostream& operator<<(ostream& os, const Stock& source)
{
	os << "Ticker: " << source.Ticker << endl << "Announcement Date: " << source.Date[32]
	<< endl << "Actual EPS: " << source.Act_EPS << endl << "Estimate EPS: " << source.Est_EPS;
	return os;
}

void Stock::SetTicker(string name)
{
	Ticker = name;
}
string Stock::GetTicker() const
{
	return Ticker;
}
void Stock::SetStartTime(char* source)
{
	StartTime = source;
}
string Stock::GetStartTime() const
{
	return StartTime;
}
void Stock::SetEndTime(char* source)
{
	EndTime = source;
}
string Stock::GetEndTime() const
{
	return EndTime;
}

//Computing Daily Return
void Stock::GenDailyReturn()
{
	DailyReturn.resize(DayNum);
	for (int i = 0; i<DayNum; i++) DailyReturn[i] = Price[i + 1] / Price[i] - 1;
}

void Stock::GenAbnormalReturn(vector<string> SPYDate, vector<double>SPYPrice)
{
	Vector_d SPYReturn;
	vector<string>::iterator it = std::find(SPYDate.begin(), SPYDate.end(), StartTime);
	int a = std::distance(SPYDate.begin(), it) + 1;
	for (int i = a; i<a + DayNum; i++)
		SPYReturn.push_back(SPYPrice[i] / SPYPrice[i - 1] - 1);
	AbnormalReturn = DailyReturn - SPYReturn;
}
void Stock::printInfo() const
{
	NumericMatrix<double, long> matrix(62, 1);
	NumericMatrix<double, long> info(1, 3);
	list<std::string> rowlabels ;
	list<std::string> columnlabels;
	list<std::string> inforow;
	list<std::string> infocol;
	string day0;
	inforow.push_back(Ticker);
	infocol.push_back("Est_EPS");
	infocol.push_back("Act_EPS");
	infocol.push_back("Day0");
	day0 = Date[31];
	day0 = day0.erase(4,1).erase(6,1);
	stringstream s_eEPS(Est_EPS),s_aEPS(Act_EPS),s_date(day0);
	double d_eEPS,d_aEPS,d_date;
	s_eEPS >> d_eEPS;
	s_aEPS >> d_aEPS;
	s_date >> d_date;
	info(1, 1) = d_eEPS;
	info(1, 2) = d_aEPS;
	info(1, 3) = d_date;
	columnlabels.push_back("PRICE");
	for (int i = 0; i < 62; i++)
	{
		matrix(i+1, 1) = Price[i];
		rowlabels.push_back(Date[i]);
	}
	std::string sheetName("Stock_Price");
	std::string sheetName1("Stock_Info");
	ExcelDriver& excel = ExcelDriver::Instance();
	excel.MakeVisible(true);		// Default is INVISIBLE!
	excel.AddMatrix(sheetName, matrix, rowlabels, columnlabels);
	excel.AddMatrix(sheetName1, info, inforow, infocol);
}
