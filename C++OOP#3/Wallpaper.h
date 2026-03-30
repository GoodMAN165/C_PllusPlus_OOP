#ifndef WALLPAPER_H
#define WALLPAPER_H


#include <vector>
#include <string>
#include <cmath>

using namespace std;

// Класс для характеристик обоев
class WallpaperRoll
{
public:
    string name;
    double width;
    double length;
    double price;

    void input()
    {
        cout << "Enter wallpaper brand/name: "; cin >> name;
        cout << "Enter roll width (meters): "; cin >> width;
        cout << "Enter roll length (meters): "; cin >> length;
        cout << "Enter price per roll: "; cin >> price;
    }
};

// Класс для параметров комнаты
class Room
{
public:
    string name;
    double width, length, height;
    bool includeCeiling;

    void input()
    {
        cout << "Enter room type (e.g. Kitchen): "; cin >> name;
        cout << "Enter dimensions (Width Length Height): ";
        cin >> width >> length >> height;
        cout << "Do you need to wallpaper the ceiling? (1-Yes, 0-No): ";
        cin >> includeCeiling;
    }

    // Расчет площади поверхности
    double calculateArea() const {
        double wallArea = 2 * height * (width + length);
        if (includeCeiling) {
            wallArea += (width * length);
        }
        return wallArea;
    }
};

// Класс квартиры, объединяющий комнаты
class Apartment
{
    vector<Room> rooms;

public:
    void addRoom(const Room& r) { rooms.push_back(r); }

    // Итоговый расчет
    void calculateTotal(const WallpaperRoll& roll) {
        double totalArea = 0;
        for (const auto& room : rooms) {
            totalArea += room.calculateArea();
        }

        double rollArea = roll.width * roll.length;
        int rollsNeeded = std::ceil(totalArea / rollArea); // Округление вверх
        double totalCost = rollsNeeded * roll.price;

        cout << "\n=== FINAL ESTIMATE ===" << endl;
        cout << "Wallpaper: " << roll.name << endl;
        cout << "Total surface area: " << totalArea << " sq.m." << endl;
        cout << "Rolls required: " << rollsNeeded << endl;
        cout << "Total project cost: " << totalCost << endl;
    }
};

#endif