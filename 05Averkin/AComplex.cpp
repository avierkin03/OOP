#include "AComplex.h"
#include "TComplex.h"
using namespace std;
#define NDEBUG

int AComplex::_freeId = 0;

AComplex::AComplex(double re, double im) : _re(re), _im(im), _id(++_freeId) {
#ifndef NDEBUG
    std::cout << "Created AComplex " << *this <<", id = " << _id << endl;
#endif
    return;
}


AComplex::AComplex(const AComplex& aCmpl) : _re(aCmpl.re()), _im(aCmpl.im()), _id(++_freeId)
{
#ifndef NDEBUG
	std::cout << "Copied AComplex "<< *this <<", id = " << _id << endl;
#endif
	return;
}


AComplex::AComplex(const TComplex& tCmpl) :_re(tCmpl.re()), _im(tCmpl.im()), _id(++_freeId)
{
#ifndef NDEBUG
	std::cout << "AComplex " << *this << ", id = " << _id << ", created from TComplex " << endl;
#endif
}


AComplex::~AComplex() {
#ifndef NDEBUG
	std::cout << "Deleted AComplex " << *this << ", id = " << _id << endl;
#endif
}

AComplex& AComplex::operator=(const AComplex& aCompl)
{
	if (this == &aCompl)
		return *this;
	im() = aCompl.im();
	re() = aCompl.re();
	return *this;
}


double& AComplex::re()
{
	return _re;
}


double& AComplex::im()
{
	return _im;
}


const double& AComplex::re() const
{
	return _re;
}


const double& AComplex::im() const
{
	return _im;
}


double AComplex::mod() const
{
	return sqrt(_re * _re + _im * _im);
}


double AComplex::arg() const
{
	return atan(_im / _re);
}


const int AComplex::getID() const
{
	return _id;
}


AComplex& operator+=(AComplex& a, const AComplex& b) 
{
	a.re() += b.re();
	a.im() += b.im();
	return a;
}


AComplex& operator+=(const double x, AComplex& a)
{
	a.re() += x;
	return a;
}


AComplex& operator-= (AComplex& a, const AComplex& b)
{
	a.re() -= b.re();
	a.im() -= b.im();
	return a;
}


AComplex& operator-=(double x, AComplex& a)
{
	x -= a.re();
	a.re() = x;
	return a;
}


const AComplex operator+(const AComplex& a, const AComplex& b)
{
	AComplex res(a);
	return res += b;
}


const AComplex operator-(const AComplex& a, const AComplex& b)
{
	AComplex res(a);
	return res -= b;
}


bool operator== (const AComplex& a, const AComplex& b)
{
	return (a.re() == b.re() && a.im() == b.im());
}


bool operator!=(const AComplex& a, const AComplex& b)
{
	return !(a == b);
}


ostream& operator<<(ostream& os, const AComplex& aCmpl)
{
	return os << "(" << aCmpl.re() << (aCmpl.im() >= 0 ? "+" : "") << aCmpl.im() << "i)";
}