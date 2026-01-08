//Daniel Akbari - ID#: 40298757
//Sepehr Ghasemzadeh Moghaddam - ID#: 40268909
//Assignment 1 - COEN 244
//“We certify that this submission is the original work of members of the group and meets the Faculty's Expectations of Originality”

#include "Employee.h"
#include <iostream>
#include <string>
using namespace std;

Employee::Employee():first(""), last(""), salary(0) {}
Employee::Employee(string f, string l, int s):first(f), last(l), salary((s<1)? 0:s) {}
Employee::Employee(const Employee& e):first(e.first), last(e.last), salary(e.salary) {}

Employee::~Employee(){
    cout << "the destructor was called." << endl;

}

string Employee::getFirst() const{
    return first;
}

string Employee::getLast() const{
    return last;
}

int Employee::getSalary() const{
    return salary;
}

void Employee::setFirst(string f){
    first = f;
}

void Employee::setLast(string l){
    last = l;
}

void Employee::setSalary(int s) {
    salary = (s < 1) ? 0 : s;
}


void Employee::display() const{
    cout << "full name: " << first << " " << last << "\tsalary: " << salary << endl;
}

void Employee::displayYearlySalary() const{
    cout << "Yearly salary: " << salary * 12 << endl;
}

void Employee::giveRaise(double percent){
    salary = salary * (1 + (percent / 100.0));
}

