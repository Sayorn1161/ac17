#include <cctype>

class BitString : public String {
public:
    BitString() : String() {}

    BitString(const char* s) : String(s) {
        if (!isValidBitString()) {
            clear(); 
        }
    }

    BitString(const BitString& other) : String(other) {}

    BitString& operator=(const BitString& other) {
        String::operator=(other);
        return *this;
    }

    ~BitString() {}

    bool isValidBitString() const {
        for (size_t i = 0; i < length; i++) {
            if (str[i] != '0' && str[i] != '1') {
                return false;
            }
        }
        return true;
    }

    void negate() {
        for (size_t i = 0; i < length; i++) {
            str[i] = (str[i] == '0') ? '1' : '0';
        }
        bool carry = true;
        for (int i = length - 1; i >= 0 && carry; i--) {
            if (str[i] == '0') {
                str[i] = '1';
                carry = false;
            } else {
                str[i] = '0';
            }
        }
    }

    BitString operator+(const BitString& other) const {
        BitString result(*this);
        result += other;
        return result;
    }

    BitString& operator+=(const BitString& other) {
        *this = *this + other;
        return *this;
    }

    bool operator==(const BitString& other) const {
        return String::operator==(other);
    }

    bool operator!=(const BitString& other) const {
        return !(*this == other);
    }

    void print() const {
        if (str != nullptr) {
            std::cout << "BitString: " << str;
        } else {
            std::cout << "BitString: (empty string)";
        }
    }
};

int main() {
    String s1("Hello");
    String s2("World");
    String s3 = s1 + s2; 
    s1 += s2; 

    std::cout << "String 1: ";
    s1.print();
    std::cout << "\nString 2: ";
    s2.print();
    std::cout << "\nConcatenated String: ";
    s3.print();
    std::cout << "\n";

    BitString bs1("1101");
    BitString bs2("0110");
    BitString bs3 = bs1 + bs2;

    std::cout << "\nBitString 1: ";
    bs1.print();
    std::cout << "\nBitString 2: ";
    bs2.print();
    std::cout << "\nConcatenated BitString: ";
    bs3.print();
    std::cout << "\n";

    std::cout << "\nNegating BitString 1...\n";
    bs1.negate();
    bs1.print();
    std::cout << "\n";

    return 0;
}
