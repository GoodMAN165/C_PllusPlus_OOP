#include <iostream>
#include "Circle.h"
#include "Airplane.h"

using namespace std;

int main()
{
    // Задания 1
    cout << "Circle \n";
    Circle c1(10.0);
    Circle c2(12.0);

    cout << "Circle 1 radius: " << c1.getRadius() << endl;
    cout << "Circle 2 radius: " << c2.getRadius() << endl;

    // Оператор >
    if (c2 > c1)
        {
        cout << "Circle 2 is larger than Circle 1 \n";
    }

    // Оператор +=
    c1 += 2.0;
    cout << "After c1 += 2.0, "; c1.printInfo();

    // Оператор ==
    if (c1 == c2)
        {
        cout << "Now Circle 1 and Circle 2 are equal! \n";
    }
    cout << endl;

    // Задания 2
    cout << "Airplane \n";
    Airplane plane1("Boeing 737", 150);
    Airplane plane2("Boeing 737", 200);
    Airplane plane3("Airbus A320", 180);

    // Оператор ==
    if (plane1 == plane2)
    {
        cout << "Plane 1 and Plane 2 have the same type. \n";
    }

    // Оператор >
    if (plane3 > plane1)
    {
        cout << "Airbus A320 has more capacity than Boeing 737. \n";
    }

    // Операторы ++ и --
    cout << "Boarding passengers to Plane 1... \n";
    ++plane1; // 1 пассажир
    ++plane1; // 2 пассажира
    plane1.printInfo();

    --plane1; // 1 пассажир вышел
    cout << "After one passenger left: ";
    plane1.printInfo();

    return 0;
}