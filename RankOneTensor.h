#ifndef RANKONETENSOR_H_
#define RANKONETENSOR_H_

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept> 
#include "BaseTensor.h"

using namespace std;

template <typename T>
class RankOneTensor : public BaseTensor {
private:
    vector<T> data;

public:
    RankOneTensor();
    RankOneTensor(int size);
    RankOneTensor(const RankOneTensor<T>& other);
    ~RankOneTensor() = default;

    void loadData() override;
    void insertData(T item);
    int getSize() const;

    // --- Operators ---

    T& operator[](int index);
    const T& operator[](int index) const;
    RankOneTensor<T>& operator=(const RankOneTensor<T>& other);
    bool operator==(const RankOneTensor<T>& other) const;

    // Math
    RankOneTensor<T> operator+(T scalar);
    RankOneTensor<T> operator-(T scalar);
    RankOneTensor<T> operator*(T scalar);
    RankOneTensor<T> operator+(const RankOneTensor<T>& other);
    RankOneTensor<T> operator-(const RankOneTensor<T>& other);
    RankOneTensor<T> operator*(const RankOneTensor<T>& other);

    // Increment
    RankOneTensor<T>& operator++();    // Prefix (++t)
    RankOneTensor<T> operator++(int);  // Postfix (t++) 

    // IO
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const RankOneTensor<U>& tensor);

    template <typename U>
    friend std::istream& operator>>(std::istream& in, RankOneTensor<U>& tensor);
};

#endif /* RANKONETENSOR_H_ */