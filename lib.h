#include <iostream>

void VvodVect(float*& x, int nx);
void VivodVect(float* x, int nx);
float Sum(float* x, int nx);
bool Check(float* x, int nx, float t);
void FormMatrix(float**& z, float* x, float* y, int nx);
void VivodMatrix(float** x, int nx);
void FindMax(float** z, int nx, int& imax, int& jmax);
void FreeMemoryMatrix(float**& x, int n);
void FreeMemoryVector(float*& x);