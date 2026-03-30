#ifndef LIFT_H
#define LIFT_H

using namespace std;

class Lift
{
    int minFloor;
    int maxFloor;
    int currentFloor;
    bool isPowered;

public:
    // Конструктор
    Lift(int min = 1, int max = 5) 
        : minFloor(min), maxFloor(max), currentFloor(min), isPowered(false) {}

    // Установка диапазона движения
    void setRange(int min, int max)
    {
        minFloor = min;
        maxFloor = max;
        if (currentFloor < minFloor) currentFloor = minFloor;
    }

    // Включение и выключение лифта
    void turnOn() { isPowered = true; }
    void turnOff() { isPowered = false; }

    // Возврат текущего состояния и положения
    bool getStatus() const { return isPowered; }
    int getCurrentFloor() const { return currentFloor; }

    // Обработка вызова лифта на этаж
    void call(int floor)
    {
        if (!isPowered) {
            cout << "SYSTEM: Lift is currently OFF." << endl;
            return;
        }
        if (floor < minFloor || floor > maxFloor) {
            cout << "ERROR: Floor " << floor << " is out of range!" << endl;
            return;
        }
        
        cout << "MOVING: From floor " << currentFloor << " to " << floor << "..." << endl;
        currentFloor = floor;
        cout << "STATUS: Lift arrived at floor " << currentFloor << "." << endl;
    }
};

#endif