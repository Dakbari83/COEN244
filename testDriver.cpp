#include "commission.h"
#include "BasePlusCommissionEmployee.h"
#include <iostream>
using namespace std;

void test(){
	CommissionEmployee cp("abc","def","123",0,0);
	std::cout << cp.toString() << std::endl;

	std::cout << "----------------------------"<<std::endl;

	BasePlusCommissionEmployee bp("ghi","lmn", "456",1,1,5);
	std::cout << bp.toString() << std::endl;

	std::cout << "----------------------------"<<std::endl;



}

void testCopyConstructor(){
	CommissionEmployee cp("hi", "dan", "135", 3.75, 0.5);
	CommissionEmployee copy(cp);
	cout << copy.toString() << endl;

	std::cout << "----------------------------"<<std::endl;

	CommissionEmployee ce("bye", "bro", "243", -5, 1.5);
	CommissionEmployee copyy(ce);
	cout << copyy.toString() << endl;

	std::cout << "----------------------------"<<std::endl;

	BasePlusCommissionEmployee bp("bon", "aki", "876", 1.5, 0.75, 10);
	BasePlusCommissionEmployee copie(bp);
	cout << copie.toString() << endl;

	std::cout << "----------------------------"<<std::endl;

	BasePlusCommissionEmployee bpe("yoo", "fry", "199", -80, 123, -20);
	BasePlusCommissionEmployee copiee(bpe);
	cout << copiee.toString() << endl;

	std::cout << "----------------------------"<<std::endl;

	if (copy.getFirstName() == "hi" && copy.getLastName() == "dan" && copy.getSocialSecurityNumber() == "135" && 
	copy.getGrossSales() == 3.75 && copy.getCommissionRate() == 0.5 && copyy.getFirstName() == "bye" && copyy.getLastName() == "bro"
	&& copyy.getSocialSecurityNumber() == "243" && copyy.getGrossSales() == 0.0 && copyy.getCommissionRate() == 0.0 && 
	copie.getFirstName() == "bon" && copie.getLastName() == "aki" && copie.getSocialSecurityNumber() == "876" &&
	copie.getGrossSales() == 1.5 && copie.getCommissionRate() == 0.75 && copie.getBaseSalary() == 10 && 
	copiee.getFirstName() == "yoo" && copiee.getLastName() == "fry" && copiee.getSocialSecurityNumber() == "199" && 
	copiee.getGrossSales() == 0.0 && copiee.getCommissionRate() == 0.0 && copiee.getBaseSalary() == 0.0)
		cout << "copy constructor test passes" << endl;
	else
		cout << "copy constructor test fails" << endl;
	
	std::cout << "----------------------------"<<std::endl;



}

void testFriendAndInheritance(){
	BasePlusCommissionEmployee basePlusMember("abc", "def", "0987654321", 250000, 0.15, 5000);
	if(checkGrossSales(basePlusMember, 100000)==true)
		cout << "friend test passes for baseline 100000" << endl;
	else
		cout << "friend test fails for baseline 100000" << endl;

	if(checkGrossSales(basePlusMember, 5000)==true)
		cout << "friend test passes for baseline 5000" << endl;
	else
		cout << "friend test fails for baseline 5000" << endl;
	

}

/* the inheritance works here because even though the function checkGrossSales was defined for CommissionEmployee class, since 
BasePlusCommissionEmployee is a derived class of CommisisonEmployee, then an object of type BasePlusCommissionEmployee
IS a CommissionEmployee, that's why we could pass the BasePlusCommissionEmployee object to our checkGrossSales function.

*/

int main(){
	test();
	testCopyConstructor();
	testFriendAndInheritance();

	return 0;
}

