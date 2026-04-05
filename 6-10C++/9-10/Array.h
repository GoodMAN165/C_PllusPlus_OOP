#pragma once

#include <string>
#include <sstream>

using namespace std;

class Array
{
    int* data;
    int size;

public:
    explicit Array(int s = 5) : size(s)
    {
        data = new int[size]{0};
    }

    // Деструктор
    ~Array() { delete[] data; }

    // Заполнение случайными числами
    void fill()
    {
        for (int i = 0; i < size; i++) data[i] = rand() % 50;
    }

    // [] - Возвращает элемент по индексу
    int& operator[](int index)
    {
        if (index >= 0 && index < size) return data[index];
        return data[0];
    }

    // () - Увеличивает все элементы на указанную величину
    void operator()(int value)
    {
        for (int i = 0; i < size; i++) data[i] += value;
    }

    // Преобразование к int: возвращает сумму элементов
    operator int() const
    {
        int sum = 0;
        for (int i = 0; i < size; i++) sum += data[i];
        return sum;
    }

    // Преобразование к char*: возвращает элементы в виде строки
    operator char*() const
    {
        stringstream ss;
        for (int i = 0; i < size; i++)
        {
            ss << data[i] << (i == size - 1 ? "" : ", ");
        }
        string temp = ss.str();
        char* res = new char[temp.length() + 1];
        strcpy(res, temp.c_str());
        return res;
    }

    void display() const
    {
        for (int i = 0; i < size; i++) cout << data[i] << " ";
        cout << endl;
    }
};