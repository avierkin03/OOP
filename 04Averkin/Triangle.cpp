#include "Triangle.h"
#include <cassert>
#define NDEBUG

Triangle::Triangle(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3) :
	_a(x1, y1), _b(x2, y2), _c(x3, y3),
	_ab(nullptr), _bc(nullptr), _ca(nullptr)
{
	assert(square() != 0);
#ifndef NDEBUG
	cout << "Created: " << *this << endl;
#endif
}


Triangle::Triangle(const Point& a, const Point& b, const Point& c):
	_a(a), _b(b), _c(c),_ab(nullptr), _bc(nullptr), _ca(nullptr)
{
	assert(square() != 0);
#ifndef NDEBUG
	cout << "Created: " << *this << endl;
#endif
	return;
}


Triangle::Triangle(const Point& a, const Segment& bc) :
	_a(a), _b(bc.start()), _c(bc.end()), _ab(nullptr), _bc(nullptr), _ca(nullptr)
{
	assert(square() != 0);
#ifndef NDEBUG
	cout << "Created: " << *this << endl;
#endif
	return;
}


Triangle::Triangle(const Triangle& tr) :
	_a(tr.apexA()), _b(tr.apexB()), _c(tr.apexC()), _ab(nullptr), _bc(nullptr), _ca(nullptr)
{
#ifndef NDEBUG
	cout << "Copied: " << *this << std::endl;
#endif
	return;
}


Triangle::~Triangle()
{
	if (_ab != nullptr) delete _ab;	
	if (_bc != nullptr) delete _bc;
	if (_ca != nullptr) delete _ca;
#ifndef NDEBUG
	cout << "Deleted: " << *this << std::endl;
#endif
};


Triangle& Triangle::operator=(const Triangle& tr) {
	_a = tr.apexA();
	_b = tr.apexB();
	_c = tr.apexC();
	if (_ab != nullptr)
		delete _ab;
	if (_bc != nullptr)
		delete _bc;
	if (_ca != nullptr)
		delete _ca;
	_ab = _bc = _ca = nullptr;
	return *this;
}


const Point& Triangle::apexA() const {
	return _a;
}


const Point& Triangle::apexB() const {
	return _b;
}


const Point& Triangle::apexC() const {
	return _c;
}


const Segment& Triangle:: side_a() const
{
	if (_bc == nullptr)
		_bc = new Segment(_b, _c);
	return *_bc;
}


const Segment& Triangle::side_b() const {
	if (_ca == nullptr)
		_ca = new Segment(_c, _a);
	return *_ca;
}


const Segment& Triangle::side_c() const {
	if (_ab == nullptr)
		_ab = new Segment(_a, _b);
	return *_ab;
}


double Triangle::square() const
{
	return 0.5 * side_a().length() * side_a().distance(_a);
}


double Triangle::length_a() const {
	return side_a().length();
}


double Triangle::length_b() const {
	return side_b().length();
}


double Triangle::length_c() const {
	return side_c().length();
}


double Triangle::getMiddle(const double x, const double y) const 
{
	return (x + y) / 2;
}


const Segment Triangle:: median_a() const 
{
	return Segment(apexA(), Point(getMiddle(_b.x(), _c.x()), getMiddle(_b.y(), _c.y())));;
}


const Segment Triangle::median_b() const 
{
	return Segment(apexB(), Point(getMiddle(_a.x(), _c.x()), getMiddle(_a.y(), _c.y())));;
}


const Segment Triangle::median_c() const 
{
	return Segment(apexC(), Point(getMiddle(_a.x(), _b.x()), getMiddle(_a.y(), _b.y())));
}


ostream& operator<<(std::ostream& os, const Triangle& t)
{
	return os << "Triangle {" << t.apexA() << ' ' << t.apexB() << ' ' << t.apexC() << "}";
}


