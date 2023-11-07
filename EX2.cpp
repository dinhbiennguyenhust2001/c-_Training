#include <iostream>

template<typename T>
bool importData(T*** pArr, int nRow, int nCol) {
    pArr = new T*[nRow];
    for (int i = 0; i < nRow; i++) {
        pArr[i] = new T[nCol];
    }

    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            std::cin >> pArr[i][j];
        }
    }
    // Assuming input always succeeds for this example
    return true; 
}

template<typename T>
T** add2Matrix(T** pArr1, T** pArr2, int nRow, int nCol) {
    T** result = new T*[nRow];
    for (int i = 0; i < nRow; i++) {
        result[i] = new T[nCol];
        for (int j = 0; j < nCol; j++) {
            result[i][j] = pArr1[i][j] + pArr2[i][j];
        }
    }
    return result;
}

template<typename T>
void printMatrix(T** pArr, int nRow, int nCol) {
    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            std::cout << pArr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template<typename T>
void freeMem(T**& pArr, int nRow, int nCol) {
    for (int i = 0; i < nRow; i++) {
        delete[] pArr[i];
    }
    delete[] pArr;
    pArr = nullptr;
}

int main() {
    int** pArr1;
    int** pArr2;

    int nRow, nCol;
    std::cout << "Enter number of rows: ";
    std::cin >> nRow;
    std::cout << "Enter number of columns: ";
    std::cin >> nCol;

    std::cout << "Enter elements for matrix 1:" << std::endl;
    importData(&pArr1, nRow, nCol);

    std::cout << "Enter elements for matrix 2:" << std::endl;
    importData(&pArr2, nRow, nCol);

    int** resultMatrix = add2Matrix(pArr1, pArr2, nRow, nCol);

    std::cout << "Resultant matrix after addition:" << std::endl;
    printMatrix(resultMatrix, nRow, nCol);

    freeMem(pArr1, nRow, nCol);
    freeMem(pArr2, nRow, nCol);
    freeMem(resultMatrix, nRow, nCol);

    return 0;
}