#include "IoTDataTensor.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

IoTDataTensor::IoTDataTensor() {
    iot_category.resize(0);
    iot_data.resize(0);
}

string IoTDataTensor::getCategory(int col) {
    if (col < 0 || col >= iot_category.size()) {
        throw std::out_of_range("Category index out of range");
    }
    return iot_category[col];
}

double IoTDataTensor::getValue(int row, int col) {
    if (row < 0 || row >= iot_data.size()) {
        throw std::out_of_range("Row index out of range");
    }
    // RankOneTensor's [] operator handles column bounds checking
    string valStr = iot_data[row][col];

    try {
        return std::stod(valStr);
    } catch (...) {
        throw std::runtime_error("Value at [" + to_string(row) + "][" + to_string(col) + "] is not a number: " + valStr);
    }
}

void IoTDataTensor::loadData() {
    string inputPath;
    cout << "Enter input file path (press Enter for default \"iot-shard.txt\"): ";
    getline(cin, inputPath);
    if (inputPath.empty()) inputPath = "iot-shard.txt";
    ifstream file(inputPath); 
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open input file.");
    }

    string line;

    // 1. Read the Header Line (Categories)
    if (getline(file, line)) {
        // Handle Windows \r if present
        if (!line.empty() && line.back() == '\r') line.pop_back();

        stringstream ss(line);
        string token;
        while (getline(ss, token, ',')) {
            iot_category.push_back(token);
        }
    }

    // 2. Read the Data Lines
    while (getline(file, line)) {
        if (line.empty()) continue;
        if (line.back() == '\r') line.pop_back();

        stringstream ss(line);
        string token;
        
        // Create a temp RankOneTensor for this row
        RankOneTensor<string> rowTensor;

        // Parse comma-separated values
        while (getline(ss, token, ',')) {
            rowTensor.insertData(token);
        }

        // Store the row
        iot_data.push_back(rowTensor);
    }
    file.close();
}

void IoTDataTensor::display() {
    cout << "=== Categories ===" << endl;
    for (size_t i = 0; i < iot_category.size(); ++i) {
        cout << "[" << i << "] " << iot_category[i] << endl;
    }

    cout << "\n=== Data Rows ===" << endl;
    for (size_t i = 0; i < iot_data.size(); ++i) {
        // Uses RankOneTensor's << operator
        cout << "Row " << i << ": " << iot_data[i] << endl; 
    }
}