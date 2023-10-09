#ifndef POINT2D_H
#define POINT2D_H
#include <cmath>
#include <ostream>

class Point2D{
	public:
		double x;
		double y;
		Point2D(int x, int y);
		static double distance(const Point2D &a, const Point2D &b);
	        friend bool operator==(const Point2D&, const Point2D&);
		friend bool operator!=(const Point2D&, const Point2D&);
		friend std::ostream& operator<<(std::ostream &out, const Point2D &p);
	     };
	
#endif
