//Daniel Akbari - ID#: 40298757
//Sepehr Ghasemzadeh Moghaddam - ID#: 40268909
//Assignment 3 - COEN 244
//“We certify that this submission is the original work of members of the group and meets the Faculty's Expectations of Originality”
#include "Package.h"
#include "TwoDayPackage.h"

#include <string>

using namespace std;

TwoDayPackage::TwoDayPackage():Package(), Tfee(0.0) {}

TwoDayPackage::TwoDayPackage(string sn, string sa, string sc, string ss, string sz, string rn, string ra, string rc, string rs, string rz, 
    double w, double c, double f) : Package(sn, sa, sc, ss, sz, rn, ra, rc, rs, rz, w, c), Tfee((f>0.0)?f:0.0) {}

TwoDayPackage::TwoDayPackage(TwoDayPackage& other):Package(other), Tfee(other.Tfee) {}

double TwoDayPackage::calculateCost() const{
    return Package::calculateCost() + Tfee;
}

double TwoDayPackage::getTwoDayFee() const{
    return Tfee;
}

TwoDayPackage& TwoDayPackage::setTwoDayFee(double t){
    Tfee = (t>0.0)?t:0.0;
    return *this;
}