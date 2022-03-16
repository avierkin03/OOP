#pragma once
#include "Segment.h"
#include "Point.h"
#include <fstream>

class Point;
class Segment;

class Triangle
{
private:
	Point _a, _b, _c;
	mutable Segment* _ab, * _bc, * _ca;
	double getMiddle(const double x, const double y) const;
public:
	Triangle(const double x1 = 0, const double y1 = 0, const double x2 = 1, const double y2 = 0, const double x3 = 0, const double y3 = 1);
	Triangle(const Point& a, const Point& b, const Point& c);
	Triangle(const Point& a, const Segment& _bc);
	Triangle(const Triangle&);
	~Triangle();

	double square() const;
	Triangle& operator= (const Triangle&);

	const Point& apexA() const;
	const Point& apexB() const;
	const Point& apexC() const;

	const Segment& side_a() const;
	const Segment& side_b() const;
	const Segment& side_c() const;

	double length_a() const;
	double length_b() const;
	double length_c() const;

	const Segment median_a() const;
	const Segment median_b() const;
	const Segment median_c() const;
};

ostream& operator<<(ostream&, const Triangle&);