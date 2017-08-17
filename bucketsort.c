/*
 ============================================================================
 Name        : bucketsort.c
 Author      : Pawan Keshari
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void bucketsort(int *, int );

int main()
{
	int n,i, *a;
	printf("Enter the number of element of array:\n");
	scanf("%d",&n);
	a = (int *)malloc(n * sizeof(int));
	printf("Enter the element of array:\n");
	for(i=0 ; i<n ; i++)
	{
		scanf("%d",&a[i]);
	}
	bucketsort(a,n);
	printf("Sorted array is:\n");
	for(i = 0 ; i < n ; i++)
	{
		printf("%d",a[i]);
	}
	getch();
	return 0;
}

void bucketsort(int *array, int size)
{
	int i,j,k,b_size;
	printf("\nEnter the size of bucket:\n");
	scanf("%d",&b_size);
	int *bucket = (int *)malloc(b_size * sizeof(int));

	for(i = 0 ; i < b_size ; i++)
		bucket[i] = 0;

	for(j = 0 ; j < size ; j++)
		bucket[array[j]] += 1;

	for(j = 0, i = 0 ; i < b_size ; i++)
		for(k = bucket[i] ; k > 0 ; --k)
			array[j++] = i;
}
