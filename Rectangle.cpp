#include "Point.h"
#include "Polygon.h"
#include "Quadrilateral.h"
#include "Rectangle.h"

#include <cmath>

using namespace std;

Rectangle::Rectangle():Quadrilateral(){
    // initialize the shorter and longer sides 
    double side1, side2, dx1, dy1, dx2, dy2;
    dx1 = points[0].getX() - points[1].getX(); // delta x
    dy1 = points[0].getY() - points[1].getY(); // delta y
    side1 = sqrt (dx1 * dx1 + dy1 * dy1); // side length

    dx2 = points[1].getX() - points[2].getX(); // delta x
    dy2 = points[1].getY() - points[2].getY(); // delta y
    side2 = sqrt (dx2 * dx2 + dy2 * dy2); // side length

    if (side1 >= side2){ // return the longer side
        longerSide = side1;
        shorterSide = side2;
    }
    
    else{
        longerSide = side2;
        shorterSide = side1;

    }
}

Rectangle::Rectangle(const Rectangle& other):Quadrilateral(other), shorterSide(other.shorterSide), longerSide(other.longerSide) {
    // initialize the shorter and longer sides in case they weren't already initialized in the original object
    if ((shorterSide == 0) || (longerSide == 0)){
        double side1, side2, dx1, dy1, dx2, dy2;
        dx1 = points[0].getX() - points[1].getX(); // delta x
        dy1 = points[0].getY() - points[1].getY(); // delta y
        side1 = sqrt (dx1 * dx1 + dy1 * dy1); // side length

        dx2 = points[1].getX() - points[2].getX(); // delta x
        dy2 = points[1].getY() - points[2].getY(); // delta y
        side2 = sqrt (dx2 * dx2 + dy2 * dy2); // side length

        if (side1 >= side2){ // return the longer side
            longerSide = side1;
            shorterSide = side2;
        }
        
        else{
            longerSide = side2;
            shorterSide = side1;

        }
    }
}

// Rectangle::~Rectangle(){
//    delete points;
// }

double Rectangle::getLongerSide(){
    // calculate again in case the points have changed
    double side1, side2, dx1, dy1, dx2, dy2;
    dx1 = points[0].getX() - points[1].getX(); // delta x
    dy1 = points[0].getY() - points[1].getY(); // delta y
    side1 = sqrt (dx1 * dx1 + dy1 * dy1); // side length

    dx2 = points[1].getX() - points[2].getX(); // delta x
    dy2 = points[1].getY() - points[2].getY(); // delta y
    side2 = sqrt (dx2 * dx2 + dy2 * dy2); // side length

    if (side1 >= side2){ // return the longer side
        longerSide = side1;
        return longerSide;
    }
    
    longerSide = side2;
    return longerSide;
    
}



double Rectangle::getShorterSide(){
    // calculate again in case the points have changed

    double dx1, dx2, dy1, dy2, side1, side2;
    
    dx1 = points[0].getX() - points[1].getX(); // delta x
    dy1 = points[0].getY() - points[1].getY(); // delta y
    side1 = sqrt (dx1 * dx1 + dy1 * dy1); // side length

    dx2 = points[1].getX() - points[2].getX(); // delta x
    dy2 = points[1].getY() - points[2].getY(); // delta y
    side2 = sqrt (dx2 * dx2 + dy2 * dy2); // side length

    if (side1 >= side2){ // return the shorter side
        shorterSide = side2;
        return shorterSide;
    }
    
    shorterSide = side1;
    return shorterSide;
}

