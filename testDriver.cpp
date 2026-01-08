#include "Point.h"
#include "Polygon.h"
#include "Quadrilateral.h"
#include "Rhombus.h"
#include "Trapezoid.h"
#include "Square.h"
#include "Rectangle.h"
#include "Parallelogram.h"

#include <iostream>
#include <iomanip>

using namespace std;

static int pass = 0, fail = 0;

bool testPolygon(){
    Polygon p(5);
    p.setPoint(0,7,1);
    p.setPoint(1,8,5);
    p.setPoint(2,5,4);
    p.setPoint(3,2,5);
    p.setPoint(4,1,1);

    cout << "\n----- Polygon -----" << endl;
    cout << "the area of polygon is "<< p.area() << endl;

    if (p.area() == 21){
        pass++;
        return true;
    }

    fail++;
    return false;
}

bool testQuadrilateral(){
    Quadrilateral q;
    q.setPoint(0,0,1);
    q.setPoint(1,9,5);
    q.setPoint(2,2,6);
    q.setPoint(3,1,5);

    cout << "\n----- Quadrilateral -----" << endl;
    cout << "the area of quadrilateral is " << q.area() << endl;

    if (q.area() == 20){
        pass++;
        return true;
    }

    fail++;
    return false;
}

bool testRhombus(){
    Rhombus r;
    r.setPoint(0,6,5);
    r.setPoint(1,4,6);
    r.setPoint(2,5,4);
    r.setPoint(3,7,3);
    cout << "\n----- Rhombus -----" << endl;
    cout << "side length: " << r.getSide() << endl;
    cout << "acute angle in radians: " << r.getAngle() << endl;
    cout << "area: " << r.area() << endl;

    if ((r.getSide() == 2.2360679774997898051) && (r.getAngle() == 0.64350110879328470403) && (r.area() == 3)){
        pass++;
        return true;
    }

    fail++;
    return false;

}

bool testParallelogram(){
    Parallelogram p;
    p.setPoint(0,5,2);
    p.setPoint(1,4,4);
    p.setPoint(2,7,7);
    p.setPoint(3,8,5);
    cout << "\n----- Parallelogram -----" << endl;
    cout << "shorter side: " << p.getShorterSide() << endl;
    cout << "longer side: " << p.getLongerSide() << endl;
    cout << "acute angle in radians: " << p.getAcuteAngleInRadian() << endl;
    cout << "area: " << p.area() << endl;

    if ((p.getShorterSide() == 2.2360679774997898051) && (p.getLongerSide() == 4.2426406871192847703) && (p.getAcuteAngleInRadian() == 1.249045772398254428) && (p.area() == 9)){
        pass++;
        return true;
    }

    fail++;
    return false;


}

bool testSquare(){
    Square s;
    s.setPoint(0,5,6);
    s.setPoint(1,7,4);
    s.setPoint(2,5,2);
    s.setPoint(3,3,4);
    cout << "\n----- Square -----" << endl;
    cout << "the side length of the square is: " << s.getSide() << endl;
    cout << "area: " << s.area() << endl;
    if ((s.getSide() == 2.8284271247461902909) && (s.area() == 8)){
        pass++;
        return true;
    }


    fail++;
    return false;

}

bool testTrapezoid(){
    Trapezoid p;
    p.setPoint(0,10,3);
    p.setPoint(1,7,5);
    p.setPoint(2,4,5);
    p.setPoint(3,4,3);
    cout << "\n----- Trapezoid -----" << endl;
    cout << "shorter side: " << p.getShorterSide() << endl;
    cout << "longer side: " << p.getLongerSide() << endl;
    cout << "area: " << p.area() << endl;

    if ((p.getShorterSide() == 3) && (p.getLongerSide() == 6) && (p.area() == 9)){
        pass++;
        return true;
    }

    fail++;
    return false;

}

bool testRectangle(){
    Rectangle r;
    r.setPoint(0,7,3);
    r.setPoint(1,7,5);
    r.setPoint(2,2,5);
    r.setPoint(3,2,3);
    cout <<"\n----- Rectangle -----" << endl;
    cout << "shorter side: " << r.getShorterSide() << endl;
    cout << "longer side: " << r.getLongerSide() << endl;
    cout << "area: " << r.area() << endl;

    if ((r.getShorterSide() == 2) && (r.getLongerSide() == 5) && (r.area() == 10)){
        pass++;
        return true;
    }

    fail++;
    return false;


}

int main(){
    if(testPolygon())
        cout << "\nPolygon test passes!" << endl;
    else
        cout << "\nPolygon test fails!" << endl;

    if(testQuadrilateral())
        cout << "\nQuadrilateral test passes!" << endl;
    else
        cout << "\nQuadrilateral test fails!" << endl;

    if(testRhombus())
        cout << "\nRhombus test passes!" << endl;
    else
        cout << "\nRhombus test fails!" << endl;

    if(testParallelogram())
        cout << "\nParallelogram test passes!" << endl;
    else    
        cout << "\nParallelogram test fails!" << endl;

    if(testTrapezoid())
        cout <<"\nTrapezoid test passes!" << endl;
    else
        cout <<"\nTrapezoid test fails!" << endl;

    if(testRectangle())
        cout << "\nRectangle test passes!" << endl;
    else
        cout << "\nRectangle test fails!" << endl;

    if(testSquare())
        cout << "\nSquare test passes!" << endl;
    else
        cout << "\nSquare test fails!" << endl;


    cout << "\n" << pass << "/" << pass + fail << " tests pass and " << fail << "/" << pass + fail << " fail!" << endl;

    return 0;
}