/* Assignment: 3
Author: alexei serdukov, ID: 323274787
campus ashdod
*/



#include<stdio.h>
#define SIZE 5
void divide(int mat[SIZE][SIZE], int arr_lines[SIZE], int arr_cols[SIZE], int d);

void main()
{
	int d;
	printf("inser ur d\n");
	scanf_s("%d", &d);
	int mat1[SIZE][SIZE], arr_lines1[SIZE], arr_cols1[SIZE];
	divide(mat1,arr_lines1,arr_cols1,d);
}
void divide(int mat[SIZE][SIZE], int arr_lines[SIZE], int arr_cols[SIZE], int d)
{
	int i, j,k, counterlines=0, countercols=0;
	int numbers = 25;
	for (i = 0;i < SIZE; i++)
	{
		for (j = 0;j < SIZE;j++)
		{
			printf("inser ur number , left %d\n", numbers);
			scanf_s("%d", &mat[i][j]);
			numbers--;
		}
	}


	for (i = 0;i < SIZE;i++)
	{
		for (j = 0;j < SIZE;j++)
		{
			if (mat[i][j] % d == 0)
			{
				counterlines++;
			}
		}
		arr_lines[i] = counterlines;
		counterlines = 0;
	}
	for (i = 0;i < SIZE;i++)
	{
		for (j = 0;j < SIZE;j++)
		{
			if (mat[j][i] % d == 0)
			{
				countercols++;
			}
		}
		arr_cols[i] = countercols;

		countercols = 0;

	}
	printf("arr_lines = ");
	printf("{");

	for (i = 0;i < SIZE;i++)
	{
		printf("%d ", arr_lines[i]);
	}
	printf("}");

	printf("\n");
	printf("arr_cols = ");
	printf("{");
	for (i = 0;i < SIZE;i++)
	{
		printf("%d ", arr_cols[i]);
	}
	printf("}");

	printf("\n");
	
}