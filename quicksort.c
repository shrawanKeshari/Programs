#include <stdio.h>
#include <stdlib.h>

int c = 0;

void quicksort(int *, int , int , int );
int partition(int *, int , int , int );

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
	quicksort(a,0,n-1,n);
	printf("Sorted array is:\n");
	for(i=0 ; i<n ; i++)
	{
		printf("%d",a[i]);
	}
	printf("\n%d",c);
	return 0;
}

void quicksort(int *given_array, int left, int right, int size)
{
	int pivot_element,j;
	if(left < right)
	{
		pivot_element = partition(given_array,left,right,size);
		quicksort(given_array,left,pivot_element - 1,size);
		quicksort(given_array,pivot_element + 1,right,size);

		for(j = 0; j <= right; j++)
			printf("%d ",given_array[j]);
		printf("\n");
	}
}

int partition(int *array, int left, int right, int size)
{
	int pivot = array[right];
	int temp,j,i = left;
	for(j = left ; j <= right - 1 ; j++)
	{
		if(array[j] <= pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i = i + 1;
			c++;
		}
	}
	temp = array[i];
	array[i] = array[right];
	array[right] = temp;
	c++;

	return (i);
}
