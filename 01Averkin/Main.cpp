#include "Point.h"
#include <iostream>
using namespace std;

int main()
{
	Point a(1, 4);
	Point b(2, 5);
	Point c(3, 6);

	Point d = a + b;
	cout << "\n1)\n" << a << " + " << b << " = " << d << endl;

	cout << "\n2)\n" << "Number of Points created: " << Point::amount() << endl;

	cout << "\n3)\n" << a << " += " << b;
	a += b;
	cout << "  -->  " << a << endl;

	cout << "\n4)\n" << "Using operator '='(A=C)" << endl;
	cout << "So, A (" << a << ") is now has the same coordinates as C (" << c <<')';
	a = c;
	cout << ": a = " << a << " and c = " << c << endl;

	cout << "\n5)\n" << "Checking if Point A(" << a << ") is equal to Point C(" << c << ") : " << boolalpha <<(a == c) << endl;
	cout << "Checking if Point A("<< a << ") is equal to Point B("<< b <<") : " << (a == b) << endl;
	cout << "Checking if Point A(" << a << ") is not equal to Point C(" << c << ") : " << (a != c) << endl;
	cout << "Checking if Point A(" << a << ") is not equal to Point D(" << d << ") : " << (a != b) << endl;

	cout << "\n6)\n" << "The ID of Point A: " << a.getID() << endl;
	cout << "The ID of Point B: " << b.getID() << endl;
	cout << "The ID of Point C: " << c.getID() << endl;
	cout << "The ID of Point D: " << d.getID() << endl << endl;
	return 0;
}