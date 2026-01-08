#include "RankOneTensor.h"
#include "BaseTensor.h"

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

void testTensorType() {
    cout << "=======================================" << endl;
    cout << "      STARTING RANK ONE TENSOR TEST    " << endl;
    cout << "=======================================" << endl << endl;

    // First, let's include the test function that was provided in the assignment description
    RankOneTensor<string> tensor(2);
    tensor[0] = "Hello";
    tensor[1] = "Coen244";
    cout<< tensor;
    RankOneTensor<double> dtensor6(2);
    dtensor6[0] = 0.15;
    dtensor6[1] = 0.30;
    cout << dtensor6;
    RankOneTensor<double> dtensor5(2);
    dtensor5.loadData();
    cout << dtensor5;
    cout << dtensor6+dtensor5;
    cout << dtensor6[0] << endl;

    // Below is more complete testing

    // ---------------------------------------------------------
    // 1. TEST CONSTRUCTORS & BASIC DATA MANAGEMENT (DOUBLE)
    // ---------------------------------------------------------
    cout << "--- 1. Constructors & Loading Data ---" << endl;
    
    // Test Constructor(size) and loadData()
    RankOneTensor<double> dtensor1(3);
    dtensor1.loadData(); 
    cout << "dtensor1 (Random): " << dtensor1;

    // Test Manual Insertion (insertData)
    dtensor1.insertData(99.9);
    cout << "dtensor1 after insertData(99.9): " << dtensor1;

    // Test Default Constructor
    RankOneTensor<double> dtensor;
    cout << "dtensor, default constructor, no data: " << dtensor;

    // Test Copy Constructor
    RankOneTensor<double> dtensor2 = dtensor1; 
    cout << "dtensor2 (Copy of dtensor1): " << dtensor2;
    RankOneTensor<double> dtensor3(dtensor2);
    cout << "dtensor3 (Copy of dtensor2): " << dtensor3;

    // Test Equality Operator
    RankOneTensor<double> dtensor4 = dtensor2;
    dtensor4[0] = 2.5;
    cout << "dtensor1 == dtensor2? " << (dtensor1 == dtensor2 ? "True" : "False") << endl;


    // Test operator[] (Write and Read)
    dtensor1[0] = 5.0;
    cout << "Modified dtensor1[0] to 5.0: " << dtensor1[0] << endl;
    cout << "dtensor1 is now: " << dtensor1;
    
    // Verify dtensor2 didn't change (deep copy check)
    cout << "dtensor2 should be unchanged: " << dtensor2 << endl;


    // ---------------------------------------------------------
    // 2. TEST MATH OPERATORS (DOUBLE)
    // ---------------------------------------------------------
    cout << endl << "--- 2. Math Operations (Double) ---" << endl;

    RankOneTensor<double> mathTensor(2);
    mathTensor[0] = 10.0;
    mathTensor[1] = 20.0;
    cout << "Base Math Tensor: " << mathTensor;

    // Scalar Math
    cout << "Add Scalar ( + 5.0): " << mathTensor + 5.0;
    cout << "Sub Scalar ( - 2.0): " << mathTensor - 2.0;
    cout << "Mul Scalar ( * 2.0): " << mathTensor * 2.0;

    // Tensor Math
    RankOneTensor<double> otherMath(2);
    otherMath[0] = 1.0;
    otherMath[1] = 2.0;
    cout << "Other Tensor: " << otherMath;

    cout << "Tensor Addition: " << (mathTensor + otherMath);
    cout << "Tensor Subtraction: " << (mathTensor - otherMath);
    cout << "Tensor Multiplication: " << (mathTensor * otherMath);


    // ---------------------------------------------------------
    // 3. TEST INCREMENT OPERATORS
    // ---------------------------------------------------------
    cout << endl << "--- 3. Increment Operators ---" << endl;
    
    // Test Prefix (++t)
    cout << "Before Prefix ++: " << mathTensor;
    ++mathTensor;
    cout << "After Prefix ++:  " << mathTensor;

    // Test Postfix (t++)
    // We print the result of the expression (should be old value) and the tensor after (new value)
    cout << "Result of Postfix t++ (Should be old value): " << mathTensor++;
    cout << "Tensor State After Postfix (Should be incremented): " << mathTensor;


    // ---------------------------------------------------------
    // 4. TEST STRING TENSORS
    // ---------------------------------------------------------
    cout << endl << "--- 4. String Tensor Specifics ---" << endl;

    RankOneTensor<string> stensor1(2);
    stensor1[0] = "Hello";
    stensor1[1] = "World";
    
    RankOneTensor<string> stensor2(2);
    stensor2[0] = " C++";
    stensor2[1] = " Templates";

    cout << "String Tensor 1: " << stensor1;
    cout << "String Tensor 2: " << stensor2;

    // Test Concatenation (Operator +)
    // Strings allow addition (concatenation), but not -, *, or /
    cout << "Concatenation (stensor1 + stensor2): " << (stensor1 + stensor2);

    // Test Assignment Operator
    stensor1 = stensor2;
    cout << "After Assignment (s1 = s2), s1 is: " << stensor1;


    // ---------------------------------------------------------
    // 5. TEST EXCEPTION HANDLING 
    // ---------------------------------------------------------
    cout << endl << "--- 5. Exception Handling Tests ---" << endl;

    // A. Test Index Out of Bounds
    try {
        cout << "Testing Index Out of Bounds... ";
        double val = dtensor1[100]; // Should fail
    } catch (const std::out_of_range& e) {
        cout << "SUCCESS! Caught expected error: " << e.what() << endl;
    }

    // B. Test Dimension Mismatch (Math)
    try {
        cout << "Testing Dimension Mismatch (Addition)... ";
        RankOneTensor<double> tiny(1);
        RankOneTensor<double> huge(100);
        tiny + huge; // Should fail
    } catch (const std::invalid_argument& e) {
        cout << "SUCCESS! Caught expected error: " << e.what() << endl;
    }

    // C. Test Dimension Mismatch (Assignment)
    try {
        cout << "Testing Dimension Mismatch (Assignment)... ";
        RankOneTensor<double> t1(2);
        RankOneTensor<double> t2(5);
        // Fill them so they aren't empty (empty logic handles resizing sometimes)
        t1.insertData(1); t1.insertData(2);
        t2.insertData(1);
        t1 = t2; // Should fail per your requirement
    } catch (const std::invalid_argument& e) {
        cout << "SUCCESS! Caught expected error: " << e.what() << endl;
    }

    // D. Test Invalid String Operations
    try {
        cout << "Testing Invalid String Subtraction... ";
        stensor1 - stensor2; // Should fail (Logic Error)
    } catch (const std::logic_error& e) {
        cout << "SUCCESS! Caught expected error: " << e.what() << endl;
    }

    try {
        cout << "Testing Invalid String Increment... ";
        stensor1++; // Should fail
    } catch (const std::logic_error& e) {
        cout << "SUCCESS! Caught expected error: " << e.what() << endl;
    }

    // E. Test Invalid Equality Operations
    try {
        cout << "Testing Invalid Equality Operation (Tensors from different dimensions)... ";
        cout << "dtensor4 == dtensor2? " << (dtensor == dtensor2 ? "True" : "False") << endl;

    } catch (const std::invalid_argument& e) {
        cout << "SUCCESS! Caught expected error: " << e.what() << endl;
    }

    try {
        cout << "Testing Invalid Equality Operation (Tensors not equal)... ";
        cout << "dtensor4 == dtensor2? " << (dtensor4 == dtensor2 ? "True" : "False") << endl;

    } catch (const std::invalid_argument& e) {
        cout << "SUCCESS! Caught expected error: " << e.what() << endl;
    }



    cout << endl << "=======================================" << endl;
    cout << "          ALL TESTS COMPLETED          " << endl;
    cout << "=======================================" << endl;
}

int main(){
    testTensorType();
    return 0;
}