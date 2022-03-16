#include "AComplex.h"
#include "TComplex.h"
using namespace std;
#define NDEBUG

int TComplex::_freeId = 0;

TComplex::TComplex(double ro, double phi) : _ro(ro), _phi(phi), _id(++_freeId)
{
#ifndef NDEBUG
	cout << "Created TComplex " << *this << ", id = " << _id << endl;
#endif 
}


TComplex::TComplex(const TComplex& tCmpl) : _ro(tCmpl.mod()), _phi(tCmpl.arg()), _id(++_freeId)
{
#ifndef NDEBUG
	cout << "Copied AComplex " << *this << ", id = " << _id << endl;
#endif 
}


TComplex::TComplex(const AComplex& aCmpl) : _ro(aCmpl.mod()), _phi(aCmpl.arg()), _id(++_freeId)
{
#ifndef NDEBUG
	cout << "TComplex " << *this << ", id = " << _id << ", created from AComplex " << endl;
#endif 
}


TComplex::~TComplex()
{
#ifndef NDEBUG
	cout << "Deleted TAComplex, id = " << _id << ": " << *this << endl;
#endif 
}


TComplex& TComplex::operator=(const TComplex& tCmpl)
{
	if (this == &tCmpl)
		return *this;
	_ro = tCmpl.mod();
	_phi = tCmpl.arg();
	return *this;
}


double& TComplex::mod()
{
	return _ro;
}


double& TComplex::arg()
{
	return _phi;
}


const double& TComplex::mod() const
{
	return _ro;
}


const double& TComplex::arg() const
{
	return _phi;
}


double TComplex::re() const
{
	return _ro * cos(_phi);
}


double TComplex::im() const
{
	return _ro * sin(_phi);
}


const int TComplex::getID() const
{
	return _id;
}


TComplex& operator*=(TComplex& a, const TComplex& b)
{
	a.mod() *= b.mod();
	a.arg() += b.arg();
	return a;
}


TComplex& operator/=(TComplex& a, const TComplex& b)
{
	a.mod() /= b.mod();
	a.arg() -= b.arg();
	return a;
}


const TComplex operator* (const TComplex& a, const TComplex& b)
{
	TComplex res(a);
	return res *= b;
}


const TComplex pow(const TComplex& a, unsigned int n)
{
	double ro = pow(a.mod(), n);
	double phi = a.arg() * n;
	return TComplex(ro, phi);
}


const TComplex operator/ (const TComplex& a, const TComplex& b)
{
	TComplex res(a);
	return res /= b;
}


bool operator== (const TComplex& a, const TComplex& b)
{
	return (a.re() == b.re() && a.im() == b.im());
}


bool operator!=(const TComplex& a, const TComplex& b)
{
	return !(a == b);
}


ostream& operator<<(ostream& os, const TComplex& tCmpl)
{
	return os << '(' << tCmpl.mod() << "(cos(" << tCmpl.arg() << ")" << " + isin(" << tCmpl.arg() << "))";
}