/*
 ============================================================================
 Name        : bubblesort.c
 Author      : Pawan Keshari
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void bubblesort(int *,int );

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
	bubblesort(&a[0],n);
	printf("Sorted array is:\n");
	for(i=0 ; i<n ; i++)
	{
		printf("%d",a[i]);
	}
	getch();
	return 0;
}

void bubblesort(int *bubble, int size)
{
	int i, j, temp, swap = 1;
	for(i = size-1 ; i >= 0 && swap ; i--)
	{
		swap = 0;
		for(j = 0 ; j < i ; j++)
		{
			if(bubble[j] > bubble[j+1])
			{
				temp = bubble[j];
				bubble[j] = bubble[j+1];
				bubble[j+1] = temp;
				swap = 1;
			}
		}
	}
}
