#ifndef POINT2D_H
#define POINT2D_H
#include <cmath>
#include <ostream>

class Point2D{
	public:
		double x;
		double y;
		Point2D(int x=0, int y=0);
		static double distance(const Point2D &a, const Point2D &b){
			return sqrt((pow(a.x,2) -2*a.x*b.x + pow(b.x,2)) + (pow(a.y,2) -2*a.y*b.y + pow(b.y,2)));
		}
	        bool operator==(const Point2D&);
		bool operator!=(const Point2D &);
		std::ostream& operator<<(std::ostream &out);
		

						
	      
	     };
	bool operator==(const Point2D &a, const Point2D &b){
		return a.x == b.x && a.y == b.y;
	}
	bool operator!=(const Point2D &a, const Point2D &b){
		return a.x != b.x || a.y == b.y;
	}
	std::ostream& operator<<(std::ostream &out, const Point2D &p){
		out << p.x << " " << p.y << std::endl;
		return out;
	}

	
#endif
