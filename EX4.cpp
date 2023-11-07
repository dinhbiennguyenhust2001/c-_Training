#include <iostream>
using namespace std;

int findsubstr(const char *str, const char *sub) {
    if (str == nullptr || sub == nullptr) return -1; // Check for null pointers.

    const char *pStr = str;  // Pointer to iterate over str.
    const char *pSub;        // Pointer to iterate over sub.
    const char *pFound;      // Pointer to remember start of match.

    // Loop over str.
    for (pStr; *pStr != '\0'; ++pStr) {
        pSub = sub;
        pFound = pStr;

        // Loop over sub.
        while (*pStr == *pSub && *pSub != '\0') {
            ++pStr;
            ++pSub;
        }

        // If end of sub is reached, match is found.
        if (*pSub == '\0') {
            return pFound - str;  // Return the starting index.
        }

        pStr = pFound; // Reset pStr to check for match starting at next char in str.
    }

    return -1;  // Substring not found.
}

int main() {
    const char *str = "Hello, world!";
    const char *sub = "world";

    int position = findsubstr(str, sub);

    if (position != -1) {
        cout << "Substring '" << sub << "' found at position " << position << endl;
    } else {
        cout << "Substring '" << sub << "' not found." << endl;
    }

    return 0;
}