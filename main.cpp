#include <iostream>
#include "src/utils/input_utils.h"
#include "src/entities/Matrix.h"
#include "src/usecases/RotateMatrix.h"

using namespace std;

int main() {
    cout <<"Введите число Размер квадратной матрицы -> ";
    int sz = getValidInput();
    cout << endl;
    cout <<"Введите число Шаг для циклического сдвига -> ";
    int step = getValidInput();
    cout << endl;

    Matrix matrix(sz); // объект матрицы
    RotateMatrix rotate_matrix; // объект Ротации матрицы

    cout <<"Default Matrix:" << endl;
    matrix.print(); // вывод неизмененной матрицы

    for (int i = 0; i < sz / 2; i++) {
        rotate_matrix.rotate(matrix, step, i, sz - i); // делаем ротацию матрицы на указанный шаг
    }

    cout <<"Rotated Matrix:" << endl;
    matrix.print(); // выводим матрицу
    cout << endl;

    return 0;
}

