/*
 ============================================================================
 Name        : countsort.c
 Author      : Pawan Keshari
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void countsort(int *, int , int *, int );

int main()
{
	int n,i,k, *a, *b;
	printf("Enter the number of element of arrays:\n");
	scanf("%d",&n);
	a = (int *)malloc(n * sizeof(int));
	b = (int *)malloc(n * sizeof(int));
	printf("Enter the elements of array:\n");
	for(i = 0 ; i < n ; i++)
	{
		scanf("%d",&a[i]);
		b[i + 1] = a[i];
	}
	printf("\nEnter the range of integer:\n");
	scanf("%d",&k);
	countsort(a,n,b,k);
	printf("\nSorted array is:\n");
	for(i = 1 ; i <= n ; i++)
	{
		printf("%d",b[i]);
	}
	getch();
	return 0;
}

void countsort(int *input_array, int size, int *output_array, int range)
{
	int i,j, *count;
	count = (int *)malloc(range * sizeof(int));

	for(i = 0 ; i < range ; i++)
		count[i] = 0;

	for(j = 0 ; j < size ; j++)
		count[input_array[j]] = count[input_array[j]] + 1;

	for(i = 1 ; i < range ; i++)
		count[i] = count[i] + count[i - 1];

	for(j = size - 1 ; j >= 0 ; j--)
	{
		output_array[count[input_array[j]]] = input_array[j];
		count[input_array[j]] = count[input_array[j]] - 1;
	}
}
