#include "Quadrilateral.h"
#include "Point.h"
#include "Polygon.h"

Quadrilateral::Quadrilateral():Polygon(4){} // force size 4

Quadrilateral::Quadrilateral(const Quadrilateral& other):Polygon(other){}

//Quadrilateral::~Quadrilateral(){
  //  delete points;
//}

// we don't need the code below, since they're already inherited from Polygon class

// void Quadrilateral::setPoint(int index, const Point& p){
//    Polygon::setPoint(index, p);
// }

// void Quadrilateral::setPoint(int index, double X, double Y){
//   Polygon::setPoint(index, X, Y);
// }

// double Quadrilateral::area() const{
//    return Polygon::area();
// }