#pragma once
#include <iostream>
using namespace std;

class Point
{
private:
	static int _freeID;
	const int _pointID;
	double _x;
	double _y;

public:
	Point(double x = 0, double y = 0);
	Point(const Point&);
	~Point();
	Point& operator=(const Point&);
	double& x();
	double& y();
	const double& x()const;
	const double& y()const;
	const int getID() const;
	static int amount();
};

ostream& operator<<(ostream&, const Point&);
const Point operator+ (const Point& u, const Point& v);
Point& operator+=(Point&, const Point&);
bool operator==(const Point& u, const Point& v);
bool operator!=(const Point& u, const Point& v);