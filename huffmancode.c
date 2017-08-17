/*
 ============================================================================
 Name        : huffmancode.c
 Author      : Pawan Keshari
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct node
{
	char data;
	int freq;
	struct node *left, *right;
};

struct minheap
{
	int count;
	int size;
	struct node **array;
};

struct node *huffmancode(char *, int *, int );
struct node *createnode(char , int );
struct minheap *createminheap(int );
void builtminheap(struct minheap *, char *, int *, int );
struct node *deletemin(struct minheap **);
int emptyheap(struct minheap *);
int isoneheap(struct minheap *);
void insertinheap(struct minheap *,struct node *);
struct minheap *resizeheap(struct minheap *);
struct minheap *minheapify(struct minheap *, int );
void swap(struct node **, struct node **);
void printtree(struct node *,int *, int );
int height(struct node *);

int main()
{
	int i,n,*freq_array,*array_tree,tree_height,index = 0;
	struct node *root;
	printf("Enter the size of array:\n");
	scanf("%d",&n);
	char char_array[10] /*= (char *)malloc(sizeof(char) * n)*/;
	freq_array = (int *)malloc(sizeof(int) * n);
	printf("Enter the character:\n");
	fflush(stdin);
	for(i = 0 ; i < n ; i++)
	{
		scanf("%c",&char_array[i]);
		fflush(stdin);
	}
	printf("Enter the frequency:\n");
	for(i = 0 ; i < n ; i++)
	{
		scanf("%d",&freq_array[i]);
	}
	root = huffmancode(char_array,freq_array,n);
	tree_height = height(root);
	array_tree = (int *)malloc(sizeof(int) * tree_height);
	printtree(root,array_tree,index);
	getch();
	return 0;
}

struct node *huffmancode(char *array, int *freq, int array_size)
{
	struct minheap *h = createminheap(array_size);
	struct node *newnode, *heap_left, *heap_right;
	builtminheap(h,array,freq,array_size);
	while(!isoneheap(h))
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		heap_left = deletemin(&h);
		heap_right = deletemin(&h);
		newnode = createnode('$',heap_left->freq + heap_right->freq);
		newnode->left = heap_left;
		newnode->right = heap_right;
		insertinheap(h,newnode);
	}
	return deletemin(&h);
}

struct node *createnode(char data, int frequency)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->freq = frequency;
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
}

struct minheap *createminheap(int size)
{
	struct minheap *h = (struct minheap *)malloc(sizeof(struct minheap));
	if(!h)
		return 0;
	h->count = 0;
	h->size = size;
	h->array = (struct node **)malloc(sizeof(struct node) * size);
	if(!h->array)
		return 0;

	return h;
}

void builtminheap(struct minheap *h, char *char_array, int *freq_array, int size)
{
	int i;
	if(!h)
		return ;
	for(i = 0 ; i < size ; i++)
		h->array[i] = createnode(char_array[i],freq_array[i]);
	h->count = size;
	for(i = (size -2)/2 ; i >=0 ; i--)
		h = minheapify(h,i);
}
struct node *deletemin(struct minheap **h)
{
	struct node *min;
	if(emptyheap(*h))
		return 0;
	min = (*h)->array[0];
	(*h)->array[0] = (*h)->array[(*h)->count - 1];
	(*h)->count -= 1;
	*h = minheapify(*h,0);
	return min;
}

int emptyheap(struct minheap *h)
{
	return (h->count==0);
}

int isoneheap(struct minheap *h)
{
	return (h->count == 1);
}

void insertinheap(struct minheap *h,struct node *tree_node)
{
	int i;
	if(h->count == h->size)
		h = resizeheap(h);
	h->count++;
	i = h->count - 1;
	while(i > 0 && (tree_node->freq < h->array[(i - 1)/2]->freq))
	{
		h->array[i] = h->array[(i - 1)/2];
		i = (i - 1)/2;
	}
	h->array[i] = tree_node;
}

struct minheap *resizeheap(struct minheap *h)
{
	int i;
	struct node **old_array = h->array;
	h->array = (struct node **)malloc(sizeof(struct node) * h->size * 2);
	for(i = 0 ; i < h->size ; i++)
		h->array[i] = old_array[i];
	h->size *= 2;
	free(old_array);
	return h;
}

struct minheap *minheapify(struct minheap *h, int index)
{
	int min, left, right;
	min = index;
	left = 2 * index + 1;
	right = 2 * index + 2;
	if((left < h->count) && (h->array[left]->freq < h->array[min]->freq))
		min = left;
	if((right < h->count) && (h->array[right]->freq < h->array[min]->freq))
		min = right;
	if(min != index)
	{
		swap(&(h->array[index]),&(h->array[min]));
		h = minheapify(h,min);
	}
	return h;
}

void swap(struct node **current, struct node **swapped)
{
	struct node *temp;
	temp = *current;
	*current = *swapped;
	*swapped = temp;
}

void printtree(struct node *root,int *array, int index)
{
	int i;
	if(root->left)
	{
		array[index] = 0;
		printtree(root->left,array,index + 1);
	}
	if(root->right)
	{
		array[index] = 1;
		printtree(root->right,array,index + 1);
	}
	if(!(root->left) && !(root->right))
	{
		printf("%c:\t",root->data);
		for(i = 0 ; i < index ; i++)
			printf("%d",array[i]);
		printf("\n");
	}
}

int height(struct node *root)
{
	int left_height,right_height;
	if(!root)
		return 0;
	else
	{
		left_height = height(root->left);
		right_height = height(root->right);
		if(left_height > right_height)
			return (left_height + 1);
		else
			return (right_height + 1);
	}
}
