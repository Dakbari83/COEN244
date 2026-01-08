//Daniel Akbari - ID#: 40298757
//Sepehr Ghasemzadeh Moghaddam - ID#: 40268909
//Assignment 1 - COEN 244
//“We certify that this submission is the original work of members of the group and meets the Faculty's Expectations of Originality”

#ifndef STUDY244_INVOICE_H
#define STUDY244_INVOICE_H

#include <iostream>
#include <string>
using namespace std;


class Invoice{
private:
    string partNumber;
    string partDescription;
    int quantity;
    int price;

public:
    Invoice(); // Default constructor
    Invoice(string, string, int, int); // Parameter-based constructor
    Invoice(const Invoice&); // Copy constructor
    ~Invoice(); // Destructor

    // Get functions
    string getPartNumber() const;
    string getPartDescription() const;
    int getQuantity() const;
    int getPrice() const;

    // Set functions
    void setPartNumber(string);
    void setPartDescription(string);
    void setQuantity(int);
    void setPrice(int);

    int getInvoiceAmount() const;
    Invoice clone() const;
    Invoice clone(const Invoice&);

    void display() const;



};

#endif //STUDY244_INVOICE_H