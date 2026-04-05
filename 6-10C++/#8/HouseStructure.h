#pragma once

#include <string>

using namespace std;


class Person
{
    char* name;

public:
    explicit Person(const char* n)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    // Конструктор переноса
    Person(Person&& other) noexcept : name(other.name)
    {
        other.name = nullptr;
    }

    ~Person() { delete[] name; }
    
    void print() const { if(name) cout << name; }
};


class Apartment
{
    Person** residents;
    int count;

public:
    Apartment(int c) : count(c)
    {
        residents = new Person*[count];
        for (int i = 0; i < count; i++) residents[i] = nullptr;
    }

    // Конструктор переноса
    Apartment(Apartment&& other) noexcept
        : residents(other.residents), count(other.count) {
        other.residents = nullptr;
        other.count = 0;
    }

    ~Apartment()
    {
        if (residents)
        {
            for (int i = 0; i < count; i++) delete residents[i];
            delete[] residents;
        }
    }
};


class House
{
    Apartment* apartments;
    int apartmentCount;

public:
    explicit House(int count) : apartmentCount(count)
    {
        apartments = (Apartment*)operator new[](count * sizeof(Apartment));
    }

    // Конструктор переноса
    House(House&& other) noexcept 
        : apartments(other.apartments), apartmentCount(other.apartmentCount)
    {
        other.apartments = nullptr;
        other.apartmentCount = 0;
    }

    ~House()
    {
        delete[] apartments;
    }
};