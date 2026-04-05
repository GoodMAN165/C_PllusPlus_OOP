#pragma once

#include <string>

using namespace std;

class Book
{
    string author;
    string title;
    string publisher;
    int year;
    int pages;

public:
    // Explicit конструктор
    explicit Book(string a = "", string t = "", string p = "", int y = 0, int pg = 0) 
        : author(a), title(t), publisher(p), year(y), pages(pg) {}

    // Функция отображения 
    void display() const
    {
        cout << "Author: " << author << " | Title: " << title 
             << " | Publisher: " << publisher << " | Year: " << year << endl;
    }

    // Геттеры
    string getAuthor() const { return author; }
    string getPublisher() const { return publisher; }
    int getYear() const { return year; }
};