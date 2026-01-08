#include "Quadrilateral.h"
#include "Point.h"
#include "Polygon.h"
#include "Parallelogram.h"
#include <cmath>

using namespace std;

Parallelogram::Parallelogram():Quadrilateral() {
    // initialize shorter and longer sides and acute angle
    double dx1, dx2, dy1, dy2, side1, side2;
    
    dx1 = points[0].getX() - points[1].getX(); // delta x
    dy1 = points[0].getY() - points[1].getY(); // delta y
    side1 = sqrt (dx1 * dx1 + dy1 * dy1); // side length

    dx2 = points[1].getX() - points[2].getX(); // delta x
    dy2 = points[1].getY() - points[2].getY(); // delta y
    side2 = sqrt (dx2 * dx2 + dy2 * dy2); // side length

    if (side1 >= side2){ 
        shorterSide = side2;
        longerSide = side1;
        
    }
    
    else{
        shorterSide = side1;
        longerSide = side2;

    }

    double dot = dx1*dx2 + dy1*dy2;
    double cosTheta = dot / (side1 * side2);

    // Clamp to [-1,1] to avoid NaNs from small floating errors
    if (cosTheta > 1.0) cosTheta = 1.0;
    if (cosTheta < -1.0) cosTheta = -1.0;

    const double PI = acos(-1.0);
    double angle = acos(cosTheta); // angle in [0, pi]

    // Convert to acute angle if it's obtuse
    if (angle > PI/2.0) angle = PI - angle;

    acuteAngle = angle;
    
}


Parallelogram::Parallelogram(const Parallelogram& other):Quadrilateral(other), shorterSide(other.shorterSide), 
longerSide(other.longerSide), acuteAngle(other.acuteAngle) {
     // initialize shorter and longer sides and acute angle in case they weren't already in the original object
     if ((shorterSide == 0) || (longerSide == 0) ) {
        double dx1, dx2, dy1, dy2, side1, side2;
        
        dx1 = points[0].getX() - points[1].getX(); // delta x
        dy1 = points[0].getY() - points[1].getY(); // delta y
        side1 = sqrt (dx1 * dx1 + dy1 * dy1); // side length

        dx2 = points[1].getX() - points[2].getX(); // delta x
        dy2 = points[1].getY() - points[2].getY(); // delta y
        side2 = sqrt (dx2 * dx2 + dy2 * dy2); // side length

        if (side1 >= side2){ 
            shorterSide = side2;
            longerSide = side1;
            
        }
        
        else{
            shorterSide = side1;
            longerSide = side2;

        }

        double dot = dx1*dx2 + dy1*dy2;
        double cosTheta = dot / (side1 * side2);


        const double PI = acos(-1.0);
        double angle = acos(cosTheta); // angle in [0, pi]

        // Convert to acute angle if it's obtuse
        if (angle > PI/2.0) angle = PI - angle;

        acuteAngle = angle;
     }
}

// Parallelogram::~Parallelogram(){
//    delete[] points;
// }

double Parallelogram::getShorterSide() { // recalculate in case the points have changed

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

double Parallelogram::getLongerSide() { // recalculate if the points have changed
        

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



double Parallelogram::getAcuteAngleInRadian() { // recalculate angle in case the points have changed
    
    double dx1 = points[1].getX() - points[0].getX();
    double dy1 = points[1].getY() - points[0].getY();
    double dx2 = points[3].getX() - points[0].getX();
    double dy2 = points[3].getY() - points[0].getY();

    double mag1 = sqrt(dx1*dx1 + dy1*dy1);
    double mag2 = sqrt(dx2*dx2 + dy2*dy2);

    // Guard against degenerate (zero-length) edges
    if (mag1 == 0.0 || mag2 == 0.0) {
        acuteAngle = 0.0; 
        return acuteAngle;
    }

    double dot = dx1*dx2 + dy1*dy2;
    double cosTheta = dot / (mag1 * mag2);

    

    const double PI = acos(-1.0);
    double angle = acos(cosTheta); // angle in [0, pi]

    // Convert to acute angle if it's obtuse
    if (angle > PI/2.0) angle = PI - angle;

    acuteAngle = angle;
    return acuteAngle;
}

