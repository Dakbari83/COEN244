#ifndef POINT_H
#define POINT_H

class Point{
protected:
    double x;
    double y;

public:
    Point();
    Point(double, double);
    Point(const Point&);

  //  ~Point();

    void setX(double c);
    void setY(double c);

    double getX() const;
    double getY() const;


};

#endif