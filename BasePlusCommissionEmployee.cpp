#include "BasePlusCommissionEmployee.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
using namespace std;

BasePlusCommissionEmployee::BasePlusCommissionEmployee(
			const string& firstName,
			const string& lastName,
			const string& ssn,
			double grossSales,
			double commissionRate,
			double salary):CommissionEmployee(firstName,lastName,ssn,grossSales,commissionRate),baseSalary((salary<=0.0)? 0.0 :salary) {

	}

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const BasePlusCommissionEmployee& other) // copy constructor
:CommissionEmployee(other),baseSalary(other.baseSalary){

}

string BasePlusCommissionEmployee::toString() const{
	ostringstream output;

	output << CommissionEmployee::toString()
		<< "\nbase salary: " <<  std::setprecision(2)  << baseSalary;

	return output.str();


}

double BasePlusCommissionEmployee::earnings() const{ //calculate earnings
	return baseSalary + (commissionRate * grossSales);

}

void BasePlusCommissionEmployee::setBaseSalary(double s){
	if(s<0.0)
		throw invalid_argument("Base salary must be >0.0");

	baseSalary = s;
}

double BasePlusCommissionEmployee::getBaseSalary() const{
	return baseSalary;
}




