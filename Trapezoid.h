#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "Point.h"
#include "Polygon.h"
#include "Quadrilateral.h"

class Trapezoid : public Quadrilateral {
private:
    double shorterSide;
    double longerSide;

public:
    Trapezoid();
    Trapezoid(const Trapezoid&);

//    ~Trapezoid();

    double getShorterSide();
    double getLongerSide();
};

#endif