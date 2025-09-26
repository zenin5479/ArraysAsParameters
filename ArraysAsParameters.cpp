#include <iostream>
#include <stdio.h>
#include "lib.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	printf("Введите размер векторов");
	scanf("%i", &n);
	float* C;
	float* P;
	printf("Введите вектор С\n");
	VvodVect(C, n);
	printf("Введите вектор P\n");
	VvodVect(P, n);
	printf("Введен вектор С\n");
	VivodVect(C, n);
	printf("Введен вектор P\n");
	VivodVect(P, n);
	float s = 0.0;
	s = Sum(C, n);
	if (Check(P, n, s))
	{
		printf("Условие выполнено\n");
		float** A;
		FormMatrix(A, C, P, n);
		VivodMatrix(A, n);
		int i, j;
		FindMax(A, n, i, j);
		printf("Индексы максимума (%i,%i)", i, j);
	}
	else
	{
		printf("Условие не выполнено");

	}
	return 0;
}