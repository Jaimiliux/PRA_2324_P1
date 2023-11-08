#include <iostream>
#include "Shape.h"
#include <ostream>
#include "Point2D.h"
#include "Circle.h"

		Circle::Circle(){
			color = "red";
			radius = 1;
			center.x = 0.0;
			center.y = 0.0;
		}
		Circle::Circle(std::string color, Point2D center, double radius){
			this->color = color;
			this->center = center;
			this->radius = radius;
		}
		Circle::Circle(Point2D center, double radius){
			color = "red";
			this->center = center;
			this->radius = radius;
		}
		Point2D Circle::get_center() const{
			return center;
		}
		void Circle::set_center(Point2D p){
			center = p;
		}
		double Circle::get_radius() const{
			return radius;
		}
		void Circle::set_radius(double r){
			radius = r;
		}
		std::ostream& operator<<(std::ostream &out, const Circle &c){
			return out << "radio: " << c.radius << " color: " << c.color << " cordX: " << c.center.x << " cordY: " << c.center.y << std::endl;
		}
		double Circle::area() const{
			return 3.141592 * radius * radius;
		}
		double Circle::perimeter() const{
			return 3.141592 * (radius * 2);
		}
		void Circle::translate(double incX, double incY){
			center.x += incX;
			center.y += incY;
		}
		void Circle::print(){
			std::cout << "radio: " << radius << " color: " << color << " cordX: " << center.x << " cordY: " << center.y << std::endl;
		}
				
