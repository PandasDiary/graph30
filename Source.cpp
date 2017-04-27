// Задача 30 и 71
// Дерево задано списком дуг, найти что-то на катом уровне

#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>


int main()
{
	char symb;
	int **A, **C;
	int count_space=0;
	FILE *txt = fopen("file.txt", "r");
	if ((txt = fopen("file.txt", "r")) == NULL)
	{
		printf("Error");
		exit(-1);
	}
	do
	{
		fscanf(txt, "%c", &symb);
		if (symb == ' ') count_space++;
		if (symb == '\n') break;
	} while (symb != EOF);
	int n = count_space + 1; // Число строк и столбцов
	A = (int**)malloc(n * sizeof(int));
	C = (int**)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		A[i]= (int*)malloc(n * sizeof(int));
		C[i]= (int*)malloc(n * sizeof(int));
	}
	fseek(txt, 0, SEEK_SET); // Сдвинуть каретку потока в начало файла
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			fscanf(txt, "%i", &A[i][j]);
			C[i][j] = A[i][j];
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			printf("%i ", A[i][j]);
			if (j%n == (n-1))	printf("\n");
		}
	printf("\n\n");
	// Алгоритм Флойда-Уоршелла
	for (int k=0; k<n; k++)
		for (int i=0; i<n; i++)
			for (int j = 0; j < n; j++)
			{
				if (C[i][j]>C[i][k] + C[k][j])
					C[i][j] = C[i][k] + C[k][j];
			}
	//
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			printf("%i ", C[i][j]);
			if (j%n == (n-1))	printf("\n");
		}
	
	fclose(txt);
	free(A);
	free(C);
	system("pause");
	return 0;
}