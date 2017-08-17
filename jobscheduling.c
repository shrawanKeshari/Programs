/*
 ============================================================================
 Name        : jobscheduling.c
 Author      : Pawan Keshari
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct job
{
	char job_id;
	int deadline;
	int profit;
};

void jobscheduling(struct job *,int );
void mergesort(struct job *,int ,int );
void merge(struct job *,int ,int ,int );
int min(int ,int );

int main()
{
	int n,i;
	printf("Enter the size of array:\n");
	scanf("%d",&n);
	fflush(stdin);
	struct job *array = (struct job *)malloc(sizeof(struct job) * n);
	for(i = 0 ; i < n ; i++)
	{
		printf("Enter the job id, deadline and profit:\n");
		scanf("%c %d %d",&array[i].job_id,&array[i].deadline,&array[i].profit);
		fflush(stdin);
	}
	printf("Job Id     Deadline     Profit");
	for(i = 0 ; i < n ; i++)
	{
		printf("\n  %c           %d          %d",array[i].job_id,array[i].deadline,array[i].profit);
	}
	jobscheduling(array,n);
	getch();
	return 0;
}

void jobscheduling(struct job *arr,int size)
{
	int i,j;
	int result[size];
	char status[size];

	mergesort(arr,0,size-1);

	for(i = 0 ; i < size ; i++)
		status[i] = 'F';

	for(i = size-1 ; i >=0 ; i--)
	{
		for(j = 0 ; j <= (min(size,arr[i].deadline) - 1) ; j++)
		{
			if(status[j] == 'F')
			{
				result[j] = i;
				status[j] = 'T';
				break;
			}
		}
	}

	printf("\nJobs with maximum profit are:\n");
	for(i = 0 ; i < size ; i++)
	{
		if(status[i] == 'T')
		{
			printf("%c\n",arr[result[i]].job_id);
		}
	}
}

void mergesort(struct job *job_arr, int left, int right)
{
	int mid;
	if(left < right)
	{
		mid = (left + right)/2;
		mergesort(job_arr,left,mid);
		mergesort(job_arr,mid + 1,right);
		merge(job_arr,left,mid,right);
	}
}

void merge(struct job *arr_job,int left,int mid,int right)
{
	int i,j,k;
	int left_size = mid - left + 1;
	int right_size = right - mid;
	struct job *left_arr = (struct job *)malloc(sizeof(struct job) * left_size);
	struct job *right_arr = (struct job *)malloc(sizeof(struct job) * right_size);

	for(i = 0 ; i < left_size ; i++)
		left_arr[i] = arr_job[left + i];

	for(j = 0 ; j < right_size ; j++)
		right_arr[j] = arr_job[mid + 1 + j];

	i = 0, j = 0;
	for(k = left ; k <= right ; k++)
	{
		if(left_arr[i].profit <= right_arr[j].profit)
		{
			arr_job[k] = left_arr[i];
			i++;
		}
		else
		{
			arr_job[k] = right_arr[j];
			j++;
		}
	}
}

int min(int first,int second)
{
	if(first < second)
		return first;
	else
		return second;
}
