/*
 ============================================================================
 Name        : heapsort.c
 Author      : Pawan Keshari
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int *heapsort(int *, int );
struct heap *create_built_heap(int *, int );
void maxheapifydown(struct heap *, int );

struct heap
{
	int count;
	int size;
	int *array;
};

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
	a = heapsort(a, n);
	printf("\nSorted array is:\n");
	for(i=0 ; i<n ; i++)
	{
		printf("%d",a[i]);
	}
	getch();
	return 0;
}

int *heapsort(int *array, int size)
{
	struct heap *h = create_built_heap(array,size);
	int old_size,i,temp;
	old_size = h->count;

	for(i = size -1 ; i > 0 ; i--)
	{
		temp = h->array[0];
		h->array[0] = h->array[h->count - 1];
		h->array[h->count - 1] = temp;
		h->count--;
		maxheapifydown(h,0);
	}
	h->count = old_size;

	return h->array;
}
struct heap *create_built_heap(int *given_array,int size)
{
	int i;
	struct heap *h = (struct heap *)malloc(sizeof(struct heap));
	if(!h)
		return 0;
	h->size = size;
	h->array = (int *)malloc(h->size * sizeof(int));
	if(!h->array)
		return 0;

	for(i = 0 ; i < size ; i++)
		h->array[i] = given_array[i];

	h->count = size;
	for(i = (size - 2)/2 ; i >= 0 ; i--)
		maxheapifydown(h,i);

	printf("heap is:\n");
	for(i = 0 ; i < h->count ; i++)
		printf("%d",h->array[i]);
	return h;
}

void maxheapifydown(struct heap *h, int index)
{
	int temp,max = index;
	int left = 2*index + 1;
	int right = 2*index + 2;

	if(left < h->count && h->array[left] > h->array[index])
		max = left;

	if(right < h->count && h->array[right] > h->array[max])
		max = right;

	if(max != index)
	{
		temp = h->array[index];
		h->array[index] = h->array[max];
		h->array[max] = temp;
		maxheapifydown(h,max);
	}
}

