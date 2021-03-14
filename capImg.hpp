#include <iostream>
#include <python3.8/Python.h>

void captureImage(){
    FILE* file;

    std::wstring src(L"captureImg.py");
    const wchar_t* srcpath = src.c_str();

    Py_SetProgramName(srcpath);
    Py_Initialize();
    file = fopen("captureImg.py", "r");
    PyRun_SimpleFile(file, "captureImg.py");
    Py_Finalize();
}