#include <stdio.h>
#include <Python.h>
#include <numpy/arrayobject.h>
#include "graph.h"

/**
 * A function that calls the drawGraph function from the DrawGraph Python module.
 * @param pyMatrix a 2D numpy array of integers
 * @return None 
 */
void DrawGraph(PyObject *pyMatrix)
{
    // Py_Initialize();
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('./src/')");
    PyObject *pModule = PyImport_ImportModule("DrawGraph");
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
    // Py_Finalize();
}

