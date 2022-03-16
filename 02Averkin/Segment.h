#pragma once
#include "Point.h"

class Segment
{
private:
	static int _freeID;
	const int _myId;
	Point _a;
	Point _b;

public:
	Segment(const double x1 = 0, const double y1 = 0,const double x2 = 1, const double y2 = 0);
	Segment(const Point& start, const Point& end);
	Segment(const Segment&);
	~Segment();
	Segment& operator=(const Segment&);
	const Point& start() const;
	const Point& end() const;
	Point& start();
	Point& end();
	const double& startX() const;
	const double& startY() const;
	const double& endX() const;
	const double& endY() const;
	double& startX();
	double& startY();
	double& endX();
	double& endY();
	double length() const;
	double distance(const Point&) const;
	const int getID() const;
};

ostream& operator<<(ostream&, const Segment&);