#include <iostream>
#include "Date.h"
#include "String.h"

using namespace std;

int main() {
    // Задания 1
    cout << "Dates \n";
    Date d1(10, 5, 2024);
    Date d2(20, 5, 2024);

    cout << "Date 1: "; d1.display();
    cout << "Date 2: "; d2.display();
    cout << "Difference in days: " << d2 - d1 << endl;

    Date d3 = d1 + 45;
    cout << "Date 1 + 45 days: "; d3.display();

    // Задания 2
    cout << "\nString";
    String s1("sdqcg");
    String s2("rgfas34");

    String result = s1 * s2;
    cout << "String 1: "; s1.display();
    cout << "String 2: "; s2.display();
    cout << "Result of intersection: "; result.display(); // Должно вывести "sg"

    return 0;
}