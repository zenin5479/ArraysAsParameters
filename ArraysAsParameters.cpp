#include <iostream>
#include <stdio.h>
#include "lib.h"

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