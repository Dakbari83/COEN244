#ifndef COMMISSION_H_
#define COMMISSION_H_

#include <string>

using namespace std;

class CommissionEmployee{
public:
	CommissionEmployee(
			const string& ,
			const string& ,
			const string& ,
			double =0.0,
			double =0.0);

	CommissionEmployee(const CommissionEmployee&); // copy constructor

	void setFirstName(const string&);
	string getFirstName() const;

	void setLastName(const string&);
	string getLastName() const;

	void setSocialSecurityNumber(const string&);
	string getSocialSecurityNumber() const;

	void setGrossSales(double);
	double getGrossSales() const;

	void setCommissionRate(double);
	double getCommissionRate() const;

	double earnings() const; //calculate earnings

	std::string toString() const; // return string representation;

	friend bool checkGrossSales (const CommissionEmployee&, double); // friended to access private data member (grossSales)


private:

protected:
	string firstName;
	string lastName;
	string socialSecurityNumber;
	double grossSales;
	double commissionRate;

};



#endif /* COMMISSION_H_ */
