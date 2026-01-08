#include <iostream>
#include <stdexcept>

#include <sstream>
#include <iomanip>

#include <string>

#include "commission.h"
using namespace std;

// parameterized constructor
CommissionEmployee::CommissionEmployee(const string& fName,const string& lName,const string& sequence,double sales,double rate) 
:firstName(fName),lastName(lName),socialSecurityNumber(sequence), grossSales((sales<0.0)? 0.0: sales),
commissionRate((rate>0.0 && rate<1.0)?rate:0.0)
{

}

CommissionEmployee::CommissionEmployee(const CommissionEmployee& other) // copy constructor
:firstName(other.firstName),lastName(other.lastName),socialSecurityNumber(other.socialSecurityNumber), grossSales(other.grossSales),
commissionRate(other.commissionRate)     {

}

void CommissionEmployee::setFirstName(const string& name){
	firstName =name;
}
std::string CommissionEmployee::getFirstName() const{
	return firstName;
}

void CommissionEmployee::setLastName(const string& name){
	lastName=name;

}
std::string CommissionEmployee::getLastName() const{
	return lastName;
}

void CommissionEmployee::setSocialSecurityNumber(const string& sequence){
	socialSecurityNumber = sequence;
}
std::string CommissionEmployee::getSocialSecurityNumber() const{
	return socialSecurityNumber;
}

void CommissionEmployee::setGrossSales(double sales){
	if(sales<0.0)
		throw invalid_argument("Gross sales must be >=0.0");
	grossSales = sales;
}
double CommissionEmployee::getGrossSales() const{
	return grossSales;
}

void CommissionEmployee::setCommissionRate(double rate){
	if(rate<=0.0 || rate >= 1.0){
		throw invalid_argument("Commission rate must be >0.0 and < 1.0");
	}
	commissionRate = rate;
}
double CommissionEmployee::getCommissionRate() const{
	return commissionRate;
}

double CommissionEmployee::earnings() const{ //calculate earnings
	return commissionRate * grossSales;

}




std::string CommissionEmployee::toString() const{ 

	ostringstream output;
	output << fixed << std::setprecision(2);
	output << "commission employee: " <<firstName
		   << " " << lastName
		   << "\nsocial security number: " << socialSecurityNumber
		   << "\ngross sales: " <<grossSales
		   << "\ncommission rate: " << commissionRate
		   << "\nearnings: " <<  std::setprecision(2) << earnings();

	return output.str();

}

bool checkGrossSales(const CommissionEmployee& other, double baseline){
	if (other.grossSales >= baseline)
		return true;
	return false;
}
