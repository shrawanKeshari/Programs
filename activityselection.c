/*
 ============================================================================
 Name        : activityselection.c
 Author      : Pawan Keshari
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct activity
{
	int start;
	int finish;
};

void activityselection(struct activity *, int );
void mergesort(struct activity *,int ,int );
void merge(struct activity *,int ,int ,int );

int main()
{
	int i,n;
	printf("Enter the size of array:\n");
	scanf("%d",&n);
	fflush(stdin);
	struct activity *array = (struct activity *)malloc(sizeof(struct activity) * n);
	for( i = 0 ; i < n ; i++)
	{
		printf("Enter the start and finish of activity:\n");
		scanf("%d %d",&array[i].start,&array[i].finish);
		fflush(stdin);
	}
	printf("Activity No.     Start     Finish");
	for(i = 0 ; i < n ; i++)
	{
		printf("\n    %d              %d         %d",i+1,array[i].start,array[i].finish);
	}
	activityselection(array,n);
	getch();
	return 0;
}

void activityselection(struct activity *arr, int size)
{
	int i,j;

	mergesort(arr,0,size-1);

	printf("\nActivity with maximum output:\n");
	i = 0;
	printf("%d",i + 1);

	for(j =  1 ; j < size ; j++)
	{
		if(arr[j].start >= arr[i].finish)
		{
			printf("%d",j + 1);
			i = j;
		}
	}
}

void mergesort(struct activity *arr,int left,int right)
{
	int mid;
	if(left < right)
	{
		mid = (left + right)/2;
		mergesort(arr,left,mid);
		mergesort(arr,mid + 1,right);
		merge(arr,left,mid,right);
	}
}

void merge(struct activity *array,int left,int mid,int right)
{
	int i,j,k;
	int left_size = mid - left + 1;
	int right_size = right - mid;
    struct activity *left_arr = (struct activity *)malloc(sizeof(struct activity) * left_size);
    struct activity *right_arr = (struct activity *)malloc(sizeof(struct activity) * right_size);

    for(i = 0 ; i < left_size ; i++)
    	left_arr[i] = array[left + i];

    for(j = 0 ; j < right_size ; j++)
    	right_arr[j] = array[mid + j + 1];

    i = 0, j = 0;

    for(k = left ; k <= right ; k++)
    {
    	if(left_arr[i].finish <= right_arr[j].finish)
    	{
    		array[k] = left_arr[i];
    		i++;
    	}
    	else
    	{
    		array[k] = right_arr[j];
    		j++;
    	}
    }
}
