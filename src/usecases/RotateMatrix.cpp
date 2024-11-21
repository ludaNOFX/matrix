#include "RotateMatrix.h"
#include <iostream>

using namespace std;

void RotateMatrix::rotate(Matrix& matrix, int step, int layer, int sz) {
    int perimeterLength = 4 * (sz - 1 - layer); // определяем длину периметра учитывая слой в котором находимся
    step = step % perimeterLength; // шаг не может быть длинее чем длина периметра

    int perimeter[perimeterLength] = {}; // создаем статический массив для периметра
    int index = 0; // индекс для массива perimeter

    // Верхняя строка - берем элемент из объекта матрицы
    for (int i = layer; i < sz-1; i++) {
        perimeter[index] = matrix.getElement(layer, i);
        index++;
    }

    // Правый столбец - берем элемент из объекта матрицы
    for (int i = layer; i < sz-1; i++) {
        perimeter[index] = matrix.getElement(i, sz-1);
        index++;
    }

    // Нижняя строка справа налево - берем элемент из объекта матрицы
    for (int i = sz - 1; i > 0 + layer; i--) {
        perimeter[index] = matrix.getElement(sz-1, i);
        index++;
    }

    // Левый столбец снизу вверх - берем элемент из объекта матрицы
    for (int i = sz - 1; i > 0 + layer; i--) {
        perimeter[index] = matrix.getElement(i, layer);
        index++;
    }

    int rotatedPerimeter[perimeterLength] = {}; // создаем статический массив для ротации периметра
    for (int i = 0; i < perimeterLength; i++) {
        rotatedPerimeter[(i+step)%perimeterLength] = perimeter[i];
    }


    index = 0;

    // Верхняя строка - вставляем элемент в объект матрица
    for (int i = layer; i < sz-1; i++) {
        matrix.setElement(layer, i, rotatedPerimeter[index]);
        index++;
    }

    // Правый столбец - вставляем элемент в объект матрица
    for (int i = layer; i < sz-1; i++) {
        matrix.setElement(i, sz - 1, rotatedPerimeter[index]);
        index++;
    }

    // Нижняя строка справа налево - - вставляем элемент в объект матрица
    for (int i = sz - 1; i > 0 + layer; i--) {
        matrix.setElement(sz - 1, i, rotatedPerimeter[index]);
        index++;
    }

    // Левый столбец снизу вверх - - вставляем элемент в объект матрица
    for (int i = sz - 1; i > 0 + layer; i--) {
        matrix.setElement(i, layer, rotatedPerimeter[index]);
        index++;
    }
}




