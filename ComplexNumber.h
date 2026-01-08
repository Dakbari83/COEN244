//Daniel Akbari - ID#: 40298757
//Sepehr Ghasemzadeh Moghaddam - ID#: 40268909
//Assignment 3 - COEN 244
//“We certify that this submission is the original work of members of the group and meets the Faculty's Expectations of Originality”

#pragma once

#include <sstream>

using namespace std;

//Task 2.1
class ComplexNumber {
    friend ostream& operator<<(ostream& os, const ComplexNumber& c);
    friend istream& operator>>(istream& is, ComplexNumber& c);

private:
    double real;
    double imag;

public:
    ComplexNumber(double r = 0.0, double i = 0.0);

   

    ComplexNumber operator+(const ComplexNumber& other) const;
    ComplexNumber operator-(const ComplexNumber& other) const;
    ComplexNumber operator*(const ComplexNumber& other) const;
    ComplexNumber operator/(const ComplexNumber& other) const;


    bool operator==(const ComplexNumber& other) const;
    bool operator!=(const ComplexNumber& other) const;

    ComplexNumber operator^(double angle) const;

    ComplexNumber operator++(int);
    ComplexNumber& operator++();

    ComplexNumber operator--(int);
    ComplexNumber& operator--();

    // this is to read the values
    double operator[] (int index) const;
    // this is to write to the values
    double& operator[] (int index);

    double operator~() const;

    ComplexNumber operator!() const;

    ComplexNumber& operator=(const ComplexNumber& other);

    double getReal() const;
    double getImag() const;

};