//Daniel Akbari - ID#: 40298757
//Sepehr Ghasemzadeh Moghaddam - ID#: 40268909
//Assignment 3 - COEN 244
//“We certify that this submission is the original work of members of the group and meets the Faculty's Expectations of Originality”
#pragma once

#include "Package.h"

#include <string>

using namespace std;

class TwoDayPackage : public Package{
private:
    double Tfee;

public:
    TwoDayPackage();
    TwoDayPackage(string, string, string, string, string, string, string, string, string, string, double, double, double);
    TwoDayPackage(TwoDayPackage&);

    virtual ~TwoDayPackage() = default;

    double calculateCost() const override final;

    double getTwoDayFee() const;
    TwoDayPackage& setTwoDayFee(double);

};