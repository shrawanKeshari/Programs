/*
 ============================================================================
 Name        : Max_Sum.c
 Author      : Pawan Keshari
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int Max_Sum(int *,int );
int max(int ,int );

int main()
{
	int n,i,max_sum;
	printf("Enter the size of array:\n");
	scanf("%d",&n);
	int *arr = (int *)malloc(sizeof(int) * n);
	printf("Enter the element of array:\n");
	for(i = 0; i < n; i++)
		scanf("%d",&arr[i]);
	max_sum = Max_Sum(arr,n);
	printf("%d",max_sum);
	getch();
	return 0;
}

int Max_Sum(int *a,int n)
{
	int i,maxsum;
	int sum[n];
	sum[0] = a[0];
	maxsum = sum[0];
	for(i = 1; i < n; i++)
	{
		sum[i] = max(sum[i - 1] + a[i],a[i]);
		if(sum[i] > maxsum)
			maxsum = sum[i];
	}
	return maxsum;
}

int max(int a,int b)
{
	return (a > b)? a: b;
}
