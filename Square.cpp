#include "Point.h"
#include "Polygon.h"
#include "Quadrilateral.h"
#include "Square.h"
#include <cmath>

using namespace std;

Square::Square():Quadrilateral() {
    // initialize side
    double dx = points[1].getX() - points[0].getX();
    double dy = points[1].getY() - points[0].getY();
    side = sqrt(dx*dx + dy*dy);
}

Square::Square(const Square& other):Quadrilateral(other), side(other.side) {  // initialize side if it wasn't already in the original object

    if (side == 0){
        double dx = points[1].getX() - points[0].getX();
        double dy = points[1].getY() - points[0].getY();
        side = sqrt(dx*dx + dy*dy);
    }
}

// Square::~Square(){
//    delete[] points;
// }

double Square::getSide() { // recalculate the side length in case the point coordinates have changed
    double dx = points[1].getX() - points[0].getX();
    double dy = points[1].getY() - points[0].getY();
    side = sqrt(dx*dx + dy*dy);
    return side;
}

