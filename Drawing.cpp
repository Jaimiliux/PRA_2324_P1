#include <ostream>
#include "Drawing.h"
#include <iostream>
#include "Node.h"
#include "Square.h"
#include "Circle.h"
#include "Rectangle.h"

Drawing::Drawing(){
	shapes = new ListLinked<Shape*>();
}
Drawing::~Drawing(){
	delete shapes;
}
void Drawing::add_front(Shape* shape){
	shapes->insert(0, shape);
}
void Drawing::add_back(Shape* shape){
	shapes->insert(shapes->size(),shape);
}
void Drawing::print_all(){
	/*Node<Shape*>* aux = shapes->get_head();
	Shape* shape;
	for(int i = 0; i < shapes->size(); i++){
		aux = shapes->get_pos(i);
		shape = aux->data;
		shape->print();
	}*/
	for(int i = 0; i < shapes->size(); i++){
		if(Circle* c = dynamic_cast<Circle*>(shapes->get(i))){
			c->print();
		}
		else if(Square* sq = dynamic_cast<Square*>(shapes->get(i))){
			sq->print();
		}
		else if(Rectangle* r = dynamic_cast<Rectangle*>(shapes->get(i))){
			r->print();
		}
	}
}
double Drawing::get_area_all_circles(){
	/*for(int i = 0; i < shapes->size(); i++){
		aux = shapes->get_pos(i);*/
	/*for(Shape* shape : shapes){
	        if(Circle* c = dynamic_cast<Cirecle*>(shape)){
			arec += circle->get_area();*/
		/*Shape* shape = aux->data;
		if (Circle* circle = dynamic_cast<Circle*>(shape)){
			areac += circle->area();
		}
	}*/
	double areac = 0;
	for(int i = 0; i < shapes->size(); i++){
		if(Circle* c = dynamic_cast<Circle*>(shapes->get(i))){
			areac+= c->area();
		}
	}
	return areac;
}
void Drawing::move_squares(double incX, double incY){
	/*for(int i = 0; i < shapes->size(); i++){
		aux = shapes->get_pos(i);
		shape = aux->data;
		if (Square* rectangle = dynamic_cast<Square*>(shape)){
			rectangle->translate(incX, incY);
		}
	}*/
	for(int i = 0; i < shapes->size(); i++){
		if(Square* rectangle = dynamic_cast<Square*>(shapes->get(i))){
			rectangle->translate(incX, incY);
		}
	}
}
