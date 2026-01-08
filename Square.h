#ifndef SQUARE_H
#define SQUARE_H

#include "Point.h"
#include "Polygon.h"
#include "Quadrilateral.h"

class Square : public Quadrilateral{
private:
    double side;

public:
    Square();
    Square(const Square&);

  //  ~Square();

    double getSide();
};

#endif