/*
 ============================================================================
 Name        : stack.c
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
	struct listnode *next;
};
struct stacknode *createstack()
{
	return NULL;
}
void push(struct stacknode **top, int data)
{
	struct stacknode *newnode=(struct stacknode *)malloc(sizeof(struct stacknode));
	if(!newnode)
		return;
	newnode->data = data;
	newnode->next = *top;

	*top = newnode;
}
int emptystack(struct stacknode *top)
{
	return (top==NULL);
}
int pop(struct stacknode **top)
{
	int data;
	struct stacknode *temp;
	if(emptystack(*top))
	{
		printf("Stack is empty");
		return 0;
	}
	else
	{
		temp = *top;
		data = temp->data;
		*top = temp->next;
		free(temp);
	}
	return data;
}
int main()
{
	int n,i,num,out;
	struct stacknode *top;
	top=NULL;
	printf("Enter the number of elements;\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the element:\n");
		scanf("%d",&num);
		push(&top,num);
	}
	for(i=0;i<n;i++)
	{
		out=pop(&top);
		printf("%d",out);
	}
	getch();
	return 0;
}
