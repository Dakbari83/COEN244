//Daniel Akbari - ID#: 40298757
//Sepehr Ghasemzadeh Moghaddam - ID#: 40268909
//Assignment 1 - COEN 244
//“We certify that this submission is the original work of members of the group and meets the Faculty's Expectations of Originality”

#include "Invoice.h"
#include <iostream>
#include <string>
using namespace std;

Invoice::Invoice():partNumber("0"),partDescription(""), quantity(0), price(0) {} // Default Constructor

// Parameter Constructor that checks if quantity or price is non-positive

Invoice::Invoice(string number, string description, int q, int p):
    partNumber(number), partDescription(description), quantity((q<1)? 0:q), price((p<1)? 0:p) {} 

Invoice::Invoice(const Invoice& i):
partNumber(i.partNumber), partDescription(i.partDescription), quantity(i.quantity), price(i.price) {} // Copy constructor

Invoice::~Invoice(){
    cout << "the destructor was called." << endl;
}

string Invoice::getPartNumber() const{
    return partNumber;
}

string Invoice::getPartDescription() const{
    return partDescription;
}

int Invoice::getPrice() const{
    return price;
}

int Invoice::getQuantity() const{
    return quantity;
}

void Invoice::setPartNumber(string n){
    partNumber = n;
}

void Invoice::setPartDescription(string d){
    partDescription = d;
}

void Invoice::setPrice(int p){
    price = (p<1)? 0 : p;
}

void Invoice::setQuantity(int q){
    quantity = (q<1)? 0:q;
}

int Invoice::getInvoiceAmount() const{
    return quantity * price;
}

Invoice Invoice::clone() const{
    Invoice clone;
    clone.partNumber = partNumber;
    clone.partDescription = partDescription;
    clone.price = price;
    clone.quantity = quantity;

    return clone;
}

Invoice Invoice::clone(const Invoice& i){
    Invoice clone;
    clone.partNumber = i.partNumber;
    clone.partDescription = i.partDescription;
    clone.price = i.price;
    clone.quantity = i.quantity;

    return clone;
}

void Invoice::display() const{
    cout << "part number: " << partNumber << "\tpart description: " << partDescription 
    << "\tprice per item: " << price << "\tquantity: " << quantity << endl;
}
