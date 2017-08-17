/*
 ============================================================================
 Name        : insertionsort.c
 Author      : Pawan Keshari
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void insertionsort(int *, int );

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
	insertionsort(&a[0],n);
	printf("Sorted array is:\n");
	for(i=0 ; i<n ; i++)
	{
		printf("%d",a[i]);
	}
	getch();
	return 0;
}

void insertionsort(int *ins ,int size)
{
	int i,j,element,v=0;
	for(i = 1 ; i < size ; i++)
	{
		element = ins[i];
		j = i;
		while(ins[j-1] > element && j >= 1)
		{
			ins[j] = ins[j-1];
			j--;
			v++;
		}
		ins[j] = element;
	}
	printf("%d",v);
}
