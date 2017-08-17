/*
 ============================================================================
 Name        : mergLL.c
 Author      : Pawan Keshari
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct stacknode *createstack();
void push(struct stacknode **,int );
int emptystack(struct stacknode *);
struct stacknode *pop(struct stacknode **);
void mergll(struct stacknode **);
void split(struct stacknode *, struct stacknode **, struct stacknode **);
struct stacknode *sort_each(struct stacknode *, struct stacknode *);

struct stacknode
{
	int data;
	struct stacknode *next;
};

int main()
{
	int n,i,num;
	struct stacknode *top = NULL;
	struct stacknode *result;
	printf("Enter the number of elements:\n");
	scanf("%d",&n);
	printf("Enter the element:\n");
	for(i=0 ; i<n ; i++)
	{
		scanf("%d",&num);
		push(&top,num);
	}
	/*for(i=0;i<n;i++)
	{
		result = pop(&top);
		printf("%d\n",result->data);
		free(result);
    }*/
	mergll(&top);
	printf("sorted order is:\n");
	for(i=0 ; i<n ; i++)
	{
		result = pop(&top);
		printf("%d\n",result->data);
		free(result);
	}
	getch();
	return 0;
}

struct stacknode *createstack()
{
	return NULL;
}

void push(struct stacknode **element,int data)
{
	struct stacknode *newnode = (struct stacknode *)malloc(sizeof(struct stacknode));
	if(!newnode)
		return ;
	newnode->data = data;
	newnode->next = *element;

	*element = newnode;
}

int emptystack(struct stacknode *top)
{
	return (top==NULL);
}

struct stacknode *pop(struct stacknode **element)
{
	struct stacknode *temp;
	if(emptystack(*element))
	{
		printf("Stack is empty");
		return 0;
	}
	else
	{
		temp = *element;
		*element = temp->next;
	}
	return temp;
}

void mergll(struct stacknode **start)
{
	struct stacknode *head = *start;
	struct stacknode *left, *right;
	if(head == NULL || head->next == NULL)
		return ;

	split(head,&left,&right);
	mergll(&left);
	mergll(&right);

	head = sort_each(left,right);
}

void split(struct stacknode *source, struct stacknode **front, struct stacknode **back)
{
	struct stacknode *fast, *slow;
	if(source == NULL || source->next == NULL)
	{
		*front = source;
		*back = NULL;
	}
	else
	{
		slow = source;
		fast = source->next;
	}
	while(fast != NULL)
	{
		fast = fast->next;
		if(fast != NULL)
		{
			slow = slow ->next;
			fast = fast->next;
		}
	}
	*front = source;
	*back = slow->next;
	slow->next = NULL;
}

struct stacknode *sort_each(struct stacknode *left, struct stacknode *right)
{
	struct stacknode *result = NULL;
	if(left == NULL)
		return right;
	else if(right == NULL)
		return left;
	if(left->data <= right->data)
	{
		result = left;
		result->next = sort_each(left->next,right);
	}
	else
	{
		result = right;
		result->next = sort_each(left,right->next);
	}

	return result;
}
