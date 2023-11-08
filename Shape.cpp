#include "Shape.h"

Shape::Shape(){
	color = "red";
}

Shape::Shape(std::string color){
	this->color = color;
	if(this->color != "red" || "green" || "blue"){
		throw std::invalid_argument("color no valido");
	}
}

std::string Shape::get_color() const{
	return color;
}

void Shape::set_color(std::string c){
	if(c == "red" || "green" || "blue"){
		color = c;
	}
	else{
	throw std::invalid_argument("color no valido");
	}
}

