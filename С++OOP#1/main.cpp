#include <iostream>
#include <cstring>
#include <fstream>
#include <windows.h>

#include "Fraction.h"
#include "Abonent.h"

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    // Тест Встречи №1
    cout << "Дроби\n";
    Fraction f1, f2;
    f1.input();
    f2.input();
    Fraction sum = f1.add(f2);
    cout << "Сумма: "; sum.display(); cout << "\n\n";

    // Тест Встречи №2
    cout << "Телефонная Книга\n";
    Abonent contact("Иванов Иван", "12-34", "56-78", "+79991234567", "Друг");
    contact.print();

    return 0;
}