#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include "Point.h"
#include "Polygon.h"

class Quadrilateral : public Polygon {
protected:

// inherited data members
  //  int size;
  //  Point* points;

public:
    Quadrilateral(); // default constructor, quadrilateral has size 4
    Quadrilateral(const Quadrilateral&);

  //  ~Quadrilateral(); // destructor

// inherited member functions

  //  void setPoint(int, const Point&);
  //  void setPoint(int, double, double);
  //  double area() const;


};

#endif