//Daniel Akbari - ID#: 40298757
//Sepehr Ghasemzadeh Moghaddam - ID#: 40268909
//Assignment 3 - COEN 244
//“We certify that this submission is the original work of members of the group and meets the Faculty's Expectations of Originality”

#include "Package.h"

#include <iostream>
#include <string>

using namespace std;

Package::Package():sname("NA"), saddress("NA"), scity("NA"), sstate("NA"), szip("NA"), rname("NA"), raddress("NA"), 
rcity("NA"), rstate("NA"), rzip("NA"), weight(0.0), cost(0.0) {}

Package::Package(string sn, string sa, string sc, string ss, string sz, string rn, string ra, string rc, string rs, string rz, double w, 
    double c):
sname(sn), saddress(sa), scity(sc), sstate(ss), szip(sz), rname(rn), raddress(ra), rcity(rc), rstate(rs), rzip(rz), 
weight((w>0.0)?w:0.0), cost((c>0.0)?c:0.0) {}

Package::Package(Package& other):sname(other.sname), saddress(other.saddress), scity(other.scity), sstate(other.sstate), szip(other.szip),
rname(other.rname), raddress(other.raddress), rcity(other.rcity), rstate(other.rstate), rzip(other.rzip), weight(other.weight), cost(other.cost) {}


double Package::calculateCost() const{
    return cost * weight;
}

string Package::getSname() const{
    return sname;
}

string Package::getSaddress() const{
    return saddress;
}

string Package::getScity() const{
    return scity;
}

string Package::getSstate() const{
    return sstate;
}

string Package::getSzip() const{
    return szip;
}

string Package::getRname() const{
    return rname;
}

string Package::getRaddress() const{
    return raddress;
}

string Package::getRcity() const{
    return rcity;
}

string Package::getRstate() const{
    return rstate;
}

string Package::getRzip() const{
    return rzip;
}

double Package::getWeight() const{
    return weight;
}

double Package::getCost() const{
    return cost;
}

// setters

Package& Package::setSname(string& n){ // to enable cascading function calls
    sname = n;
    return *this;
}

Package& Package::setSaddress(string& a){
    saddress = a;
    return *this;
}

Package& Package::setScity(string& c){
    scity = c;
    return *this;
}

Package& Package::setSstate(string& s){
    sstate = s;
    return *this;
}

Package& Package::setSzip(string& z){
    szip = z;
    return *this;
}

Package& Package::setRname(string& n){ // to enable cascading function calls
    rname = n;
    return *this;
}

Package& Package::setRaddress(string& a){
    raddress = a;
    return *this;
}

Package& Package::setRcity(string& c){
    rcity = c;
    return *this;
}

Package& Package::setRstate(string& s){
    rstate = s;
    return *this;
}

Package& Package::setRzip(string& z){
    rzip = z;
    return *this;
}

Package& Package::setWeight(double w){
    weight = (w>0.0)?w:0.0;
    return *this;
}

Package& Package::setCost(double c){
    cost = (c>0.0)?c:0.0;
    return *this;
}

