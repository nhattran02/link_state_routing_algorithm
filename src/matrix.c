#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Python.h>
#include <numpy/arrayobject.h>
#include "../inc/matrix.h"

// #include "graph.h"

/**
 * It reads a matrix from a file
 * 
 * @param size the size of the matrix
 * 
 * @return matrix
 */
int** readMatrixFromFile(int *size)
{
    char filename[256];
    FILE *infile ;

    do{
        printf("\n\t Please enter filename of adjacency matrix: ");
        scanf("%s", filename);
        char path[256] = "testfile/";
        strcat(path, filename);
        infile = fopen(path, "r");
        if(infile == NULL){
            printf("%s%s%s", "\x1b[31;1m", "\t Enter matrix failed. Check again!", "\x1b[39;49m");
        }
    }while(infile == NULL);

    fscanf(infile, "%d", size);
    int** matrix = (int **) malloc((*size) * sizeof(int *));
    for(int i = 0; i < (*size); ++i) {
        matrix[i] = (int *) malloc((*size) * sizeof(int));
        for(int j = 0; j < (*size); ++j) {
            fscanf(infile, "%d", &matrix[i][j]);
        }
    }
    fclose(infile);
    printf("%s%s%s", "\x1b[32;1m", "\t Enter matrix successfully!", "\x1b[39;49m");
    return matrix;
}

/**
 * It frees the memory allocated for the matrix
 * 
 * @param matrix The matrix to be freed.
 * @param size The size of the matrix.
 * @return None
 */
void freeMemory(int **matrix, int size)
{
    for(int i = 0; i < size; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

/**
 * Convert 2D C++ array to a NumPy array
 * 
 * @param cppMatrix The input matrix in C++
 * @param size The size of the matrix.
 * 
 * @return NumPy array
 */
PyObject *convertcppMatrix2pyMatrix(int **cppMatrix, int size)
{
    // Create a NumPy array of the same size as the input array
    npy_intp dims[2] = {size, size};
    import_array();
    PyObject *pyArray = PyArray_SimpleNew(2, dims, NPY_INT);
    if(pyArray == NULL){
        printf("%s%s%s", "\x1b[31;1m", "\t Error: failed to allocate memory for NumPy array", "\x1b[39;49m");
        return NULL;
    }
    // Copy the data from the input array to the NumPy array
    int *pyData = (int *)PyArray_DATA((PyArrayObject *)pyArray);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            *(pyData + i*size + j) = cppMatrix[i][j];
        }
    }

    // Return the NumPy array
    return pyArray;
}

/**
 * Print all elements of matrix 
 * 
 * @param matrix The matrix to be freed.
 * @param size The size of the matrix.
 * @return None
 */
void printMatrix(int **matrix, int size)
{
    printf("\n\t ------------------------------------- ");
    printf("\n\t |    DISPLAY THE ADJACENCY MATRIX   | ");
    printf("\n\t ------------------------------------- ");
    printf("\n\t");
    for(int i = 0; i < size ; i++){
        for(int j = 0; j < size ; j++){
            printf("%5d", matrix[i][j]);
        }
        printf("\n\t");
    }
}
