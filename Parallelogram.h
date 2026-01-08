#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include "Quadrilateral.h"
#include "Point.h"
#include "Polygon.h"

class Parallelogram : public Quadrilateral{

private:
    double acuteAngle;
    double shorterSide;
    double longerSide;

public:
    Parallelogram();
    Parallelogram(const Parallelogram&);

//    ~Parallelogram();

    double getShorterSide() ;
    double getLongerSide() ;
    double getAcuteAngleInRadian() ;

};

#endif