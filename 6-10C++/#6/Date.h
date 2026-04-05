#ifndef DATE_H
#define DATE_H

using namespace std;

class Date
{
    int day, month, year;

    // Проверка на высокосный год
    bool isLeap(int y) const
    {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    // Количество дней в конкретном месяце
    int daysInMonth(int m, int y) const
    {
        int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (m == 2 && isLeap(y)) return 29;
        return months[m - 1];
    }

    // Перевод даты
    long totalDays() const
    {
        long count = day;
        for (int y = 1; y < year; ++y) count += (isLeap(y) ? 366 : 365);
        for (int m = 1; m < month; ++m) count += daysInMonth(m, year);
        return count;
    }

public:
    Date(int d = 1, int m = 1, int y = 2000) : day(d), month(m), year(y) {}

    // Перегрузка -
    long operator-(const Date& other) const
    {
        return this->totalDays() - other.totalDays();
    }

    // Перегрузка +
    Date operator+(int days) const
    {
        Date res = *this;
        res.day += days;
        while (res.day > daysInMonth(res.month, res.year))
            {
            res.day -= daysInMonth(res.month, res.year);
            res.month++;
            if (res.month > 12)
                {
                res.month = 1;
                res.year++;
            }
        }
        return res;
    }

    void display() const
    {
        cout << (day < 10 ? "0" : "") << day << "." 
             << (month < 10 ? "0" : "") << month << "." << year << endl;
    }
};

#endif