#include "Trapezoid.h"
#include "Point.h"
#include "Polygon.h"
#include "Quadrilateral.h"
#include <cmath>

using namespace std;

Trapezoid::Trapezoid():Quadrilateral() {
    // initialize sides and angle
    bool side = false;
    // determine which two sides are parallel

    if(((points[1].getY()-points[0].getY())/(points[1].getX() - points[0].getX())) == 
    ((points[3].getY() - points[2].getY())/(points[3].getX() - points[2].getX())))
        side = true;    

    double side1, side2, dx1, dy1, dx2, dy2;
    if (side){ // if the line connecting the first two vertices is parallel to the line connecting the last two vertices
        dx1 = points[0].getX() - points[1].getX(); // delta x
        dy1 = points[0].getY() - points[1].getY(); // delta y
        side1 = sqrt (dx1 * dx1 + dy1 * dy1); // side length

        dx2 = points[3].getX() - points[2].getX(); // delta x
        dy2 = points[3].getY() - points[2].getY(); // delta y
        side2 = sqrt (dx2 * dx2 + dy2 * dy2); // side length

        if (side1 >= side2){ // return the shorter side
            shorterSide = side2;
            longerSide = side1;
        }

        else{
            shorterSide = side1;
            longerSide  = side2;

        }
        
        
    }

    // if the line connecting the second and third vertices is parallel to the line connecting the first and last vertices
    dx1 = points[2].getX() - points[1].getX(); // delta x
    dy1 = points[2].getY() - points[1].getY(); // delta y
    side1 = sqrt (dx1 * dx1 + dy1 * dy1); // side length

    dx2 = points[3].getX() - points[0].getX(); // delta x
    dy2 = points[3].getY() - points[0].getY(); // delta y
    side2 = sqrt (dx2 * dx2 + dy2 * dy2); // side length

    if (side1 >= side2){ // return the shorter side
        shorterSide = side2;
        longerSide = side1;
    }
    else{
        shorterSide = side1;
        longerSide = side2;

    }
} 

// copy constructor
Trapezoid::Trapezoid(const Trapezoid& other) : Quadrilateral(other), shorterSide(other.shorterSide), longerSide(other.longerSide) {
    // initialize sides if they weren't already in the original object
    if ((shorterSide == 0) || (longerSide == 0)){
        bool side = false;
        // determine which two sides are parallel

        if(((points[1].getY()-points[0].getY())/(points[1].getX() - points[0].getX())) == 
        ((points[3].getY() - points[2].getY())/(points[3].getX() - points[2].getX())))
            side = true;    

        double side1, side2, dx1, dy1, dx2, dy2;
        if (side){ // if the line connecting the first two vertices is parallel to the line connecting the last two vertices
            dx1 = points[0].getX() - points[1].getX(); // delta x
            dy1 = points[0].getY() - points[1].getY(); // delta y
            side1 = sqrt (dx1 * dx1 + dy1 * dy1); // side length

            dx2 = points[3].getX() - points[2].getX(); // delta x
            dy2 = points[3].getY() - points[2].getY(); // delta y
            side2 = sqrt (dx2 * dx2 + dy2 * dy2); // side length

            if (side1 >= side2){ // return the shorter side
                shorterSide = side2;
                longerSide = side1;
            }

            else{
                shorterSide = side1;
                longerSide  = side2;

            }
            
            
        }

        // if the line connecting the second and third vertices is parallel to the line connecting the first and last vertices
        dx1 = points[2].getX() - points[1].getX(); // delta x
        dy1 = points[2].getY() - points[1].getY(); // delta y
        side1 = sqrt (dx1 * dx1 + dy1 * dy1); // side length

        dx2 = points[3].getX() - points[0].getX(); // delta x
        dy2 = points[3].getY() - points[0].getY(); // delta y
        side2 = sqrt (dx2 * dx2 + dy2 * dy2); // side length

        if (side1 >= side2){ // return the shorter side
            shorterSide = side2;
            longerSide = side1;
        }
        else{
            shorterSide = side1;
            longerSide = side2;

        }
    }
} 

