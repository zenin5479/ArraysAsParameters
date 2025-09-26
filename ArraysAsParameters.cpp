#include <iostream>
#include <stdio.h>
void VvodVect(float*& x, int nx);
void VivodVect(float* x, int nx);
float Sum(float* x, int nx);
bool Check(float* x, int nx, float t);
void FormMatrix(float**& z, float* x, float* y, int nx);
void VivodMatrix(float** x, int nx);
void FindMax(float** z, int nx, int& imax, int& jmax);
void FreeMemoryMatrix(float**& x, int n);
void FreeMemoryVector(float*& x);

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	printf("������� ������ ��������");
	scanf("%i", &n);
	float* C;
	float* P;
	printf("������� ������ �\n");
	VvodVect(C, n);
	printf("������� ������ P\n");
	VvodVect(P, n);
	printf("������ ������ �\n");
	VivodVect(C, n);
	printf("������ ������ P\n");
	VivodVect(P, n);
	float s = 0.0;
	s = Sum(C, n);
	if (Check(P, n, s))
	{
		printf("������� ���������\n");
		float** A;
		FormMatrix(A, C, P, n);
		VivodMatrix(A, n);
		int i, j;
		FindMax(A, n, i, j);
		printf("������� ��������� (%i,%i)", i, j);
	}
	else
	{
		printf("������� �� ���������");

	}
	return 0;
}

void VvodVect(float*& x, int nx)
{
	x = new float[nx];
	for (int i = 0; i < nx; i++)
	{
		printf("������� ������� ��� ������� %i ", i);
		scanf("%f", &x[i]);
	}
	printf("\n");
	return;

}
void VivodVect(float* x, int nx)
{
	for (int i = 0; i < nx; i++)
	{
		printf("%f ", x[i]);
	}
	printf("\n");
	return;
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
	return;
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
	return;
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
	return;

}
void FreeMemoryMatrix(float**& x, int nx)
{
	for (int i = 0; i < nx; i++)
	{
		delete[] x[i];
	}
	delete[]x;
	return;
}
void FreeMemoryVector(float*& x)
{
	delete[]x;
	return;
}
