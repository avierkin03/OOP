#pragma once
#include <iostream>
using namespace std;

class AComplex;
class TComplex
{
private:
	double _ro, _phi;
	static int _freeId;
	int _id;
public:
	TComplex(double ro = 0, double phi = 0);
	TComplex(const TComplex&);
	TComplex(const AComplex&);
	~TComplex();
	TComplex& operator= (const TComplex&);
	double& mod();
	double& arg();
	const double& mod() const;
	const double& arg() const;
	double re() const;
	double im() const;
	const int getID() const;
};
TComplex& operator*=(TComplex& a, const TComplex& b);
TComplex& operator/=(TComplex& a, const TComplex& b);
const TComplex operator* (const TComplex&, const TComplex&);
const TComplex pow(const TComplex&, unsigned int);
const TComplex operator/ (const TComplex&, const TComplex&);
bool operator== (const TComplex& a, const TComplex& b);
bool operator!= (const TComplex&, const TComplex&);
ostream& operator<<(std::ostream&, const TComplex&);
