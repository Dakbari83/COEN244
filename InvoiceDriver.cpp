//Daniel Akbari - ID#: 40298757
//Sepehr Ghasemzadeh Moghaddam - ID#: 40268909
//Assignment 1 - COEN 244
//“We certify that this submission is the original work of members of the group and meets the Faculty's Expectations of Originality”

#include "Invoice.h"
#include <iostream>
#include <string>

using namespace std;

static int pass=0, fail=0;

bool testDefaultConstructor(){
    Invoice i;
    if((i.getPartNumber() == "0") && (i.getPartDescription() == "") && (i.getPrice() == 0 ) && (i.getQuantity() == 0)) {
        pass++;
        return true;
    }

    else{
        fail++;
        return false;
    }
}

bool testParameterConstructor(){
    Invoice i("123", "desk", -2, -5), j("5", "chair", 50, 2);
    if((i.getPartNumber() == "123") && (i.getPartDescription() == "desk") && (i.getPrice() == 0 ) && (i.getQuantity() == 0) && 
    (j.getPartNumber() == "5") && (j.getPartDescription() == "chair") && (j.getPrice() == 2) && (j.getQuantity() == 50)) {
        pass++;
        return true;
    }
    else{
        fail++;
        return false;
    }
}

bool testCopyConstructor(){
    Invoice i("23", "mouse", 35, 8);
    Invoice j(i);
    if((j.getPartNumber() == "23") && (j.getPartDescription() == "mouse") && (j.getPrice() == 8 ) && (j.getQuantity() == 35)){
        pass ++;
        return true;
    }
    else{
        fail++;
        return false;
    }
}

bool testGetFunctions(){
    Invoice i("67", "book", 150, 12);
    if((i.getPartNumber() == "67") && (i.getPartDescription() == "book") && (i.getPrice() == 12 ) && (i.getQuantity() == 150)){
        pass++;
        return true;
    }
    else{
        fail++;
        return false;
    }
}

bool testSetFunctions(){
    Invoice i, j;
    i.setPartNumber("762");
    i.setPartDescription("bottle");
    i.setPrice(32);
    i.setQuantity(17);

    j.setPartNumber("0");
    j.setPartDescription("no");
    j.setPrice(-5);
    j.setQuantity(-12);

    if((i.getPartNumber() == "762") && (i.getPartDescription() == "bottle") && (i.getPrice() == 32 ) && (i.getQuantity() == 17) && 
    (j.getPartNumber() == "0") && (j.getPartDescription() == "no") && (j.getPrice() == 0) && (j.getQuantity() == 0)){
        pass++;
        return true;
    }
    else{
        fail++;
        return false;
    }
}

bool testGetInvoiceAmount(){
    Invoice i("789", "ipad", 15, 3);
    if(i.getInvoiceAmount() == 45){
        pass++;
        return true;
    }
    else{
        fail++;
        return false;
    }
}

bool testCloneFunction1(){
    Invoice i("890", "mac", 145, 7999);
    Invoice j = i.clone();
    if((j.getPartNumber() == "890") && (j.getPartDescription() == "mac") && (j.getPrice() == 7999 ) && (j.getQuantity() == 145)){
        pass++;
        return true;
    }
    else{
        fail++;
        return false;
    }
}

bool testCloneFunction2(){
    Invoice i("890", "mac", 145, 7999);
    Invoice j;
    j = j.clone(i);
    if((j.getPartNumber() == "890") && (j.getPartDescription() == "mac") && (j.getPrice() == 7999 ) && (j.getQuantity() == 145)){
        pass++;
        return true;
    }
    else{
        fail++;
        return false;
    }
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

    string message6 = testGetInvoiceAmount() ? "passes!" : "fails!";
    cout << "The case for invoice amount " << message6 << endl;

    string message7 = testCloneFunction1() ? "passes!" : "fails!";
    cout << "The case for the first clone function " << message7 << endl;

    string message8 = testCloneFunction2() ? "passes!" : "fails!";
    cout << "The case for the second clone function " << message8 << endl;


    cout << pass << "/" << pass+fail <<" pass and " << fail <<"/" << pass+fail <<" fail" << endl;
    
    return 0;
}
