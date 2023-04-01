#ifndef MATRIX_H
#define MATRIX_H

int** readMatrixFromFile(int *size);
void freeMemory(int **matrix, int size);
PyObject *convertcppMatrix2pyMatrix(int **cppMatrix, int size);


#endif

