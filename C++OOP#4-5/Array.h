#pragma once

#include <algorithm>

using namespace std;

class Array
{
    int* data;
    int size;

public:
    // Конструктор
    explicit Array(int s = 10)
    {
        size = s;
        data = new int[size]{0};
    }

    // Конструктор копирования
    Array(const Array& other)
    {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++) data[i] = other.data[i];
    }

    // Деструктор
    ~Array()
    {
        delete[] data;
    }

    // Заполнение массива
    void fill()
    {
        for (int i = 0; i < size; i++) data[i] = rand() % 100;
    }

    // Изменение размера массива
    void resize(int newSize)
    {
        int* newData = new int[newSize]{0};
        int minSize = (size < newSize) ? size : newSize;
        for (int i = 0; i < minSize; i++) newData[i] = data[i];
        delete[] data;
        data = newData;
        size = newSize;
    }

    // Сортировка массива
    void sort()
    {
        std::sort(data, data + size);
    }

    // Поиск минимального значения
    int getMin() const
    {
        int minVal = data[0];
        for (int i = 1; i < size; i++) if (data[i] < minVal) minVal = data[i];
        return minVal;
    }

    // Поиск максимального значения
    int getMax() const
    {
        int maxVal = data[0];
        for (int i = 1; i < size; i++) if (data[i] > maxVal) maxVal = data[i];
        return maxVal;
    }

    // Отображение содержимого
    void display() const
    {
        for (int i = 0; i < size; i++) cout << data[i] << " ";
        cout << endl;
    }
};