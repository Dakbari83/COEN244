#ifndef IOTDATATENSOR_H
#define IOTDATATENSOR_H

#include "RankOneTensor.h"
#include <vector>
#include <string>

using namespace std;

class IoTDataTensor : public RankOneTensor<string> {
public:
    IoTDataTensor();

    // Returns the value at (row, col) converted to double
    double getValue(int row, int col);

    // Returns the column header (category) at index col
    string getCategory(int col);

    // Reads the file and populates the vectors
    void loadData() override;

    // Function to print all categories and data rows
    void display();

private:
    std::vector<string> iot_category;
    std::vector<RankOneTensor<string>> iot_data;
};

#endif