//Daniel Akbari - ID#: 40298757
//Sepehr Ghasemzadeh Moghaddam - ID#: 40268909
//Assignment 3 - COEN 244
//“We certify that this submission is the original work of members of the group and meets the Faculty's Expectations of Originality”
#include "ComplexNumber.h"
#include <iostream>
#include <iomanip>
#include <cmath> // for sqrt
#include <stdexcept>

using namespace std;

//Task 2.1
ComplexNumber::ComplexNumber(double r, double i) : real(r), imag(i) {}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& other) const{
    return ComplexNumber(real + other.real, imag + other.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& other) const{
    return ComplexNumber(real - other.real, imag - other.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& other) const{
    return ComplexNumber(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber& other) const{
    return ComplexNumber((real * other.real + imag * other.imag) / (other.real * other.real + other.imag * other.imag), 
    (imag * other.real - real * other.imag) / (other.real * other.real + other.imag * other.imag));
}

bool ComplexNumber::operator==(const ComplexNumber& other) const{
    return ((real == other.real) && (imag == other.imag));
}

bool ComplexNumber::operator!=(const ComplexNumber& other) const{
    return !operator==(other);
}

double ComplexNumber::getReal() const{
    return real;
}

double ComplexNumber::getImag() const{
    return imag;
}

ostream& operator<<(ostream& os, const ComplexNumber& c) { 
    if (c.imag >= 0)
        os << c.real << " + i" << c.imag;
    else

        os <<  c.real << " - i" <<  -c.imag ;
    return os;
}

istream& operator>>(istream& is, ComplexNumber& c) { 
        is >> c.real  >> c.imag;
    return is;
}

ComplexNumber& ComplexNumber::operator++() {
    imag += 1.0;
    real += 1.0;
    return *this;
}

// Postfix Increment 
ComplexNumber ComplexNumber::operator++(int) { 
    ComplexNumber temp = *this;
    imag += 1.0;
    real += 1.0;
    return temp; 
}

// Prefix Decrement 
ComplexNumber& ComplexNumber::operator--() {
    imag -= 1.0;
    real -= 1.0;
    return *this;
}

// Postfix Decrement 
ComplexNumber ComplexNumber::operator--(int) {
    ComplexNumber temp = *this;
    imag -= 1.0;
    real -= 1.0;
    return temp;
}

// version to write to
double& ComplexNumber::operator[](int index){
    if(index != 0 && index != 1)
        throw out_of_range("index out of range!");

    return (index) ? imag : real;
}

// version to read the values
double ComplexNumber::operator[](int index) const{
    if(index != 0 && index != 1)
        throw out_of_range("index out of range!");

    return (index) ? imag : real;
}

double ComplexNumber::operator~() const{
    return sqrt(real*real + imag*imag);
}

ComplexNumber ComplexNumber::operator!() const{
    return ComplexNumber(real, -imag);
}

ComplexNumber ComplexNumber::operator^(double angle) const{
    return ComplexNumber(real * cos(angle) - imag * sin(angle), real * sin(angle) + imag * cos(angle));
}

ComplexNumber& ComplexNumber::operator=(const ComplexNumber& other){
    if(*this != other){
        real = other.real;
        imag = other.imag;
    }
    return *this;
}