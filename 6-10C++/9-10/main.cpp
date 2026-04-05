#include <iostream>
#include "Var.h"
#include "Complex.h"
#include "Time.h"
#include "Array.h"

int main() {
    // Var
    var a = 15, d = "50";
    var b = a + d;
    cout << "Var sum: "; b.Show();

    // Complex
    Complex c1(2, 3), c2(1, 2);
    cout << "Complex sum: " << (c1 + c2) << endl;

    // Time
    Time t1(23, 59, 59);
    ++t1;
    cout << "Time after ++: " << t1 << endl;

    return 0;
}