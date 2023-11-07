#include <iostream>

template<typename T>
T* get_even_num(T* arr, int size, int* sz) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            count++;
        }
    }

    *sz = count;
    T* even_arr = new T[count];

    int j = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            even_arr[j] = arr[i];
            j++;
        }
    }
    return even_arr;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int even_size;

    int* even_arr = get_even_num(arr, size, &even_size);
    std::cout << "Even numbers are: ";
    for (int i = 0; i < even_size; i++) {
        std::cout << even_arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] even_arr;
    return 0;
}