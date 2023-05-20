#ifndef MATRIX_H
#define MATRIX_H
#define MAX 100

int** readMatrixFromFile(int *size);
void freeMemory(int **matrix, int size);
PyObject *convertcppMatrix2pyMatrix(int **cppMatrix, int size);
void printMatrix(int **matrix, int size);

#endif

