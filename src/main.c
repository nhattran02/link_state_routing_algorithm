#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Python.h>
#include <numpy/arrayobject.h>
#include "matrix.h"
#include "graph.h"

int main(int argc, char const *argv[])
{
    int **cppMatrix;
    int size;
    cppMatrix = readMatrixFromFile(&size);

    // Initialize Python interpreter
    Py_Initialize();
    PyObject *pyMatrix = convertcppMatrix2pyMatrix(cppMatrix, size);
    if(!pyMatrix){
        printf("Error to convert\n");
    }
    // Draw graph
    DrawGraph(pyMatrix);
    // Finalize Python interpreter
    Py_Finalize();

    freeMemory(cppMatrix, size);
    return 0;
}


