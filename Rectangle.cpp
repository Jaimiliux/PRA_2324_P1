#include "Rectangle.h"
#include "Point2D.h"
#include <cmath>
#include <ostream>
bool Rectangle::check(Point2D* vertices){
	return sqrt(pow(Point2D::distance(vertices[0], vertices[1]),2)) == sqrt(pow(Point2D::distance(vertices[2], vertices[3]),2));
}
Rectangle::Rectangle(){
	color = "red";
	vs = new Point2D[N_VERTICES];
	vs[0] = Point2D (-1.0,0.5);
	vs[1] = Point2D (1.0,0.5);
	vs[2] = Point2D (1.0,-0.5);
	vs[3] = Point2D (-1.0,-0.5);
}
Rectangle::Rectangle(std::string color, Point2D* vertices){
	this->color = color;
	if(((Point2D::distance(vertices[0], vertices[1]),2)) == sqrt(pow(Point2D::distance(vertices[2], vertices[3]),2))){
		vs = vertices;
	}
	else{
		throw std::invalid_argument("No es un rectangulo");
	}
}
Rectangle::Rectangle(const Rectangle &r){
	vs = new Point2D[N_VERTICES];
	for( int i = 0; i < N_VERTICES; i++){	
	vs[i] = r.vs[i];
	}
	color = r.color;
}
Rectangle::~Rectangle(){
	delete[] vs;
}
Point2D Rectangle::get_vertex(int ind) const{
	if(ind >= 0 && ind < N_VERTICES){
		return vs[ind];
	}
	else{
		throw std::out_of_range("Fuera del intervalo de vertices del rectangulo");
	}
}
Point2D Rectangle::operator[](int ind) const{
	if(ind >= 0 && ind < N_VERTICES){
		return vs[ind];
	}
	else{
		throw std::invalid_argument("No es un rectangulo");
	}
}
void Rectangle::set_vertices(Point2D* vertices){
	if(check(vertices)){
		vs = vertices;
	}
	else{
		throw std::invalid_argument("No es un rectangulo");
	}
}
Rectangle& Rectangle::operator=(const Rectangle &r){
	delete[] vs;
	this->color = r.color;
	this->vs = r.vs;
	return *this;
}
std::ostream& operator<<(std::ostream &out, const Rectangle &r){
	out << "vertice 1: " << r.vs[0] << " vertice 2:" << r.vs[1] << " vertice 3: " << r.vs[2] << " vertice 4: " << r.vs[3] << " color: " << r.color << std::endl;
	return out;
}

double Rectangle::area() const{
	return Point2D::distance(vs[0],vs[1]) * Point2D::distance(vs[1], vs[2]);
}

double Rectangle::perimeter() const{
	return 2 * Point2D::distance(vs[0], vs[1]) + 2 * Point2D::distance(vs[1], vs[2]);
}
void Rectangle::translate(double incX, double incY){
	vs[0] = Point2D(vs[0].x + incX, vs[0].y + incY);
	vs[1] = Point2D(vs[1].x + incX, vs[1].y + incY);
	vs[2] = Point2D(vs[2].x + incX, vs[2].y + incY);
	vs[3] = Point2D(vs[3].x + incX, vs[3].y + incY);
}
void Rectangle::print(){
	std::cout << " vertice 1: " << vs[0] << " vertice 2: " << vs[1] << " vertice 3: " << vs[2] << " vertice 4: " << vs[3] << " color: " << color << " area: " << area() << std::endl;
}

