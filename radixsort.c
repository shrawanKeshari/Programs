/*
 ============================================================================
 Name        : radixsort.c
 Author      : Pawan Keshari
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void radixsort(int *, int );
int max(int *, int );
void countsort(int *, int , int );

int main()
{
	int n,i, *a;
	printf("Enter the number of element of array:\n");
	scanf("%d",&n);
	a = (int *)malloc(n * sizeof(int));
	printf("Enter the element of array:\n");
	for(i = 0 ; i < n ; i++)
	{
		scanf("%d",&a[i]);
	}
	radixsort(a,n);
	printf("Sorted array is:\n");
	for(i = 0; i < n ; i++)
	{
		printf("%d\t",a[i]);
	}
	getch();
	return 0;
}

void radixsort(int *input_array, int size)
{
	int digit;
	int m = max(input_array,size);

	for(digit = 1 ; m/digit > 0 ; digit *= 10)
		countsort(input_array,size,digit);
}

int max(int *array, int size)
{
	int i,max = array[0];
	for(i = 1 ; i < size ; i++)
	{
		if(array[i] > max)
		{
			max = array[i];
		}
	}

	return max;
}

void countsort(int *i_arr, int arr_size, int digit)
{
	int i,j, count[10], o_arr[arr_size];

	for(i = 0 ; i < 10 ; i++)
		count[i] = 0;

	for(j = 0 ; j < arr_size ; j++)
		count[(i_arr[j]/digit)%10] = count[(i_arr[j]/digit)%10] + 1;

	for(i = 1 ; i < 10 ; i++)
		count[i] = count[i] + count[i - 1];

	for(j = arr_size - 1 ; j >= 0 ; j--)
	{
		o_arr[count[(i_arr[j]/digit)%10] - 1] = i_arr[j];
		count[(i_arr[j]/digit)%10] = count[(i_arr[j]/digit)%10] - 1 ;
	}

	for( j = 0 ; j < arr_size ; j++)
	{
		i_arr[j] = o_arr[j];
	}
}
