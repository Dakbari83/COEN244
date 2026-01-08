#include "Point.h"
#include "Polygon.h"
#include "Quadrilateral.h"
#include "Rhombus.h"

#include <cmath>

using namespace std;

Rhombus::Rhombus():Quadrilateral(){
    // initliaze side and angle
    double dx = points[1].getX() - points[0].getX();
    double dy = points[1].getY() - points[0].getY();
    side = sqrt(dx*dx + dy*dy);
    double bx = points[3].getX() - points[0].getX();
    double by = points[3].getY() - points[0].getY();

    double magA = sqrt(dx*dx + dy*dy);
    double magB = sqrt(bx*bx + by*by);

    double dot = dx*bx + dy*by; // calculate dot product
    double cosTheta = dot / (magA * magB);
    if (cosTheta > 1.0) cosTheta = 1.0; // just to prevent potential errors
    if (cosTheta < -1.0) cosTheta = -1.0;

    double angle = acos(cosTheta);
    const double PI = acos(-1.0);
    if (angle > PI/2.0) angle = PI - angle; // get acute angle
    acuteAngle = angle;
}

Rhombus::Rhombus(const Rhombus& other):Quadrilateral(other), side(other.side), acuteAngle(other.acuteAngle) { // copy constructor
    // initialize side and angle in case they weren't already in the original object
    if (side == 0){
        double dx = points[1].getX() - points[0].getX();
        double dy = points[1].getY() - points[0].getY();
        side = sqrt(dx*dx + dy*dy);
        double bx = points[3].getX() - points[0].getX();
        double by = points[3].getY() - points[0].getY();

        double magA = sqrt(dx*dx + dy*dy);
        double magB = sqrt(bx*bx + by*by);

        double dot = dx*bx + dy*by; // calculate dot product
        double cosTheta = dot / (magA * magB);
        if (cosTheta > 1.0) cosTheta = 1.0; // just to prevent potential errors
        if (cosTheta < -1.0) cosTheta = -1.0;

        double angle = acos(cosTheta);
        const double PI = acos(-1.0);
        if (angle > PI/2.0) angle = PI - angle; // get acute angle
        acuteAngle = angle;
    }
}

// Rhombus::~Rhombus(){
//    delete[] points;
// }

double Rhombus::getSide() { // recalculate side in case the points have changed
    double dx = points[1].getX() - points[0].getX();
    double dy = points[1].getY() - points[0].getY();
    side = sqrt(dx*dx + dy*dy);
    return side;
}

double Rhombus::getAngle() { // recalculate angle in case the points have changed
    // vector a = points[1] - points[0]
    double ax = points[1].getX() - points[0].getX();
    double ay = points[1].getY() - points[0].getY();
    // vector b = points[3] - points[0]
    double bx = points[3].getX() - points[0].getX();
    double by = points[3].getY() - points[0].getY();

    double magA = sqrt(ax*ax + ay*ay);
    double magB = sqrt(bx*bx + by*by);
    if (magA == 0.0 || magB == 0.0) return 0.0;

    double dot = ax*bx + ay*by;
    double cosTheta = dot / (magA * magB);
    if (cosTheta > 1.0) cosTheta = 1.0;
    if (cosTheta < -1.0) cosTheta = -1.0;

    double angle = acos(cosTheta);
    const double PI = acos(-1.0);
    if (angle > PI/2.0) angle = PI - angle;
    acuteAngle = angle;
    return acuteAngle;
}
