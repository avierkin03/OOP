#include "Date.h"
#include <ctime>
#define NDEBUG

bool Date::defaultSet = false;
Date Date::defaultDate = Date(1, jan, 1);

string Date::monthNames[] = {"January", "February", "March", "April", "May", "June", "July", "August","September","October", "November", "December"};

Date::Date(const int d, const Month m, const int y)
{
	fillDate(d, m, y);
}


Date::Date(const int d, const int m, const int y)
{
	fillDate(d, Month(m), y);
}


Date::Date(const Date& date) {
	fillDate(date.day(), Month(date.month()), date.year());
}


Date::~Date()
{
#ifndef NDEBUG
	cout << "Deletion " << *this << endl;
#endif
	return;
}


bool Date::thirtyDays(int month)
{
	switch (month)
	{
		case apr:
		case jun:
		case sep:
		case nov:
			return true;
		default:
			return false;
	}
}


bool Date::thirtyOneDay(int month)
{
	switch (Month(month))
	{
		case jan: case mar: case may: case jul: case aug: case oct: case dec:
			return true;
		default:
			return false;
	}
}


void Date::checkDate(const int day, const int month, const int year)
{
	if ((day > 0) && (month > 0) && (month <= 12))
	{
		if (month == 2)
		{
			if ((leapYear(year) && day > 29) || (!leapYear(year) && day > 28))
				throw BadDate(day, month, year);
		}
		else if (((thirtyOneDay(month)) && day > 31) || ((thirtyDays(month)) && day > 30))
			throw BadDate(day, month, year);
	}
	else
	{
		throw BadDate(day, month, year);
	}
}

void Date::setDefault(const int day, const Month month, const int year)
{
	try
	{
		checkDate(day, month, year);
	}
	catch (Date::BadDate bd)
	{
		cout << "Your date is wrong!" << endl;
		return;
	}
	defaultDate = Date(day, month, year);
	defaultSet = true;
#ifndef NDEBUG
	cout << "New default date: ";
	showDefault();
#endif
}


void Date::setDefault()
{
	defaultDate = Date(1, jan, 1);
	defaultSet = true;
#ifndef NDEBUG
	cout << "Set default date: ";
	showDefault();
#endif
}


void Date::showDefault()
{
	cout << defaultDate << endl;
}

int Date::day() const
{
	return _day;
}

int Date::month() const
{
	return Month(_month);
}


int Date::year() const
{
	return _year;
}


const string Date::getMonthName() const
{
	return monthNames[_month - 1];
}


void Date::setDay(const int day)
{
	try
	{
		checkDate(day, _month, _year);
	}
	catch (Date::BadDate bd)
	{
		cout << "Your day is wrong! : " << day << endl;
		return;
	}
	_day = day;
}


void Date::setMonth(const int month)
{
	try
	{
		checkDate(_day, month, _year);
	}
	catch (Date::BadDate bd)
	{
		cout << "Your month is wrong! :" << month << endl;
		return;
	}
	_month = month;
}


void Date::setDYear(const int year)
{
	try
	{
		checkDate(_day, _month, year);
	}
	catch (Date::BadDate bd)
	{
		cout << "Your year is wrong! :" << year << endl;
		return;
	}
	_year = year;
}


void Date::validateChange()
{
	if (_day < 1) {
		_month--;
		if (_month == 2) {
			if (leapYear(_year)) {
				_day = 29;
			}
			else {
				_day = 28;
			}
		}
		else if (thirtyDays(_month)) {
			_day = 30;
		}
		else {
			_day = 31;
		}
	}
	else if ((_day > 31 && thirtyOneDay(_month)) || (_day > 30 && thirtyDays(_month))) {
		_month++;
		_day = 1;
	}
	else if (_month == 2) {
		if (leapYear(_year) && _day > 29) {
			_month++;
			_day = 1;
		}
		else {
			if (_day > 28) {
				_month++;
				_day = 1;
			}
		}
	}
	if (_month > 12) {
		_month = 1;
		_year++;
	}
	if (_month < 1) {
		_month = 12;
		_year--;
	}
}


const Date& Date::operator++()
{
	++_day;
	validateChange();
	return *this;
}


const Date Date::operator++(int)
{
	Date date = *this;
	++* this;
	return date;
}


const Date& Date::operator--()
{
	--_day;
	validateChange();
	return *this;
}


const Date Date::operator--(int)
{
	Date date = *this;
	--* this;
	return date;
}


bool leapYear(int y)
{
	bool leap;
	if (y % 4)
	{
		leap = false;
	}
	else if (y % 100)
	{
		leap = true;
	}
	else if (y % 400)
	{
		leap = false;
	}
	else leap = true;
	return leap;
}

ostream& operator<<(ostream& os, const Date& d)
{
	return os << d.day() << '/' << d.month() << '/' << d.year();
}

ostream& operator<<(ostream& os, const Date::BadDate& bd)
{
	return os << "Bad date: " << bd._day << '/' << bd._month << '/' << bd._year;
}


void Date::fillDate(int d, Month m, int y)
{
	_day = d ? d : defaultDate._day;
	_month = m ? m : defaultDate._month;
	_year = y ? y : defaultDate._year;
	try
	{
		checkDate(_day, _month, _year);
	}
	catch (Date::BadDate bd)
	{
		cout << "Your date is wrong!" << endl;
		return;
	}
#ifndef NDEBUG
	cout << "Filled date: " << *this << endl;
#endif
}