#define PY_SSIZE_T_CLEAN
#include "Python.h"
// Always use the two lines above...

//Then load all the C++ stuff needed
#include "iostream"
#include "string"

// Python-exposed functions have to be in this form.
PyObject *getText(PyObject *self, PyObject *args)
{
    // Before sending objects to the Python world you need to convert them properly.
    return PyUnicode_FromString("Hello World!"); 
}

PyObject *test_myprint(PyObject *self, PyObject *args)
{
    std::cout << "Printed from C" << std::endl;
    // Don't want to return a value? You have to explicitly return this:
    Py_RETURN_NONE;
}


// But wait! How to retrieve data FROM Python?
PyObject *printValues(PyObject *self, PyObject *args)  //Function args do not change...
{
    
    const char *x; // This will get you string.
    int num;
    /* Take the tuple of args coming from Python,
     * the first one is to be considered as string, hence the "s",
    */
    if (!PyArg_ParseTuple(args, "si", &x, &num))  
        return NULL;
    
    // From here is pure C++    
    std::cout << x << std::endl;
    std::cout << num << std::endl;
    
    // Return to Python
    Py_RETURN_NONE;
}



/*           MODULE INITIALIZATION                  */

// This exposes C++ methods to Python
static struct PyMethodDef test_module_methods[] = {
    // For each function just put the name you want to call it from Python
    // and the actual C++ function name
    // {"FunctionNameFromPython", function_name, METH_VARARGS, NULL}
    {"printSomething", test_myprint, METH_VARARGS, NULL},             
    {"getText", getText, METH_VARARGS, NULL},             
    {"printTheseValues", printValues, METH_VARARGS, NULL},             
    { NULL,NULL,0, NULL}
};



static struct PyModuleDef moduledef = {
        PyModuleDef_HEAD_INIT,
        "test",                         // <--- MODULENAME here
        NULL,
        -1,
        test_module_methods,
        NULL,
        NULL,
        NULL,
        NULL
};

PyMODINIT_FUNC PyInit_test(void)    // Call as PyInit_MODULENAME
{
    PyObject *m;
    m = PyModule_Create(&moduledef);   //This refers to the above
    if (m == NULL) {
        return NULL;
    }
    

    return m;
}

