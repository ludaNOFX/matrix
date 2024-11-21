#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
public:
    Matrix(int N); // Конструктор
    ~Matrix(); // Деструктор для очистки памяти
    void setElement(int row, int col, int value); // метод для установки значения
    int getElement(int row, int col) const; // метод для получения значения
    int print() const; // метод для вывода всей матрицы
    
private:
    int** data; // динамический массив для хранения матрицы
    int N; // переменная содержащая размерность матрицы
};

#endif // MATRIX_H