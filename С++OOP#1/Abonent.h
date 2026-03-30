#ifndef ABONENT_H
#define ABONENT_H

using namespace std;

class Abonent
{
    char* fullName;
    char homePhone[20];
    char workPhone[20];
    char mobilePhone[20];
    char info[100];

public:
    // Конструктор
    Abonent(const char* name = "None", const char* h = "0", const char* w = "0", const char* m = "0", const char* i = "None")
    {
        fullName = new char[strlen(name) + 1];
        strcpy(fullName, name);
        strcpy(homePhone, h);
        strcpy(workPhone, w);
        strcpy(mobilePhone, m);
        strcpy(info, i);
    }

    // Деструктор 
    ~Abonent()
    {
        delete[] fullName; // Освобождение памяти 
    }

    // Aункция вывода
    inline void print() const
    {
        cout << "ФИО: " << fullName << " | Моб: " << mobilePhone << " | Инфо: " << info << std::endl;
    }

    // Геттеры
    const char* getName() const { return fullName; }
    
    void saveToFile(ofstream& out) const {
        out << fullName << "\n" << homePhone << "\n" << workPhone << "\n" << mobilePhone << "\n" << info << "\n";
    }
};

#endif