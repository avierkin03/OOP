#include "Segment.h"
#include <cassert>
using namespace std;

int Segment::_freeID = 0;


Segment::Segment(const double x1, const double y1,const double x2, const double y2):_a(x1, y1), _b(x2, y2), _myId(++_freeID)
{
#ifndef NDEBUG
	cout << "Creating Segment " << *this  << " id = " << _myId << endl;
#endif
	return;
}


Segment::Segment(const Point& start, const Point& end):_a(start), _b(end), _myId(++_freeID)
{
#ifndef NDEBUG
	cout << "Creating Segment " << *this << " with id = " << _myId << endl;
#endif
	return;
}


Segment::Segment(const Segment& u):_a(u._a), _b(u._b), _myId(++_freeID)
{
#ifndef NDEBUG
	cout << "Segment: " << *this << " with ID: " << _myId << " has been copied." << endl;
#endif
	return;
}


Segment::~Segment()
{
#ifndef NDEBUG
	cout << "Deletion " << *this << " id = " << _myId << endl;
#endif
	return;
}


Segment& Segment::operator=(const Segment& sgm)
{
	_a = sgm._a;
	_b = sgm._b;
	return *this;
}


const Point& Segment::start() const
{
	return _a;
}


const Point& Segment::end() const
{
	return _b;
}


Point& Segment::start()
{
	return _a;
}


Point& Segment::end()
{
	return _b;
}


double& Segment::startX()
{
	return const_cast<double&>(start().x());
}


double& Segment::startY()
{
	return const_cast<double&>(start().y());
}


double& Segment::endX()
{
	return const_cast<double&>(end().x());
}


double& Segment::endY()
{
	return const_cast<double&>(end().y());
}


double Segment::length() const
{
	return sqrt((_a.x() - _b.x())*(_a.x() - _b.x()) + (_a.y() - _b.y())*(_a.y() - _b.y()));
}


double Segment::distance(const Point& point) const
{
	double A = (_a.x() == _b.x() ? 0 : 1 / (_b.x() - _a.x()));
	double B = (_b.y() == _a.y() ? 0 : 1 / (_a.y() - _b.y()));
	double C = -_a.x() * A - _a.y() * B;
	assert((A != 0) || (B != 0));
	if (B == 0)
		return fabs(-C / A - point.y());
	if (A == 0)
		return fabs(-C / B - point.x());
	return fabs((A * point.x() + B * point.y() + C) / sqrt(A * A + B * B));
}


const int Segment::getID() const
{
	return _myId;
}


const double& Segment::startX() const
{
	return _a.x();
}


const double& Segment::startY() const
{
	return _a.y();
}


const double& Segment::endX() const
{
	return _b.x();
}


const double& Segment::endY() const
{
	return _b.y();
}


ostream& operator<<(ostream& os, const Segment& sgm)
{
	os << "Segment [" << sgm.start() << ',' << sgm.end() << ']';
	return os;
}

