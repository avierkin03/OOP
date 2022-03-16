#pragma once
#include <iostream>
using namespace std;

class TComplex;
class AComplex
{
private:
	double _re, _im;
	static int _freeId;
	int _id;
public:
	AComplex(double re = 0, double im = 0);
	AComplex(const TComplex&);
	AComplex(const AComplex&);
	~AComplex();
	AComplex& operator= (const AComplex&);
	double& re();
	double& im() ;
	const double& re() const;
	const double& im() const;
	double mod() const;
	double arg() const;
	const int getID() const;
};
AComplex& operator+=(AComplex&, const AComplex&);
AComplex& operator+=(const double x, AComplex& a);
AComplex& operator-=(AComplex&, const AComplex&);
AComplex& operator-=(double x, AComplex& a);
const AComplex operator+ (const AComplex&, const AComplex&);
const AComplex operator- (const AComplex&, const AComplex&);
bool operator== (const AComplex&, const AComplex&);
bool operator!= (const AComplex&, const AComplex&);
ostream& operator<<(ostream&, const AComplex&);