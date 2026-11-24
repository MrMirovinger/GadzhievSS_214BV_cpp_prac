#include "DynamicArray.h"
#include <iostream>
#include <stdexcept>

bool DynamicArray::validIndex(int index) const {
    return index >= 0 && index < size;
}

bool DynamicArray::validValue(int value) const {
    return value >= -100 && value <= 100;
}

DynamicArray::DynamicArray(int count) {
    size = count;
    if (size < 0) {
        throw std::invalid_argument("Размер массива не может быть отрицательным.");
    }
    data = new int[size]{};
}

DynamicArray::DynamicArray(const DynamicArray& other) : DynamicArray(other.size) {
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

DynamicArray::~DynamicArray() {
    delete[] data;
}

void DynamicArray::print() const {
    std::cout << '{';
    for (int i = 0; i < size; ++i) {
        if (i > 0) {
            std::cout << ", ";
        }
        std::cout << data[i];
    }
    std::cout << "}\n";
}

void DynamicArray::set(int index, int value) {
    if (!validIndex(index)) {
        throw std::out_of_range("Индекс вне массива.");
    }
    if (!validValue(value)) {
        throw std::invalid_argument("Значение должно быть от -100 до 100.");
    }
    data[index] = value;
}

int DynamicArray::get(int index) const {
    if (!validIndex(index)) {
        throw std::out_of_range("Индекс вне массива.");
    }
    return data[index];
}

void DynamicArray::append(int value) {
    if (!validValue(value)) {
        throw std::invalid_argument("Значение должно быть от -100 до 100.");
    }
    int* newData = new int[size + 1];
    for (int i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    newData[size] = value;
    delete[] data;
    data = newData;
    ++size;
}

void DynamicArray::add(const DynamicArray& other) {
    for (int i = 0; i < size && i < other.size; ++i) {
        data[i] += other.data[i];
    }
}

void DynamicArray::subtract(const DynamicArray& other) {
    for (int i = 0; i < size && i < other.size; ++i) {
        data[i] -= other.data[i];
    }
}
