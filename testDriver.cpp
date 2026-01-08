//Daniel Akbari - ID#: 40298757
//Sepehr Ghasemzadeh Moghaddam - ID#: 40268909
//Assignment 3 - COEN 244
//“We certify that this submission is the original work of members of the group and meets the Faculty's Expectations of Originality”

#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

void virtualTest(const Package* baseClassPtr); // prototype


//Task 1.3 - a
void testStaticBinding(){
    cout << "\n--------------- Static binding test ---------------" << endl;
   Package p{"danny", "123 rue Guy", "Montreal", "QC", "H3H 3H3", "sep", "456 rue Fort", "Gatineau", "QC", "J1J 1J1", 5.5, 20};
   TwoDayPackage t{"Sierra", "789 rue Mcgill", "Ottawa", "ON", "P3P 2P1", "Monty", "1011 rue Mackay", "Toronto", "ON", "F4F 5F6", 10.75, 100, 43.5};
   OvernightPackage o("Taha", "146 boul Maisonn", "Vancouver", "BC", "K9K 8K7", "Sarah", "712 rue ste hel", "London", "ON", "U5U 1U2", 14.75, 95, 5);

   cout << "normal package cost: "
     << p.calculateCost() << "\ttwo-day package cost: " << t.calculateCost() << "\tovernight package cost: "
	 <<o.calculateCost() <<  endl;

     if (p.calculateCost() == 110 && t.calculateCost() == 1118.5 && o.calculateCost() == 1475)
        cout << "static binding test passes!" << endl;
    else
        cout << "static binding test fails!" << endl;
}

//Task 1.3 - b
void testDynamicBinding(){

		cout << "\n--------------- Dynamic binding test ---------------" << endl;

	    TwoDayPackage t1{"danny", "123 rue Guy", "Montreal", "QC", "H3H 3H3", "sep", "456 rue Fort", "Gatineau", "QC", "J1J 1J1", 5.5, 20, 58};
        TwoDayPackage t2{"Sierra", "789 rue Mcgill", "Ottawa", "ON", "P3P 2P1", "Monty", "1011 rue Mackay", "Toronto", "ON", "F4F 5F6", 10.75, 100, 43.5};
        TwoDayPackage t3{"bro", "97 rue conc", "winnipeg", "MA", "S3S 4S5", "hii", "10129 rue stanly", "Halifax", "NB", "L9L 3L4", 13, 40, 100};
        TwoDayPackage t4{"marie", "232 rue Rene", "calgary", "AL", "Y3Y 4Y1", "john", "2364 rue atwater", "Dallas", "TX", "I4I 4I6", 2.5, 64.5, 202.25};
        TwoDayPackage t5{"pierre", "73827 rue pen", "kingston", "ON", "Q3Q 8Q7", "tom", "1211 rue bishop", "Houston", "TX", "K4K 2K6", -5, -75.2, -140};
        TwoDayPackage t6(t5);
        TwoDayPackage t7;
        

        OvernightPackage o1("Taha", "146 rue mais", "new york", "NY", "K9K 8K7", "Sarah", "712 rue ste hel", "Sherbrooke", "QC", "V7V 1V2", 14.75, 95, 5);
        OvernightPackage o2("Genevieve", "167 rue tache", "LA", "CA", "E9E 6E7", "george", "1312 rue moise", "Quebec city", "QC", "X5X 1X0", 42, 23, 10);
        OvernightPackage o3("Arma", "452 rue laur", "SF", "CA", "W5K 8W7", "tommy", "4356 rue namur", "Granby", "QC", "A5A 1A3", 38.5, 78.5, 15);
        OvernightPackage o4("Stephanie", "248 rue sher", "Chicago", "IL", "N9N 8N2", "yannee", "356 rue du parc", "Longueil", "QC", "D5D 9D3", 60, 21, 20);
        OvernightPackage o5("Shay", "328 rue abi", "Miami", "FL", "B9B 8B4", "francesco", "853 rue de la cathedrale", "Laval", "QC", "M5M 8M4", -15.5, -44, -5);
        OvernightPackage o6(o5);
        OvernightPackage o7;

	   // create and initialize vector of base-class pointers
	   vector<Package*> packages{&t1, &t2, &t3, &t4, &t5, &t6, &t7, &o1, &o2, &o3, &o4, &o5, &o6, &o7};

	    double tCost = 0.0;


	   for (const Package* packagePtr : packages) {
	      virtualTest(packagePtr);
          tCost += packagePtr -> calculateCost();
	   }

       cout << "Total cost for all packages: " << tCost << endl;

       if (t1.calculateCost() == 168 && t2.calculateCost() == 1118.5 && t3.calculateCost() == 620 && t4.calculateCost() == 363.5 &&
        t5.calculateCost() == 0 && t6.calculateCost() == 0 && t7.calculateCost() == 0
        && o1.calculateCost() == 1475 && o2.calculateCost() == 1386 && o3.calculateCost() == 3599.75 && o4.calculateCost() == 2460 && 
        o5.calculateCost() == 0 && o6.calculateCost() == 0 && o7.calculateCost() == 0) 
            cout << "dynamic binding test passes!" << endl;
        else
            cout << "dynamic binding test fails!" << endl;
    }

void virtualTest(const Package* baseClassPtr) {

	cout<<left;
    cout << setw(60) <<"sender:" << "recipient: " << endl;

	cout << setw(30) << "name: "<< setw(30) <<baseClassPtr->getSname()
		<<setw(30) <<"name: " << setw(30) <<baseClassPtr->getRname()<<endl;

   cout << setw(30) << "address: " << setw(30) <<baseClassPtr->getSaddress()
	<< setw(30) << "address: " << setw(30) <<baseClassPtr->getRaddress()<< endl;

   cout <<setw(30) << "city: " << setw(30) <<baseClassPtr->getScity()
	<< setw(30) << "city: " << setw(30) <<baseClassPtr->getRcity() << endl;

   cout << setw(30) << "state: " << setw(30) <<baseClassPtr->getSstate()
	<<setw(30) << "state: " << setw(30) <<baseClassPtr->getRstate()<<endl;

   cout << setw(30) << "zip: " << setw(30) <<baseClassPtr->getSzip()
	<< setw(30) << "zip: " << setw(30) <<baseClassPtr->getRzip() << endl;

   cout << "cost: " << baseClassPtr->calculateCost() << endl;
   cout << "------------------------------------------------------" << endl;
}

//Task 1.3 - c
int main(){
    testStaticBinding();
    testDynamicBinding();
    return 0;
}