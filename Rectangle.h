#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Point.h"
#include "Polygon.h"
#include "Quadrilateral.h"

class Rectangle : public Quadrilateral{
private:
    double shorterSide;
    double longerSide;

public:
    Rectangle();
    Rectangle(const Rectangle&);

  //  ~Rectangle();

    double getShorterSide();
    double getLongerSide();
};

#endif