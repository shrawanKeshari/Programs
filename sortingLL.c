/*
 ============================================================================
 Name        : sortingLL.c
 Author      : Pawan Keshari
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct stacknode
{
	int data;
	int priority;
	struct stacknode *next;
};

struct stacknode *createstack()
{
	return NULL;
}

void push(struct stacknode **element,int data,int priority)
{
	struct stacknode *newnode = (struct stacknode *)malloc(sizeof(struct stacknode));
	if(!newnode)
		return ;
	newnode->data = data;
	newnode->priority = priority;
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

void sort(struct stacknode **element)
{
	struct stacknode *source, *prev, *current, *nextpoint, *temp;
	source = NULL;
	while(source != (*element)->next)
	{
		current = prev = *element;
		nextpoint = current->next;
		while(current != source)
		{
			if(current->data > nextpoint->data)
			{
				if(current == *element)
				{
					temp = nextpoint->next;
					nextpoint->next = current;
					current->next = temp;
					*element = nextpoint;
					prev = nextpoint;
				}
				else
				{
					temp = nextpoint->next;
					nextpoint->next = current;
					current->next = temp;
					prev->next = nextpoint;
					prev = nextpoint;
				}
			}
			else
			{
				prev = current;
				current = current->next;
			}
			nextpoint = current->next;
			if(nextpoint == source)
				source = current;
		}
	}
}

int main()
{
	int n,i,num,prior;
	struct stacknode *top = NULL;
	struct stacknode *result;
	printf("Enter the number of elements:\n");
	scanf("%d",&n);
	for(i=0 ; i<n ; i++)
	{
		printf("Enter the element an priority:\n");
		scanf("%d %d",&num,&prior);
		push(&top,num,prior);
	}
	/*for(i=0;i<n;i++)
	{
		result = pop(&top);
		printf("%d\n",result->data);
		free(result);
    }*/
	sort(&top);
	printf("sorted order is:\n");
	for(i=0 ; i<n ; i++)
	{
		result = pop(&top);
		printf("data:%d , priority:%d\n",result->data,result->priority);
		free(result);
	}
	getch();
	return 0;
}
