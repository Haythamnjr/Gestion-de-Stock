#ifndef DATE_H
#define DATE_H
#include<iostream>
using namespace std;

class Date {

private:

	int Day, Month, Year;

public:

	Date(int DAY, int MONTH, int YEAR);

	Date() = default;

	int getDay()const;

	virtual void setDay(int Day);

	int getMonth()const;

	virtual void setMonth(int Month);

	int getYear()const;

	virtual void setYear(int Year);

};


#endif

