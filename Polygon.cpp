#include "Point.h"
#include "Polygon.h"
#include <stdexcept>
using namespace std;

Polygon::Polygon(int s):size(s), points(new Point[s]) {} // default constructor

Polygon::Polygon(const Polygon& other):size(other.size), points(new Point[size]){ // copy constructor
    for (int i = 0; i < size; i ++)
        points[i] = other.points[i];
}


Polygon::~Polygon(){ // destructor
    delete[] points;
}

void Polygon::setPoint(int index, const Point& p){
    if(index>=size)
        throw invalid_argument("the index should be smaller than the size of the polygon!");

    points[index].setX(p.getX());
    points[index].setY(p.getY());
}

void Polygon::setPoint(int index, double x, double y){
    if(index>=size)
        throw invalid_argument("the index should be smaller than the size of the polygon!");

    points[index].setX(x);
    points[index].setY(y);
}

double Polygon::area() const{
    double a = 0.0;
    for (int i = 0; i < size-1; i++)
        a+=(points[i].getX() * points[i+1].getY() - points[i].getY() * points[i+1].getX());
    a+=points[size-1].getX() * points[0].getY() - points[size-1].getY() * points[0]. getX();

    if(a<0.0)
        return -a/2.0; // absolute value of area

    return a/2.0;
}