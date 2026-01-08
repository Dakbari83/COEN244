#include "RankOneTensor.h"
#include "BaseTensor.h"

#include <iostream>
#include <vector>
#include <random>
#include <stdexcept> 
#include <string>

using namespace std;

// --- Constructors ---
template <typename T>
RankOneTensor<T>::RankOneTensor() : data(0) {}

template <typename T>
RankOneTensor<T>::RankOneTensor(int size) : data(size) {}

template <typename T>
RankOneTensor<T>::RankOneTensor(const RankOneTensor<T>& other) : data(other.data) {}

// --- Data Management ---
template <typename T>
void RankOneTensor<T>::insertData(T item) {
    data.push_back(item);
}

template <typename T>
int RankOneTensor<T>::getSize() const {
    return data.size();
}

// --- Load Data Specializations ---
template <>
void RankOneTensor<double>::loadData() {
    std::fill(data.begin(), data.end(), valueGen());
}

template <>
void RankOneTensor<string>::loadData() {
    std::fill(data.begin(), data.end(), std::to_string(valueGen()));
}

// --- Operator Overloading ---

template <typename T>
T& RankOneTensor<T>::operator[](int index) {
    if (index < 0 || index >= data.size()) throw std::out_of_range("Index out of range");
    return data[index];
}

template <typename T>
const T& RankOneTensor<T>::operator[](int index) const {
    if (index < 0 || index >= data.size()) throw std::out_of_range("Index out of range");
    return data[index];
}

template <typename T>
RankOneTensor<T>& RankOneTensor<T>::operator=(const RankOneTensor<T>& other) {
    if (this != &other) {
        if (data.size() > 0 && data.size() != other.data.size()) {
             throw std::invalid_argument("Assignment dimensions do not match");
        }
        data = other.data;
    }
    return *this;
}

template <typename T>
bool RankOneTensor<T>::operator==(const RankOneTensor<T>& other) const {
    if (data.size() != other.data.size()) throw std::invalid_argument("Size mismatch");
    for (size_t i = 0; i < other.data.size(); i++) {
        if (other.data[i] != data[i]) {
            throw std::invalid_argument("Value mismatch at index " + std::to_string(i));
        }
    }
    return true;
}

// --- Math Operators ---

// Scalar addition
template <typename T>
RankOneTensor<T> RankOneTensor<T>::operator+(T scalar) {
    RankOneTensor<T> result(data.size());
    for (size_t i = 0; i < data.size(); ++i) result.data[i] = data[i] + scalar;
    return result;
}

// Scalar subtraction
template <typename T>
RankOneTensor<T> RankOneTensor<T>::operator-(T scalar) {
    RankOneTensor<T> result(data.size());
    for (size_t i = 0; i < data.size(); ++i) {
        result.data[i] = data[i] - scalar; 
    }
    return result;
}

// Scalar multiplication
template <typename T>
RankOneTensor<T> RankOneTensor<T>::operator*(T scalar) {
    RankOneTensor<T> result(data.size());
    for (size_t i = 0; i < data.size(); ++i) result.data[i] = data[i] * scalar;
    return result;
}

template <typename T>
RankOneTensor<T> RankOneTensor<T>::operator+(const RankOneTensor<T>& other) {
    if (data.size() != other.data.size()) throw std::invalid_argument("Dimension mismatch");
    RankOneTensor<T> result(data.size());
    for (size_t i = 0; i < data.size(); ++i) result.data[i] = data[i] + other.data[i];
    return result;
}

template <typename T>
RankOneTensor<T> RankOneTensor<T>::operator-(const RankOneTensor<T>& other) {
    if (data.size() != other.data.size()) throw std::invalid_argument("Dimension mismatch");
    RankOneTensor<T> result(data.size());
    for (size_t i = 0; i < data.size(); ++i) result.data[i] = data[i] - other.data[i];
    return result;
}

template <typename T>
RankOneTensor<T> RankOneTensor<T>::operator*(const RankOneTensor<T>& other) {
    if (data.size() != other.data.size()) throw std::invalid_argument("Dimension mismatch");
    RankOneTensor<T> result(data.size());
    for (size_t i = 0; i < data.size(); ++i) result.data[i] = data[i] * other.data[i];
    return result;
}

// --- Increments ---

// Prefix (++t)
template <typename T>
RankOneTensor<T>& RankOneTensor<T>::operator++() {
    for (size_t i = 0; i < data.size(); ++i) data[i]++;
    return *this;
}

// Postfix (t++) 
// We make a copy, increment the original, and return the copy.
template <typename T>
RankOneTensor<T> RankOneTensor<T>::operator++(int) {
    RankOneTensor<T> temp = *this; // Copy current state
    ++(*this);                     // Use prefix to increment
    return temp;                   // Return old state
}

// --- IO Stream ---
template <typename U>
std::ostream& operator<<(std::ostream& os, const RankOneTensor<U>& tensor) {
    os << "Data: [";
    for (size_t i = 0; i < tensor.data.size(); ++i) {
        os << tensor.data[i];
        if (i < tensor.data.size() - 1) os << ", ";
    }
    os << "]" << endl;
    return os;
}

template <typename U>
std::istream& operator>>(std::istream& in, RankOneTensor<U>& tensor) {
    U value;
    while (in >> value) tensor.data.push_back(value);
    return in;
}

// ============================================================
// SPECIALIZATIONS FOR STRING
// These are required to prevent compile-time errors because 
// std::string does not support -, *, or ++ natively.
// ============================================================

template <>
RankOneTensor<string> RankOneTensor<string>::operator-(const RankOneTensor<string>& other) {
    throw std::logic_error("Subtraction not defined for string tensors.");
}

template <>
RankOneTensor<string> RankOneTensor<string>::operator-(string scalar) {
    throw std::logic_error("Scalar subtraction is not defined for string tensors.");
}

template <>
RankOneTensor<string> RankOneTensor<string>::operator*(const RankOneTensor<string>& other) {
    throw std::logic_error("Multiplication not defined for string tensors.");
}

template <>
RankOneTensor<string> RankOneTensor<string>::operator*(string scalar) {
    throw std::logic_error("Scalar multiplication not defined for string tensors.");
}

template <>
RankOneTensor<string>& RankOneTensor<string>::operator++() {
    throw std::logic_error("Prefix increment not defined for string tensors.");
}

template <>
RankOneTensor<string> RankOneTensor<string>::operator++(int) {
    throw std::logic_error("Postfix increment not defined for string tensors.");
}

// Note: operator+ works for strings (Concatenation), so we don't specialize/disable it.

// --- EXPLICIT INSTANTIATION ---
template class RankOneTensor<double>;
template class RankOneTensor<std::string>;

template std::ostream& operator<<(std::ostream& os, const RankOneTensor<double>& tensor);
template std::ostream& operator<<(std::ostream& os, const RankOneTensor<std::string>& tensor);
template std::istream& operator>>(std::istream& in, RankOneTensor<double>& tensor);
template std::istream& operator>>(std::istream& in, RankOneTensor<std::string>& tensor);