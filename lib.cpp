#include "lib.h"

void VvodVect(float*& x, int nx)
{
	x = new float[nx];
	for (int i = 0; i < nx; i++)
	{
		printf("Введите элемент под номером %i ", i);
		scanf("%f", &x[i]);
	}
	printf("\n");
}

void VivodVect(float* x, int nx)
{
	for (int i = 0; i < nx; i++)
	{
		printf("%f ", x[i]);
	}
	printf("\n");
}

float Sum(float* x, int nx)
{
	float s = 0.0;
	for (int i = 0; i < nx; i++)
	{
		s += x[i];
	}
	return s;
}

bool Check(float* x, int nx, float t)
{
	int i = 0;
	bool fl = true;
	while (i < nx && fl)
	{
		if (x[i] < t) i++;
		else fl = false;
	}
	return fl;
}

void FormMatrix(float**& z, float* x, float* y, int nx)
{
	z = new float* [nx];
	for (int i = 0; i < nx; i++)
	{
		z[i] = new float[nx];
		for (int j = 0; j < nx; j++)
		{
			z[i][j] = x[i] / (y[j] + x[i] * x[i]);
		}
	}
}

void VivodMatrix(float** x, int nx)
{
	for (int i = 0; i < nx; i++)
	{
		for (int j = 0; j < nx; j++)
		{
			printf("%f ", x[i][j]);
		}
		printf("\n");
	}
}

void FindMax(float** z, int nx, int& imax, int& jmax)
{
	float Max = z[0][0];
	imax = 0;
	jmax = 0;
	for (int i = 0; i < nx; i++)
	{
		for (int j = 0; j < nx; j++)
		{
			if (Max < z[i][j])
			{
				Max = z[i][j];
				imax = i;
				jmax = j;
			}
		}
	}
}

void FreeMemoryMatrix(float**& x, int nx)
{
	for (int i = 0; i < nx; i++)
	{
		delete[] x[i];
	}
	delete[]x;
}

void FreeMemoryVector(float*& x)
{
	delete[]x;
}
