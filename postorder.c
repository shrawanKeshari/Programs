/*
 ============================================================================
 Name        : postorder.c
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
	struct stacknode *sdata;
	struct stacknode *next;
};
struct binarytreenode
{
	int data;
	struct binarytreenode *left;
	struct binarytreenode *right;
};
struct stacknode *createstack()
{
	return NULL;
}
void push(struct stacknode **top, struct binarytreenode *item)
{
	struct stacknode *newnode = (struct stacknode *)malloc(sizeof(struct stacknode));
	if(!newnode)
		return;
	newnode->sdata = item;
	newnode->next = *top;

	*top = newnode;
}
int emptystack(struct stacknode *top)
{
	return (top == NULL);
}
struct binarytreenode *pop(struct stacknode **top)
{
	struct binarytreenode *pop;
	struct stacknode *temp;
	if(emptystack(*top))
	{
		printf("Stack is empty");
		return 0;
	}
	else
	{
		temp = *top;
		pop = temp->sdata;
		*top = temp->next;
		free(temp);
	}
	return pop;
}
void deletestack(struct stacknode **top	)
{
	struct stacknode *temp1, *temp2;
	temp1 = *top;
	while(temp1->next)
	{
		temp2 = temp1->next;
		temp1->next = temp2->next;
		free(temp2);
	}
	free(temp1);
}
struct binarytreenode *createtree(struct binarytreenode **b, int data)
{
	if(*b==NULL)
	{
		*b = (struct binarytreenode *)malloc(sizeof(struct binarytreenode));
		(*b)->data = data;
		(*b)->left = NULL;
		(*b)->right = NULL;
	}
	else
	{
		if(data < (*b)->data)
			createtree(&((*b)->left),data);
		else
			createtree(&((*b)->right),data);
	}
	return *b;
}
void postorder(struct binarytreenode *b)
{
	struct binarytreenode *temp;
	struct stacknode *start = createstack();
	struct stacknode *output = createstack();
	push(&start,b);
	while(!emptystack(start))
	{
		b = pop(&start);
		push(&output,b);
		if(b->left)
			push(&start,b->left);
		if(b->right)
			push(&start,b->right);
	}
	while(!emptystack(output))
	{
		temp = pop(&output);
		printf("%d\n",temp->data);
	}
	//deletestack(&start);
	//deletestack(&output);
}
/*void postorder(struct binarytreenode *b)
{
	if(b)
	{
		postorder(b->left);
		postorder(b->right);
		printf("%d\n",b->data);
	}
}*/
int main()
{
	int n,i,num;
	struct binarytreenode *bt = NULL;
	printf("Enter the number of element in tree:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the element:\n");
		scanf("%d",&num);
		bt = createtree(&bt,num);
	}
	printf("Postorder traversal is:\n");
	postorder(bt);
	getch();
	return 0;
}
