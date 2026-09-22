#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <memory>
#include <mysql/jdbc.h>
using namespace std;


class DataBase {
protected:
	unique_ptr<sql::Connection>data;
	std::string Host = "localhost";
	std::string User = "root";
	std::string Password = "";
public:
	DataBase();
	virtual ~DataBase() = default;

};

/*
cette Classe qui Representer la Date de Entrer de Stock qui caracteriser par 

*/
class Date:public DataBase {

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

