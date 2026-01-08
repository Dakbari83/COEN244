//Daniel Akbari - ID#: 40298757
//Sepehr Ghasemzadeh Moghaddam - ID#: 40268909
//Assignment 3 - COEN 244
//“We certify that this submission is the original work of members of the group and meets the Faculty's Expectations of Originality”

#include "Package.h"
#include "OvernightPackage.h"

#include <string>

using namespace std;

OvernightPackage::OvernightPackage():Package(), Ofee(0.0) {}

OvernightPackage::OvernightPackage(string sn, string sa, string sc, string ss, string sz, string rn, string ra, string rc, string rs, string rz, 
    double w, double c, double f) : Package(sn, sa, sc, ss, sz, rn, ra, rc, rs, rz, w, c), Ofee((f>0.0)?f:0.0) {}

OvernightPackage::OvernightPackage(OvernightPackage& other):Package(other), Ofee(other.Ofee) {}

double OvernightPackage::calculateCost() const{
    return (Ofee + cost) * weight;
}

double OvernightPackage::getOvernightFee() const{
    return Ofee;
}

OvernightPackage& OvernightPackage::setOvernightFee(double o){
    Ofee = (o>0.0)?o:0.0;
    return *this;
}