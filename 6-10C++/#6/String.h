#ifndef STRING_H
#define STRING_H

#include <cstring>

using namespace std;

class String
{
    char* str;
    int length;

public:
    String() : String("") {}
    String(const char* s)
    {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    ~String() { delete[] str; }

    // Перегрузка *
    String operator*(const String& other) const
    {
        char temp[1024] = "";
        int k = 0;
        
        for (int i = 0; i < length; ++i)
            {
            for (int j = 0; j < other.length; ++j)
                {
                if (str[i] == other.str[j])
                    {
                    // Проверка, чтобы не добавлять дубликаты в результат
                    if (!strchr(temp, str[i]))
                        {
                        temp[k++] = str[i];
                        temp[k] = '\0';
                    }
                    break;
                }
            }
        }
        return String(temp);
    }

    void display() const
    {
        cout << "String content: " << str << endl;
    }
};

#endif