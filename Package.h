//Daniel Akbari - ID#: 40298757
//Sepehr Ghasemzadeh Moghaddam - ID#: 40268909
//Assignment 3 - COEN 244
//“We certify that this submission is the original work of members of the group and meets the Faculty's Expectations of Originality”

#pragma once

#include <string>

using namespace std;


class Package {
protected:
    // sender
    string sname;
    string saddress;
    string scity;
    string sstate;
    string szip;

    // recipient
    string rname;
    string raddress;
    string rcity;
    string rstate;
    string rzip;

    double weight;
    double cost;

public:
    Package(); // default constructor
    Package(string, string, string, string, string, string, string, string, string, string, double, double); // parameter constructor
    Package(Package&); // copy constructor

    virtual ~Package() = default; // virtual default destructor

    virtual double calculateCost() const;

    // getters
    string getSname() const;
    string getSaddress() const;
    string getScity() const;
    string getSstate() const;
    string getSzip() const;
    
    string getRname() const;
    string getRaddress() const;
    string getRcity() const;
    string getRstate() const;
    string getRzip() const;

    double getWeight() const;
    double getCost() const;

    // setters with cascading funtion call capability
    Package& setSname(string&);
    Package& setSaddress(string&);
    Package& setScity(string&);
    Package& setSstate(string&);
    Package& setSzip(string&);

    Package& setRname(string&);
    Package& setRaddress(string&);
    Package& setRcity(string&);
    Package& setRstate(string&);
    Package& setRzip(string&);

    Package& setWeight(double);
    Package& setCost(double);

};