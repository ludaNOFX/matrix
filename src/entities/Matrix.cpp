#include "Matrix.h"
#include <iostream>

Matrix::Matrix(int N) {
    this->N = N; // указатель на текущий атрибут класса

    data = new int*[N]; // выделение памяти для квадратной матрицы

    for (int i = 0; i < N; i++){
        data[i] = new int[N]; // выделение памяти для каждого ряда
    }
    int count = 0;
    // Инициализация матрицы 
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            count++;
            data[i][j] = count;
        }
    }
}

// Деструктор~!!!

Matrix::~Matrix() {
    for (int i = 0; i < N; ++i) {
        delete[] data[i]; // Очистка памяти для каждого ряда
    }
    delete[] data; // Очистка памяти для основного массива
}

void Matrix::setElement(int row, int col, int value) {
    data[row][col] = value; // реализация метода setElement
}

int Matrix::getElement(int row, int col) const {
    return data[row][col]; // реализация метода getElement
}

int Matrix::print() const {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << data[i][j] << " "; // вывод каждого элемента
        }
        std::cout << std::endl;
    }
    return 1;
}


