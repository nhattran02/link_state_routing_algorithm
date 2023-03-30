// DrawGraph.py 
// Created on: 30.3.2023
// nhat.tranminh

#include <fstream>
#include <iostream>
#include <string>
#include </usr/include/python3.8/Python.h>
#include <numpy/arrayobject.h>

using namespace std; 
void DrawGraph(PyObject *pyMatrix);
int** readMatrixFromFile(int *size);
void freeMemory(int **matrix, int size);
PyObject *convertcppMatrix2pyMatrix(int **cppMatrix, int size);


int main(int argc, char const *argv[])
{
    int **cppMatrix;
    int size;
    cppMatrix = readMatrixFromFile(&size);  

    //start python 
    Py_Initialize();
    PyObject *pyMatrix = convertcppMatrix2pyMatrix(cppMatrix, size);
    DrawGraph(pyMatrix);
    Py_Finalize();
    //end python

    freeMemory(cppMatrix, size);
    return 0;
}

int** readMatrixFromFile(int *size)
{
    string filename;
    printf("Enter filename: ");
    cin >> filename;
    string path = "testfile/";
    path.append(filename);
    ifstream infile(path);
    infile >> *size;
    int** matrix = new int*[(*size)];
    for(int i = 0; i < (*size); ++i){
        matrix[i] = new int[(*size)];
        for(int j = 0; j < (*size); ++j){
            infile >> matrix[i][j];
        }
    }
    infile.close();
    return matrix;
}

void freeMemory(int **matrix, int size)
{
    for(int i = 0; i < size; ++i){
        delete[] matrix[i];
    }
    delete[] matrix;
}

PyObject *convertcppMatrix2pyMatrix(int **cppMatrix, int size)
{
    // Initialize the Python interpreter and NumPy array
    import_array();

    // Create a NumPy array of the same size as the input array
    npy_intp dims[2] = {size, size};
    PyObject *pyArray = PyArray_SimpleNew(2, dims, NPY_INT);

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

void DrawGraph(PyObject *pyMatrix)
{
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./src/')");
    PyObject *pModule(0);
    pModule = PyImport_ImportModule("DrawGraph");
    if (pModule) {
        // Get a handle to the drawGraph function
        PyObject *pFunc = PyObject_GetAttrString(pModule, "drawGraph");
        if (pFunc && PyCallable_Check(pFunc)) {
            // Call the drawGraph function with the pyMatrix argument
            PyObject *pArgs = PyTuple_New(1);
            PyTuple_SetItem(pArgs, 0, pyMatrix);
            PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);
        }
        else {
            printf("Error: drawGraph is not callable\n");
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }
    else {
        printf("Error: could not import module DrawGraph\n");
    }
}