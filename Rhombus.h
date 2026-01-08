#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Point.h"
#include "Polygon.h"
#include "Quadrilateral.h"

class Rhombus : public Quadrilateral{
private:
    double side;
    double acuteAngle;

public:
    Rhombus();
    Rhombus(const Rhombus&);

   // ~Rhombus();

    double getSide();
    double getAngle();

};


#endif