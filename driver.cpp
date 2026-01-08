#include <iostream>
#include <stdexcept>
#include "IoTDataTensor.h"

using namespace std;

void testIoTDataTensor() {
    IoTDataTensor iot;
    try {
        cout << "Loading data from file..." << endl;
        iot.loadData();

        // 1. This will print ALL categories and ALL data rows
        iot.display();

        // 2. Verify specific access 
        int row = 1000;
        int col = 100;
        cout << "\n--- Specific Value Check ---" << endl;
        cout << "Header: " << iot.getCategory(col) << endl;
        cout << "Value : " << iot.getValue(row, col) << endl;

    } catch (const std::exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

int main() {
    testIoTDataTensor();
    return 0;
}