// Trapezoid::~Trapezoid(){
//    delete points;
// }


double Trapezoid::getShorterSide() {    // recalculate the shorter side in case the points of the object have changed

    bool side = false;
    // determine which two sides are parallel

    if(((points[1].getY()-points[0].getY())/(points[1].getX() - points[0].getX())) == 
    ((points[3].getY() - points[2].getY())/(points[3].getX() - points[2].getX())))
        side = true;    

    double side1, side2, dx1, dy1, dx2, dy2;
    if (side){ // if the line connecting the first two vertices is parallel to the line connecting the last two vertices
        dx1 = points[0].getX() - points[1].getX(); // delta x
        dy1 = points[0].getY() - points[1].getY(); // delta y
        side1 = sqrt (dx1 * dx1 + dy1 * dy1); // side length

        dx2 = points[3].getX() - points[2].getX(); // delta x
        dy2 = points[3].getY() - points[2].getY(); // delta y
        side2 = sqrt (dx2 * dx2 + dy2 * dy2); // side length

        if (side1 >= side2){ // return the shorter side
            shorterSide = side2;
            return shorterSide;
        }
        
        shorterSide = side1;
        return shorterSide;
        
    }

    // if the line connecting the second and third vertices is parallel to the line connecting the first and last vertices
    dx1 = points[2].getX() - points[1].getX(); // delta x
    dy1 = points[2].getY() - points[1].getY(); // delta y
    side1 = sqrt (dx1 * dx1 + dy1 * dy1); // side length

    dx2 = points[3].getX() - points[0].getX(); // delta x
    dy2 = points[3].getY() - points[0].getY(); // delta y
    side2 = sqrt (dx2 * dx2 + dy2 * dy2); // side length

    if (side1 >= side2){ // return the shorter side
        shorterSide = side2;
        return shorterSide;
    }

    shorterSide = side1;
    return shorterSide;



}

double Trapezoid::getLongerSide() {    // recalculate the longer side in case the points of the object have changed

    bool side = false;
    // determine which two sides are parallel

    if(((points[1].getY()-points[0].getY())/(points[1].getX() - points[0].getX())) == 
    ((points[3].getY() - points[2].getY())/(points[3].getX() - points[2].getX())))
        side = true;    

    double side1, side2, dx1, dy1, dx2, dy2;
    if (side){ // if the line connecting the first two vertices is parallel to the line connecting the last two vertices
        dx1 = points[0].getX() - points[1].getX(); // delta x
        dy1 = points[0].getY() - points[1].getY(); // delta y
        side1 = sqrt (dx1 * dx1 + dy1 * dy1); // side length

        dx2 = points[3].getX() - points[2].getX(); // delta x
        dy2 = points[3].getY() - points[2].getY(); // delta y
        side2 = sqrt (dx2 * dx2 + dy2 * dy2); // side length

        if (side1 >= side2){ // return the longer side
            longerSide = side1;
            return longerSide;
        }
        
        longerSide = side2;
        return longerSide;
        
    }

    // if the line connecting the second and third vertices is parallel to the line connecting the first and last vertices
    dx1 = points[2].getX() - points[1].getX(); // delta x
    dy1 = points[2].getY() - points[1].getY(); // delta y
    side1 = sqrt (dx1 * dx1 + dy1 * dy1); // side length

    dx2 = points[3].getX() - points[0].getX(); // delta x
    dy2 = points[3].getY() - points[0].getY(); // delta y
    side2 = sqrt (dx2 * dx2 + dy2 * dy2); // side length

    if (side1 >= side2){ // return the shorter side
        longerSide = side1;
        return longerSide;
    }

    longerSide = side2;
    return longerSide;
}


