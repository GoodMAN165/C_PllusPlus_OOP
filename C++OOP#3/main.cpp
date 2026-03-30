#include <iostream>
#include "Lift.h"
#include "Wallpaper.h"

int main() {
    cout << "Lift" << endl;
    Lift myLift(1, 12); // Лифт с 1 по 12 этаж
    myLift.turnOn();
    myLift.call(5);
    myLift.call(10);
    cout << "Current location: Floor " << myLift.getCurrentFloor() << endl;
    cout << "-------------------------\n" << endl;

    // Обои
    cout << "Wallpaper" << endl;
    Apartment myApartment;
    int roomCount;
    cout << "How many rooms are in the apartment? ";
    cin >> roomCount;

    for (int i = 0; i < roomCount; ++i) {
        cout << "\nData for room #" << i + 1 << ":" << endl;
        Room r;
        r.input();
        myApartment.addRoom(r);
    }

    cout << "\nSet wallpaper parameters:" << endl;
    WallpaperRoll myRoll;
    myRoll.input();

    myApartment.calculateTotal(myRoll);

    return 0;
}