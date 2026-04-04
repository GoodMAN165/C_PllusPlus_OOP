#include <iostream>
#include "Geometry.h"
#include "Point.h"
#include "Student.h"

using namespace std;

int main() {

    cout << "Geometry \n";
    cout << "Triangle Area: " << Geometry::triangleArea(10, 5) << endl;
    cout << "Rectangle Area: " << Geometry::rectangleArea(4, 8) << endl;
    cout << "Calculations made: " << Geometry::getCalculationCount() << endl;


    cout << "\nPoint Stats \n";
    Point p1;
    Point p2(10, 20);
    p1.display();
    cout << "Active points: " << Point::getPointCount() << endl;


    cout << "\nStudent Stats \n";
    Student s1("Alice");
    cout << "Active students: " << Student::getStudentCount() << endl;

    return 0;
}