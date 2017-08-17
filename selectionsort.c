/*
 ============================================================================
 Name        : selectionsort.c
 Author      : Pawan Keshari
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void selectionsort(int * , int );

int main()
{
	int n,i, *a;
	printf("Enter the number of element of array:\n");
	scanf("%d",&n);
	a = (int *)malloc(n * sizeof(int));
	printf("Enter the elements of array:\n");
	for(i=0 ; i<n ; i++)
	{
		scanf("%d",&a[i]);
	}
	selectionsort(&a[0],n);
	printf("Sorted array is:\n");
	for(i=0 ; i<n ; i++)
	{
		printf("%d",a[i]);
	}
	getch();
	return 0;
}

void selectionsort(int *sel, int size)
{
	int i,j,temp,min;
	for(i = 0 ; i < size -1 ; i++)
	{
		min = i;
		for(j = i+1 ; j < size ; j++)
		{
			if(sel[j] < sel[min])
			{
				min = j;
				temp = sel[min];
				sel[min] = sel[i];
				sel[i] = temp;
			}
		}
	}
}
