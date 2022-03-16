#include "Triangle.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "1) Triangle created by coordinates:" << endl<<endl;
	Triangle t1(0, 0, 0, 8, 2, 0);
	cout << t1 << endl;
	cout << "\nVertices of the first triangle:" << endl;
	cout << "A: " << t1.apexA() << endl;
	cout << "B: " << t1.apexB() << endl;
	cout << "C: " << t1.apexC() << endl;

	cout << "\nSides of the first triangle:" << endl;
	cout << "Side BC: " << t1.side_a() << endl;
	cout << "Side CA: " << t1.side_b() << endl;
	cout << "Side AB: " << t1.side_c() << endl;

	cout << "\nMedians of the first triangle:" << endl;
	cout << "Meadian a: " << t1.median_a() << endl;
	cout << "Meadian b: " << t1.median_b() << endl;
	cout << "Meadian c: " << t1.median_c() << endl;

	cout << "\nArea of the first triangle: " << t1.square() << endl;

	cout << "------------------------------------------" << endl;

	cout << "2) Triangle created by points:" << endl << endl;
	Point a(0, 0);
	Point b(0, 6);
	Point c(8, 0);
	Triangle t2(a,b,c);
	cout << t2 << endl;
	cout << "Length of side BC " << t2.side_a() << " is: " << t2.length_a() << endl;
	cout << "Length of side CA " << t2.side_b() << " is: " << t2.length_b() << endl;
	cout << "Length of side AB " << t2.side_c() << " is: " << t2.length_c() << endl;

	cout << "------------------------------------------" << endl;

	cout << "3) Triangle copy:" << endl << endl;
	Triangle ñopyT2 = t2;
	cout << "Creating a new triangle and copy the value of t2 into it: " << ñopyT2 << endl;
	
	cout << "Copying " << t2 << " to " << ñopyT2 << ": " ;
	ñopyT2 = t1;
	cout << ñopyT2 << endl;

	return 0;
}