#include "Point2D.h"
#include <ostream>
#include <cmath>

	Point2D::Point2D(int x=0, int y=0) : x(x), y(x) {}
	bool operator==(const Point2D &a, const Point2D &b){
		return a.x == b.x && a.y == b.y;
	}
	bool operator!=(const Point2D &a, const Point2D &b){
		return a.x != b.x || a.y != b.y;
	}
	std::ostream& operator<<(std::ostream &out, const Point2D &p){
		out << p.x << " " << p.y << std::endl;
		return out;
	}
	double Point2D::distance(const Point2D &a, const Point2D &b){
			return sqrt((pow(a.x,2) -2*a.x*b.x + pow(b.x,2)) + (pow(a.y,2) -2*a.y*b.y + pow(b.y,2)));
	}
