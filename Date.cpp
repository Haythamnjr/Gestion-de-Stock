#include"Date.h"
#include"StockItem.h"
#include<iostream>
#include "Exception.h"
Date::Date(int DAY, int MONTH, int YEAR) {
	setDay(DAY); setMonth(MONTH); setYear(YEAR);
}


int Date::getDay() const {
	return this->Day;
}

void Date::setDay(int Day) {
	if (Day < 1 || Day > 31) {
		throw Exception("Entrer le jour qui compris entre 1 ou 31");
		return;
	}
	

	this->Day = Day;
}

int Date::getMonth() const {
	return this->Month;
}

void Date::setMonth(int Month) {
	if (Month < 1 || Month > 12) {
		throw Exception("Entrer le mois qui compris entre 1 ou 12");
		return;
	}
	
	this->Month = Month;
}

int Date::getYear() const {
	return this->Year;
}

void Date::setYear(int Year) {
	if (Year < 2000) {
		throw Exception("L'année doit être postérieure à 2000");
		return;
	}
	
	this->Year = Year;
}