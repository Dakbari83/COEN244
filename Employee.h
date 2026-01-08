//Daniel Akbari - ID#: 40298757
//Sepehr Ghasemzadeh Moghaddam - ID#: 40268909
//Assignment 1 - COEN 244
//“We certify that this submission is the original work of members of the group and meets the Faculty's Expectations of Originality”

#ifndef STUDY244_EMPLOYEE_H
#define STUDY244_EMPLOYEE_H

#include <iostream>
#include <string>
using namespace std;

class Employee{

private:
    string first;
    string last;
    int salary;

public:
    Employee(); // Default constructor
    Employee(string, string, int);
    Employee(const Employee&);
    ~Employee(); // destructor

    string getFirst() const;
    string getLast() const;
    int getSalary() const;

    void setFirst(string);
    void setLast(string);
    void setSalary(int);

    void display() const; // function to display an employee's info
    void displayYearlySalary() const;

    void giveRaise(double); // function to give raise to an employee by passing the raise percentage


    friend int compareSalary(const void* first, const void* second); // friended to access private data members by the compare function


};




#endif //STUDY244_EMPLOYEE_H