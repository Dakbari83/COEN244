//Daniel Akbari - ID#: 40298757
//Sepehr Ghasemzadeh Moghaddam - ID#: 40268909
//Assignment 3 - COEN 244
//“We certify that this submission is the original work of members of the group and meets the Faculty's Expectations of Originality”

#pragma once

#include "Package.h"

#include <string>

using namespace std;

class OvernightPackage : public Package {
private:
    double Ofee;

public:
    OvernightPackage();
    OvernightPackage(string, string, string, string, string, string, string, string, string, string, double, double, double);
    OvernightPackage(OvernightPackage&);

    virtual ~OvernightPackage() = default;

    double calculateCost() const override final;

    double getOvernightFee() const;
    OvernightPackage& setOvernightFee(double);

};