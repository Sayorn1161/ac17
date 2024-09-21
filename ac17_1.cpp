#include <iostream>
#include <cstring> 

class String {
protected:
    char* str; 
    size_t length; 
public:
    String() : str(nullptr), length(0) {}

    String(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    String(const String& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
    }

    String& operator=(const String& other) {
        if (this == &other) {
            return *this;
        }
        delete[] str;
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
        return *this;
    }

    size_t getLength() const {
        return length;
    }

    void clear() {
        delete[] str;
        str = nullptr;
        length = 0;
    }

    virtual ~String() {
        delete[] str;
    }

    String operator+(const String& other) const {
        size_t newLength = length + other.length;
        char* newStr = new char[newLength + 1];

        strcpy(newStr, str);
        strcat(newStr, other.str);

        return String(newStr);
    }

    String& operator+=(const String& other) {
        *this = *this + other;
        return *this;
    }

    bool operator==(const String& other) const {
        return strcmp(str, other.str) == 0;
    }

    bool operator!=(const String& other) const {
        return !(*this == other);
    }

    void print() const {
        if (str != nullptr) {
            std::cout << str;
        } else {
            std::cout << "(empty string)";
        }
    }
};
