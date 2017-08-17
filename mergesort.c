/*
 ============================================================================
 Name        : mergesort.c
 Author      : Pawan Keshari
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int c = 0;
void mergesort(int *, int , int);
void merge(int *, int , int , int);

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
	mergesort(&a[0],0,n-1);
	printf("\nSorted array is:\n");
	for(i=0 ; i<n ; i++)
	{
		printf("%d",a[i]);
	}
	printf("\n%d",c);
	getch();
	return 0;
}

void mergesort(int *mer_sort , int left , int right)
{
	int mid;
	if(left < right)
	{
		mid = (left + right)/2;
		mergesort(mer_sort , left , mid);
		mergesort(mer_sort , mid + 1 , right);
		merge(mer_sort , left , mid , right);
	}
}

void merge(int *merge , int left , int mid , int right)
{
	int i,j,k;
	int left_size = mid - left + 1;
	int right_size = right - mid;
	int *left_array = (int *)malloc(left_size * sizeof(int));
	int *right_array = (int *)malloc(right_size * sizeof(int));
	printf("\nArray is:\n");
	for(i = 0 ; i <= right ; i++)
	{
		printf("\n%d",merge[i]);
	}
	for(i = 0 ; i < left_size ; i++)
		left_array[i] = merge[left + i];

	for(j = 0 ; j < right_size ; j++)
		right_array[j] = merge[mid + j + 1];

	i = 0;
	    j = 0;
	    k = left;
	    while (i < left_size && j < right_size)
	    {
	        if (left_array[i] <= right_array[j])
	        {
	            merge[k] = left_array[i];
	            i++;
	        }
	        else
	        {
	            merge[k] = right_array[j];
	            j++;
	            c += abs(k - j);
	        }
	        k++;
	    }
	    while (i < left_size)
	    {
	        merge[k] = left_array[i];
	        i++;
	        k++;
	    }
	    while (j < right_size)
	    {
	        merge[k] = right_array[j];
	        j++;
	        k++;
	    }
}
