#include <iostream>
#include <cstring>

class String {
private:
    char* str;

public:
    //Default constructor
    String() : str(new char[1]) {
        str[0] = '\0';
    }

    //Parameter constructor
    String(const char* s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    // Copy constructor, copy string
    String(const String& other) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }

    // Destructor
    ~String() {
        delete[] str;
    }
    // Overloading operator "+"
    friend String operator+(const String& lhs, const String& rhs) {
        String result;
        result.str = new char[strlen(lhs.str) + strlen(rhs.str) + 1];
        strcpy(result.str, lhs.str); 
        strcat(result.str, rhs.str);
        return result;
    }

    String& operator=(const String& other) {
    if (this != &other) { 
        delete[] str;
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str); 
    }
    return *this; 
}

    friend std::istream& operator>>(std::istream& is, String& string) {
        char buffer[2048]; 
        is >> buffer;
        delete[] string.str; 
        string.str = new char[strlen(buffer) + 1];
        strcpy(string.str, buffer); 
        return is; 
    }

    friend std::ostream& operator<<(std::ostream& os, const String& string) {
        os << string.str; 
        return os;
    }
};

int main() {
    String s1, s2, s3;
    
    std::cout << "Enter first string: ";
    std::cin >> s1;
    
    std::cout << "Enter second string: ";
    std::cin >> s2;
    
    s3 = s1 + s2;
    
    std::cout << "Concatenated string: " << s3 << std::endl;
    
    return 0;
}