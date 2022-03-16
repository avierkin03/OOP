#include "Point.h"
using namespace std;
//#define NDEBUG

int Point::_freeID = 0;

Point::Point(double x, double y):_x(x), _y(y), _pointID(_freeID)
{
	_freeID += 1;
#ifndef NDEBUG
	cout << "Creating " << *this << " id = " << _pointID << endl;
#endif
	return;
}

Point::Point(const Point& point):_x(point.x()), _y(point.y()), _pointID(_freeID)
{
	_freeID += 1;
#ifndef NDEBUG
	cout << "Point: " << *this << " with ID: " << _pointID << " has been copied." << endl;
#endif
	return;
}

Point::~Point()
{
#ifndef NDEBUG
	cout << "Deletion " << *this << " id = " << _pointID << endl;
#endif
}

double& Point::x()
{
	return _x;
}

double& Point::y()
{
	return _y;
}

const double& Point::x() const
{
	return _x;
}


const double& Point::y() const
{
	return _y;
}

const int Point::getID() const
{
	return _pointID;
}

int Point::amount()
{
	return _freeID;
}

Point& Point::operator=(const Point& point)
{
	_x = point.x();
	_y = point.y();
	return *this;
}

ostream& operator<<(ostream& os, const Point& p)
{
	os << "Point(" << p.x() << "," << p.y() << ")";
	return os;
}

const Point operator+(const Point& u, const Point& v)
{
	double x = u.x() + v.x();
	double y = u.y() + v.y();
	return Point(x, y);
}

Point& operator+=(Point& u, const Point& v)
{
	u.x() += v.x();
	u.y() += v.y();
	return u;
}

bool operator==(const Point& u, const Point& v)
{
	return (u.x() == v.x() && u.y() == v.y());
}

bool operator!=(const Point& u, const Point& v)
{
	return !(u == v);
}