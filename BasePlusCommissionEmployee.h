#ifndef BASEPLUSCOMMISSIONEMPLOYEE_H_
#define BASEPLUSCOMMISSIONEMPLOYEE_H_

#include "commission.h"
#include <string>
using namespace std;
class BasePlusCommissionEmployee : public CommissionEmployee{
	/// the following attributes are protected data members;

	/*
	 * 	std::string firstName;
	std::string lastName;
	std::string socialSecurityNumber;
	double grossSales;
	double commissionRate;
	 */

public:
	BasePlusCommissionEmployee(
			const string& firstName,
			const string& lastName,
			const string& ssn,
			double grossSales=0.0,
			double commissionRate=0.0,
			double salary=0.0);

	//copy constructor
	BasePlusCommissionEmployee(const  BasePlusCommissionEmployee& );
	string toString() const;

	double earnings() const;

	double getBaseSalary() const;
	void setBaseSalary(double);



private:
	double baseSalary;


};


#endif /* BASEPLUSCOMMISSIONEMPLOYEE_H_ */
