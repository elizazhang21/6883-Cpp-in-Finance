#ifndef Date_hpp
#define Date_hpp

#include <iostream>
#include <map>
#include <string>

using namespace std;

class Date {
private:
	int year;
	int month;
	int day;
	
public:
	Date() :year(0), month(0), day(0) {}
	Date(int year_, int month_, int day_) :year(year_), month(month_), day(day_) {}
	Date(const Date& date_) :year(date_.year), month(date_.month), day(date_.day) {}
	~Date() {}
	bool operator>(const Date& obj) const;
	bool operator<(const Date& obj) const;
	bool operator==(const Date& obj) const;
	bool operator<=(const Date& obj) const;
	bool operator>=(const Date& obj) const;
	const Date& operator=(const Date& obj);
	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;
	void SetYear(int y);
	void SetMonth(int m);
	void SetDay(int d);
	string toString() const;
};

inline ostream & operator<<(ostream & out, Date d) {
	out << d.GetYear() << "-" << d.GetMonth() << "-" << d.GetDay();
	return out;
}

#endif /* Date_hpp */
