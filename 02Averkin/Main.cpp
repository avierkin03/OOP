#include "Point.h"
#include "Segment.h"
#include <iostream>
using namespace std;

int main()
{
	Point p1(0, 0);
	Point p2(1, 3);
	Segment s1(p1, p2);
	Segment s2 = s1;

	cout << "------------------------------" << endl;

	double x0(2);
	double y0(0);
	double x1(-4);
	double y1(0);
	Segment sgm(x0, y0, x1, y1);
	cout << "Length of " << sgm << " is: " << sgm.length() << endl;

	cout << "------------------------------" << endl;

	sgm.startX() = 1.0;
	sgm.startY() = 1.0;
	sgm.endX() = 6.0;
	sgm.endY() = 2.0;
	cout << "The length of " << sgm << " is: " << sgm.length() << endl;
	cout << "Segment starts: " << sgm.start()  << ", ends: " << sgm.end() << endl;
	cout << "Segment starts with X: " << sgm.startX() << ", ends with Y: " << sgm.endY() << endl;

	cout << "------------------------------" << endl;

	Point p3(2, 2);
	Point p4(2, -5);
	cout << "Distance from " << p3 << " to " << sgm << " is: " << sgm.distance(p3) << endl;
	cout << "Distance from " << p4 << " to " << sgm << " is: " << sgm.distance(p4) << endl;

	cout << "------------------------------" << endl;

	return 0;
}