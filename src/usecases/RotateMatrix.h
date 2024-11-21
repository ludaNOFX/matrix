#include "../entities/Matrix.h"
#ifndef ROTATEMATRIX_H
#define ROTATEMATRIX_H


class RotateMatrix {
public:
    /// @param matrix - экземпляр класса матрицы
    /// @param step - шаг циклического сдвига
    /// @param layer - слой периметра (внешний - 0 внутрение 1, 2...)
    /// @param sz - размер матрицы он уменьшается на каждый слой
    void rotate(Matrix& matrix, int step, int layer, int sz); // Метод для циклического сдвига
};

#endif // ROTATEMATRIX_H