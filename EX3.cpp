#include <iostream>

using namespace std;

// Define the arithmetic operations
float _plus(float a, float b) {
    return a + b;
}

float _minus(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    if (b != 0.0f) {
        return a / b;
    } else {
        cout << "Error: Division by zero." << endl;
        return 0.0f;
    }
}

// Function that takes a function pointer as an argument
void operation(float a, float b, float (*p2Func)(float, float)) {
    float result = p2Func(a, b);
    cout << "Result: " << result << endl;
}

int main() {
    float a, b;

    // 1. Input two float numbers
    cout << "Enter two numbers: ";
    cin >> a >> b;

    // 2. Call the operation(...) function to perform addition, subtraction, multiplication, and division
    cout << "Addition: ";
    operation(a, b, _plus);

    cout << "Subtraction: ";
    operation(a, b, _minus);

    cout << "Multiplication: ";
    operation(a, b, multiply);

    cout << "Division: ";
    operation(a, b, divide);

    return 0;
}