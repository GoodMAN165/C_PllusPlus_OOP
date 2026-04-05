#pragma once

#include <iomanip>

using namespace std;

class Time
{
    int hours, minutes, seconds;

    void normalize()
    {
        if (seconds >= 60) { minutes += seconds / 60; seconds %= 60; }
        if (minutes >= 60) { hours += minutes / 60; minutes %= 60; }
        hours %= 24;
    }

public:
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {
        normalize();
    }

    // Приращение на 1 секунду
    void addSecond()
    {
        seconds++;
        normalize();
    }

    // Префиксный инкремент
    Time& operator++()
    {
        addSecond();
        return *this;
    }

    // Оператор +=
    Time& operator+=(int s)
    {
        seconds += s;
        normalize();
        return *this;
    }

    // Сравнение
    bool operator==(const Time& other) const
    {
        return hours == other.hours && minutes == other.minutes && seconds == other.seconds;
    }

    // Дружественный вывод
    friend ostream& operator<<(ostream& os, const Time& t)
    {
        os << setfill('0') << setw(2) << t.hours << ":" 
           << setw(2) << t.minutes << ":" << setw(2) << t.seconds;
        return os;
    }
};