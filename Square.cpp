#include "Rectangle.h"
#include "Point2D.h"
#include "Square.h"
#include <cmath>
#include <ostream>

bool Square::check(Point2D* vertices){
	return Point2D::distance(vertices[0], vertices[1]) == Point2D::distance(vertices[1], vertices[2]);
}
Square::Square(){
	color = "red";
	vs = new Point2D[N_VERTICES];
	vs[0] = Point2D(-1.0, 1.0);
	vs[1] = Point2D(1.0, 1.0);
	vs[2] = Point2D(1.0, -1.0);
	vs[3] = Point2D(-1.0, -1.0);
}
Square::Square(std::string color, Point2D* vertices){
	if(check(vertices) == true){
		for(int i = 0; i < N_VERTICES; i++){
			vs[i].x = vertices[i].x;
			vs[i].y = vertices[i].y;
		}
		this->color = color;
	}
	else{
		throw std::invalid_argument("No es un cuadrado");
	}
}
void Square::set_vertices(Point2D* vertices){
	if(check(vertices) == true){
		for(int i = 0; i < N_VERTICES; i++){
			vs[i] = vertices[i];
		}
	}
	else{
		throw std::invalid_argument("No es un cuadrado");
	}
}
std::ostream& operator<<(std::ostream& out, const Square &square){
	return out << " vertice 1: " << square.vs[0] <<" vertice 2: " << square.vs[1] <<" vertice 3: " << square.vs[2] <<" vertice 4: " << square.vs[3] << " color: " << square.color << " area: " << square.area();
}
void Square::print(){
	std::cout << " vertice 1: " << vs[0] <<" vertice 2: " << vs[1] <<" vertice 3: " << vs[2] <<" vertice 4: " << vs[3] << " color: " << color << " area: " << area() << std::endl;
}
 
