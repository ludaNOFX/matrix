#include <iostream>
#include "src/utils/input_utils.h"
#include "src/entities/Matrix.h"
#include "src/adapters/MatrixPrinter.h"
#include "src/usecases/RotateMatrix.h"
#include <cstdlib>

using namespace std;

size_t allocated_memory = 0;

void* operator new(size_t size) {
    allocated_memory += size;
    return malloc(size);
}

void operator delete(void* pointer, size_t size) noexcept {
    allocated_memory -= size;
    free(pointer);
}

int main() {
    cout <<"Введите число Размер квадратной матрицы -> ";
    int sz = getValidInput();
    cout << endl;
    cout <<"Введите число Шаг для циклического сдвига -> ";
    int step = getValidInput();
    cout << endl;

    Matrix matrix(sz);
    RotateMatrix rotate_matrix;
    MatrixPrinter printer;

    cout <<"Default Matrix:" << endl;
    printer.print(matrix);

    for (int i = 0; i < sz / 2; i++) {
        rotate_matrix.rotate(matrix, step, i, sz - i);
    }

    cout <<"Rotated Matrix:" << endl;
    printer.print(matrix);
    cout << endl;

    cout << "Allocated memory: " << allocated_memory << " bytes" << endl;

    return 0;
}
