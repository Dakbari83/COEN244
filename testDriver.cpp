//Daniel Akbari - ID#: 40298757
//Sepehr Ghasemzadeh Moghaddam - ID#: 40268909
//Assignment 3 - COEN 244
//“We certify that this submission is the original work of members of the group and meets the Faculty's Expectations of Originality”

#include "ComplexNumber.h"

#include <iostream>

using namespace std;

//Task 2.2
void testComplexNumber(){
    cout << "\n----------------Overridden operator test---------------" <<endl;
    ComplexNumber c1(3,4);
    ComplexNumber c2(5,6);
    ComplexNumber c3(3,4);

    cout << "Original c1: " << c1 << endl;
    cout << "Original c2: " << c2 << endl;
    cout << "Original c3: " << c3 << endl;


    // testing prefix increment
    cout << "after ++c1: " << ++c1 << endl;

    // testing postfix increment
    cout << "after c1++: " << c1++ << endl;
    cout << "value of c1 after c1++: " << c1 << endl;

    // testing prefix decrement
    cout << "after --c1: " << --c1 << endl;

    // testing postfix decrement
    cout << "after c1--: " << c1-- << endl;
    cout << "value of c1 after c1--: " << c1 << endl;

    // access real and imaginary parts using []
    cout << "real part (c1[0]): " << c1[0] << endl;
    cout << "imaginary part (c1[1]): " << c1[1] << endl;

    // addition
    cout << "c1 + c2: " << c1 + c2 << endl;

    // subtraction
    cout << "c1 - c2: " << c1 - c2 << endl;

    // multiplication
    cout << "c1 * c2: " << c1 * c2 << endl;

    // division
    cout << "c1 / c2: " << c1 / c2 << endl;


    // equality, unequality
    string s = (c1 == c3) ? "equal" : "not equal";
    string s2 = (c2 == c3) ? "equal" : "not equal";

    string s3 = (c1 != c3) ? "unequal" : "equal";
    string s4 = (c1 != c2) ? "unequal" : "equal";


    cout << "c1 and c3 are " << s << endl;
    cout << "c2 and c3 are " << s2 << endl;
    cout << "c1 and c3 are " << s3 << endl;
    cout << "c1 and c2 are " << s4 << endl;

    // rotation
    ComplexNumber rot = c1 ^ 1.5;
    cout << "rotation (c1^1.5): " << rot << endl;

    // modulus
    cout << "modulus (~c1): " << ~c1 << endl;

    // complex conjugate
    cout << "complex conjugate (!c1): " << !c1 << endl;

    // input >> operator

    cout << "enter new values for c2: " << endl;
    cin >> c2;

    cout << "new c2 is: " << c2 << endl;

    // test writing to the object using []
    c2[0] = 15;
    cout <<"writing to object using []: now c2 is: (c2[0] = 15) " << c2 << endl;

    // test assignment
    ComplexNumber c4 = c1;
    cout << "assignment: c4 is the same as c1 (c4 = c1): " << c4 << endl;

    try{
        cout << "invalid index access (c1[2]): " << c1[2] << endl;}
    catch(const out_of_range& e){
        cerr << "Error: " << e.what() << endl;
    }

    }
 

//Task 2.3
void testMandelbrot() {
    cout << "\n\n--- Testing Mandelbrot Iteration ---" << endl;
    
    ComplexNumber z(0.0, 0.0);  // Standard starting value for z(0)
    ComplexNumber c(0.3, 0.4);  // A sample constant 'c'
    int n = 10;                 // Number of iterations

    cout << "Starting with z(0) = " << z << endl;
    cout << "Using constant   c = " << c << endl;
    cout << "Iterating " << n << " times...\n" << endl;

    for (int i = 0; i < n; ++i) {
        z = z * z + c;

        cout << "z(" << (i + 1) << ") = " << z << endl;

        double magnitude = ~z;
        if (magnitude > 2.0) {
            cout << "  -> Magnitude is " << magnitude << " (which is > 2). Point has 'escaped'." << endl;
            break; 
        }
    }

    cout << "\n--- End of Mandelbrot Test ---" << endl;
}
    

int main(){
    testMandelbrot();
    testComplexNumber();
    return 0;
}