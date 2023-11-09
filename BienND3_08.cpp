#include <iostream>
#include <stdexcept>

template <class T>
class Stack {
private:
    T* stackArray;     // Con trỏ để lưu mảng động
    int capacity;      // Kích thước tối đa của stack
    int size;          // độ dài của stack
public:
    // Constructor với capacity mặc định là 100
    Stack(int capacity = 100) {
        stackArray = new T[capacity]; // Cấp phát bộ nhớ cho mảng
        size =0;
    }

    // Destructor giải phóng bộ nhớ
    ~Stack() {
        delete[] stackArray;
    }

    //Thêm một phần tử vào ngăn xếp
    void Push(const T& item) {
        if (size >= capacity - 1) {
            T* newStack = stackArray;
            stackArray = new T[capacity * 2];
            for (int i = 0; i < capacity; ++i) {
                stackArray[i] = newStack[i];
            }
            delete[] newStack;
            capacity *= 2;
        }
        stackArray[size] = item;
        size++;

    }

    //loại bỏ phần tử trên cùng của ngăn xếp
    void Pop() {
    if (size == 0) {
        throw std::out_of_range("Stack<>::Pop(): empty stack");
    }
        size--;
    }

    // lấy giá trị của phần tử trên cùng mà không loại bỏ nó khỏi ngăn xếp
    T Top() const {
    if (size == 0) {
        throw std::out_of_range("Stack<>::Top(): empty stack");
    }
        return stackArray[size-1];
    }
};

int main() {
    Stack<int> intStack; // Tạo một ngăn xếp với kiểu dữ liệu int
        try {
        intStack.Push(10);
        intStack.Push(20);
        std::cout << "Top element is: " << intStack.Top() << std::endl;

        intStack.Pop();
        std::cout << "Top element after pop is: " << intStack.Top() << std::endl;
        } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}