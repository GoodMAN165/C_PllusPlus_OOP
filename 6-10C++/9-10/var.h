#pragma once

#include <string>
#include <algorithm>

using namespace std;

class var
{
    enum Type { INT, DOUBLE, STRING } type;
    int i_val;
    double d_val;
    string s_val;

public:
    // Конструкторы
    var(int v) : type(INT), i_val(v), d_val(0) {}
    var(double v) : type(DOUBLE), d_val(v), i_val(0) {}
    var(const char* v) : type(STRING), s_val(v), i_val(0), d_val(0) {}
    var() : type(INT), i_val(0), d_val(0) {}

    void Show() const
    {
        if (type == INT) cout << i_val << endl;
        else if (type == DOUBLE) cout << d_val << endl;
        else cout << s_val << endl;
    }

    // Вспомогательные методы конвертации
    int asInt() const
    {
        if (type == INT) return i_val;
        if (type == DOUBLE) return (int)d_val;
        return stoi(s_val);
    }

    string asString() const
    {
        if (type == STRING) return s_val;
        if (type == INT) return to_string(i_val);
        return to_string(d_val);
    }

    // Перегрузка +
    var operator+(const var& other) const
    {
        if (type == INT) return var(this->i_val + other.asInt());
        if (type == STRING) return var((this->s_val + other.asString()).c_str());
        return var(this->d_val + (double)other.asInt());
    }

    // Операция * для строк
    var operator*(const var& other) const
    {
        if (type == STRING)
            {
            string res = "";
            string s2 = other.asString();
            for (char c : s_val) {
                if (s2.find(c) != string::npos && res.find(c) == string::npos) 
                    res += c;
            }
            return var(res.c_str());
        }
        return var(this->i_val * other.asInt());
    }

    // Перегрузка ==
    bool operator==(const var& other) const
    {
        if (type == STRING) return s_val == other.asString();
        return asInt() == other.asInt();
    }
};