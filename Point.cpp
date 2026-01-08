#include "Point.h"

Point::Point():x(0), y(0){} // default constructor

Point::Point(double X, double Y):x(X), y(Y){} // parameter constructor

Point::Point(const Point& other):x(other.x), y(other.y){} // copy constructor

// Point::~Point(){

// }

double Point::getX() const{
    return x;
}

double Point::getY() const{
    return y;
}

void Point::setX(double X){
    x = X;
}

void Point::setY(double Y){
    y = Y;
}

