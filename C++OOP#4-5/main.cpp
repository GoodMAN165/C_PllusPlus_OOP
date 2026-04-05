#include <iostream>
#include "String.h"
#include "Array.h"
#include "Book.h"
#include "Worker.h"

using namespace std;

int main()
{
    // String
    String s("Lab Work 4");
    s.output();

    // Array
    Array arr(5);
    arr.fill();
    arr.sort();
    cout << "Max in array: " << arr.getMax() << endl;

    // Worker
    Worker staff[2] = {
        Worker("Ivanov I.I.", "Developer", 2015, 5000),
        Worker("Petrov P.P.", "Manager", 2023, 3000)
    };

    cout << "\nWorkers with salary > 4000:" << endl;
    for(int i = 0; i < 2; i++) {
        if(staff[i].getSalary() > 4000) staff[i].display();
    }

    return 0;
}