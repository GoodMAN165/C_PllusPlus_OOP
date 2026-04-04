#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>

using namespace std;

class String
{

    char* str;
    int length;
    static int objectCount;

public:
    // Конструктор, произвольный размер
    String(int size) {
        length = size;
        str = new char[length + 1];
        str[0] = '\0';
        objectCount++;
    }

    // 2. Конструктор по умолчанию
    String() : String(80) {}

    // 3. Конструктор с строкой пользователя
    String(const char* userStr) {
        length = static_cast<int>(strlen(userStr));
        str = new char[length + 1];
        strcpy(str, userStr);
        objectCount++;
    }

    // Деструктор
    ~String() {
        delete[] str;
        objectCount--;
    }

    // Функция ввода
    void input() {
        char buffer[1024];
        cout << "Enter string text: ";
        

        if (cin.peek() == '\n') cin.ignore();
        cin.getline(buffer, 1023);

        delete[] str; // Удаляем старые данные
        length = static_cast<int>(strlen(buffer));
        str = new char[length + 1];
        strcpy(str, buffer);
    }

    // Вывода строки
    void display() const {
        if (str) {
            cout << "Value: " << str << " | Length: " << length << endl;
        }
    }

    // Получение счётчика
    static int getObjectCount() {
        return objectCount;
    }
};

int String::objectCount = 0;

#endif