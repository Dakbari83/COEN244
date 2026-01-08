#ifndef POLYGON_H
#define POLYGON_H

#include "Point.h"

class Polygon{
protected:
    int size;
    Point* points;

public:
    Polygon(int);
    Polygon(const Polygon&);

    ~Polygon();

    void setPoint(int, const Point&);
    void setPoint(int, double, double);
    double area() const;

};

#endif