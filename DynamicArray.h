#pragma once

class DynamicArray {
private:
    int size;
    int* data;
    bool validIndex(int index) const;
    bool validValue(int value) const;
public:
    explicit DynamicArray(int count);

    DynamicArray(const DynamicArray& other);

    DynamicArray& operator=(const DynamicArray&) = delete;

    ~DynamicArray();

    void print() const;

    void set(int index, int value);

    int get(int index) const;

    void append(int value);

    void add(const DynamicArray& other);

    void subtract(const DynamicArray& other);
};
