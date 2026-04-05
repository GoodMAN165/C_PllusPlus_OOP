#pragma once

#include <cstring>

using namespace std;

class String
{
    char* str;
    int length;

public:
    // Конструктор по умолчанию
    String()
    {
        length = 80;
        str = new char[length + 1];
        str[0] = '\0';
    }

    // Конструктор произвольного размера
    String(int size)
    {
        length = size;
        str = new char[length + 1];
        str[0] = '\0';
    }

    // Инициализация строкой пользователя
    String(const char* userStr)
    {
        length = strlen(userStr);
        str = new char[length + 1];
        strcpy(str, userStr);
    }

    // Конструктор копирования
    String(const String& other)
    {
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
    }

    // Деструктор
    ~String() {
        delete[] str;
    }

    // Ввод строки с клавиатуры
    void input()
    {
        cout << "Enter string: ";
        cin.getline(str, length + 1);
    }

    // Вывод строки на экран
    void output() const
    {
        cout << "String content: " << str << endl;
    }
};