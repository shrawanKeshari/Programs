/*
 ============================================================================
 Name        : LIS.c
 Author      : Pawan Keshari
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int LIS(int *,int );

int main()
{
	int n,i,ans;
	printf("Enter the size of array:\n");
	scanf("%d",&n);
	int *array = (int *)malloc(sizeof(int) * n);
	printf("Enter the elements:\n");
	for(i = 0; i < n; i++)
		scanf("%d",&array[i]);

	ans = LIS(array,n);
	printf("\nAnswer is:%d",ans);
	getch();
	return 0;
}

int LIS(int *arr,int size)
{
	int i,j,max;
	int ls[size];
	for(i = 0; i < size; i++)
		ls[i] = 1;
	max = ls[0];
	for(i = 1; i < size; i++)
	{
		for(j = 0; j < i; j++)
		{
			if(arr[i] > arr[j] && ls[i] < ls[j] + 1)
				ls[i] = ls[j] + 1;
			if(max < ls[i])
				max = ls[i];
		}
	}
	return max;
}
