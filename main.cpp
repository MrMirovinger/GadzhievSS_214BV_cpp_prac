#include "DynamicArray.h"
#include <iostream>

int main() {
    DynamicArray a(3);
    a.set(0, 10);
    a.set(1, 20);
    a.set(2, 30);
    std::cout << "Исходный массив: ";
    a.print();
    std::cout << "Элемент с индексом 1: " << a.get(1) << '\n';

    DynamicArray copy(a);
    copy.set(0, -100);
    copy.append(100);
    std::cout << "Копия после изменений: ";
    copy.print();
    std::cout << "Исходный массив после изменений копии: ";
    a.print();

    DynamicArray b(2);
    b.set(0, 1);
    b.set(1, 2);
    a.add(b);
    std::cout << "После прибавления {1, 2}: ";
    a.print();
    a.subtract(b);
    std::cout << "После вычитания {1, 2}: ";
    a.print();

    std::cout << "Проверка ошибочного ввода:\n";
    a.set(3, 5);
    a.get(-1);
    a.set(0, 101);
    a.append(-101);
    std::cout << "Массив после проверок: ";
    a.print();
}
