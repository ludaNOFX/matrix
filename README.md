# Matrix Rotation Project

Этот проект демонстрирует работу с матрицами выполняется циклический сдвиг элементов квадратной матрицы: ввод размеров матрицы, циклический сдвиг элементов, а также анализ утечек памяти.

---

## Компиляция и запуск

### 1. Простая компиляция и запуск

```bash
g++ -o main main.cpp src/utils/input_utils.cpp src/entities/Matrix.cpp src/adapters/MatrixPrinter.cpp src/usecases/RotateMatrix.cpp
./main

### 2. Компиляция и запуск с анализом утечек памяти
 
```bash
g++ -g -o main main.cpp src/utils/input_utils.cpp src/entities/Matrix.cpp src/adapters/MatrixPrinter.cpp src/usecases/RotateMatrix.cpp
valgrind --leak-check=full ./main

