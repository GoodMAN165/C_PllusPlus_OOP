#include <iostream>
#include "String.h"

using namespace std;

int main() {

    String s1("OOP Developer");
    String s2;

    cout << "String \n";
    s1.display();

    cout << "Active string objects: " << String::getObjectCount() << endl;

    // Ввод данных пользователем
    cout << "\nUpdating string:" << endl;
    s2.input();
    s2.display();

    return 0;
}