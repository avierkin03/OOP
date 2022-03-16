#include "Date.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Default date: ";
	Date::showDefault();

	cout << "\nChanging default date to new: ";
	Date::setDefault(31, Date::Month(1), 2022);
	Date::showDefault();

	cout << "\nReturn to default date: ";
	Date::setDefault();
	Date::showDefault();

	cout << "-----------------------------------------------------" << endl;

	cout << "Operators:\n" << endl;
	Date d;
	Date d1(28, 2, 2022);
	Date d2(d1);

	cout << "--(" << d1 << ')';
	cout << " --> Result: " << --d1 << endl;

	cout << "\n(" << d1 << ")--";
	d1--;
	cout << " --> Result: " << d1 << endl;

	cout << "\n++(" << d2 << ')';
	cout << " --> Result: " << ++d2 << endl;

	cout << "\n(" << d1 << ")++";
	d1++;
	cout << " --> Result: " << d1 << endl;

	Date leapFbr(29, 02, 2020);
	cout << "\n++(" << leapFbr << ')';
	cout << " --> Result: " << ++leapFbr << endl;

	cout << "-----------------------------------------------------" << endl;

	cout << "Changing the date to my date of birth:" << endl;
	leapFbr.setDay(20);
	leapFbr.setMonth(02);
	leapFbr.setDYear(2003);
	cout << "Result: " << leapFbr << endl;

	cout << "\nChanging the date to a non-existent one(trying 45/2/2003):" << endl;
	leapFbr.setDay(45);
	cout << "Result: " << leapFbr << endl;

	cout << "-----------------------------------------------------" << endl;

	cout << "Creating incorrect date: " << endl;
	Date wd(111, 50, 2019);

	return 0;
}