//Daniel Akbari - ID#: 40298757
//Sepehr Ghasemzadeh Moghaddam - ID#: 40268909
//Assignment 1 - COEN 244
//“We certify that this submission is the original work of members of the group and meets the Faculty's Expectations of Originality”

#include "Employee.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

static int pass=0, fail=0;

bool testDefaultConstructor(){
    Employee e;
    if((e.getFirst() == "" ) && (e.getLast() == "") && (e.getSalary() == 0)){
        pass++;
        return true;
    }
    else{
        fail++;
        return false;
    }

}

bool testCopyConstructor(){
    Employee e("danny", "chambly", 54321);
    Employee copied(e);
    if((copied.getFirst() == "danny" ) && (copied.getLast() == "chambly") && (copied.getSalary() == 54321)){
        pass++;
        return true;
    }
    else{
        fail++;
        return false;
    }
}

bool testParameterConstructor(){
    Employee e("dan", "anne", 76543), i("mac", "book", -5);
    if((e.getFirst() == "dan" ) && (e.getLast() == "anne") && (e.getSalary() == 76543) && (i.getFirst() == "mac") && 
    (i.getLast() == "book") && (i.getSalary() == 0)){
        pass++;
        return true;
    }
    else{
        fail++;
        return false;
    }
}

bool testGetFunctions(){
    Employee e("brian", "maccy", 9876);
    if((e.getFirst() == "brian") && (e.getLast() == "maccy") && (e.getSalary() == 9876)){
        pass++;
        return true;
    }
    else{
        fail++;
        return false;
    }
}

bool testSetFunctions(){
    Employee i,j;
    i.setFirst("sep");
    i.setLast("akb");
    i.setSalary(85643);

    j.setFirst("dannn");
    j.setLast("woah");
    j.setSalary(-12345);

    if((i.getFirst() == "sep") && (i.getLast() == "akb") && (i.getSalary() == 85643) && (j.getFirst() == "dannn") && 
    (j.getLast() == "woah") && (j.getSalary() == 0)){
        pass++;
        return true;
    }
    else{
        fail++;
        return false;
    }
}

bool testGiveRaise(){
    Employee i("", "", 1000),j("", "", 50000);
    i.displayYearlySalary(); // displaying their yearly salaries before the raise 
    j.displayYearlySalary();

    i.giveRaise(10);
    j.giveRaise(25);
    i.displayYearlySalary(); // displaying their yearly salaries after the raise
    j.displayYearlySalary();

    if((i.getSalary() == 1100) && (j.getSalary() == 62500)){
        pass++;
        return true;
    }

    else{
        fail++;
        return false;
    }
}

int compareSalary(const void* first, const void* second){ 
    const Employee* employee1 = static_cast <const Employee*> (first); 
    const Employee* employee2 = static_cast <const Employee*> (second); 

    int s = static_cast <int> (employee1->salary - employee2->salary);

    return s;
}

static bool test;

double testMaxEmployeeSalary(){
    Employee e("josh", "bouchard", 105000.99);
    Employee arrayEmployee[] = { Employee("dan", "tremblay", -59234), Employee(), e, Employee(e), Employee("sep", "man", 96743.25), 
    Employee("", "", 150500.5), Employee("", "", 86034), Employee("", "", 143753), Employee("", "", 120432), Employee("", "", 189000), 
    Employee("", "", 145234.24), Employee("", "", 178922)}; 

    size_t arraySize = sizeof(arrayEmployee) / sizeof (arrayEmployee[0]); 

    qsort (arrayEmployee, arraySize, sizeof(arrayEmployee[0]), compareSalary); 

 //   for (Employee item : arrayEmployee)
   //     item.display();
    
    if((arrayEmployee[11].getSalary())==189000){
        test = true;
        pass++;
    }
    else {
        test = false;
        fail++;
    }
        
    return (arrayEmployee[11].getSalary());
}



int main(){
    string message1 = testDefaultConstructor() ? "passes!" : "fails!";
    cout << "The case for default constructor " << message1 << endl;
    
    string message2 = testParameterConstructor() ? "passes!" : "fails!";
    cout << "The case for parameter-based constructor " << message2 << endl;

    string message3 = testCopyConstructor() ? "passes!" : "fails!";
    cout << "The case for copy constructor " << message3 << endl;

    string message4 = testGetFunctions() ? "passes!" : "fails!";
    cout << "The case for get functions " << message4 << endl;

    string message5 = testSetFunctions() ? "passes!" : "fails!";
    cout << "The case for set functions " << message5 << endl;

    string message6 = testGiveRaise() ? "passes!" : "fails!";
    cout << "The case for giving raise " << message6 << endl;

    testMaxEmployeeSalary();
    string message = (test) ? "passes!" : "fails!" ;
    cout << "The case for MaxEmployeeSalary " << message << endl;

    cout << pass << "/" << pass+fail <<" pass and " << fail <<"/" << pass+fail <<" fail" << endl;

    return 0;
    
}
