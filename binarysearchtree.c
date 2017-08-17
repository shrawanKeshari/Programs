/*
 ============================================================================
 Name        : binarysearchtree.c
 Author      : Pawan Keshari
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct bstnode
{
	int data;
	struct bstnode *left;
	struct bstnode *right;
};
struct bstnode *find(struct bstnode *b, int item)
{
	if(!b)
		return 0;
	while(b)
	{
		if(item == b->data)
			return b;
		else if(item < b->data)
			b = b->left;
		else
			b = b->right;
	}
	return 0;
}

struct bstnode *createbst(struct bstnode **b,int data)
{
	if(*b==NULL)
	{
		*b = (struct bstnode *)malloc(sizeof(struct bstnode));
		(*b)->data = data;
		(*b)->left = NULL;
		(*b)->right = NULL;
	}
	else
	{
		if(data < (*b)->data)
			createbst(&((*b)->left),data);
		else
			createbst(&((*b)->right),data);
	}
	return *b;
}
struct bstnode *findmin(struct bstnode *b)
{
	if(!b)
		return 0;
	while(b->left)
		b = b->left;
	return b;
}
struct bstnode *findmax(struct bstnode *b)
{
	if(!b)
		return 0;
	while(b->right)
		b = b->right;
	return b;
}
struct bstnode *delete(struct bstnode *b,int item)
{
	struct bstnode *temp;
	if(b == NULL)
		return 0;
	else if(item < b->data)
		b->left = delete(b->left,item);
	else if(item >b->data)
		b->right = delete(b->right,item);
	else
	{
		if(b->left && b->right)
		{
			temp = findmax(b->left);
			b->data = temp->data;
			b->left = delete(b->left,b->data);
		}
		else
		{
			if(b->left == NULL)
			{
				temp = b;
				b = b->right;
				free(temp);
				return b;
			}
			else if(b->right == NULL)
			{
				temp = b;
				b = b->right;
				free(temp);
				return b;
			}
		}
	}
	return b;
}
void inorder(struct bstnode *b)
{
	if(b)
	{
		inorder(b->left);
		printf("%d\t",b->data);
		inorder(b->right);
	}
}
int main()
{
	int n,i,num,delelement;
	char choice;
	struct bstnode *bt = NULL;
	printf("Enter the number of elements in tree:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the element:\n");
		scanf("%d",&num);
		bt = createbst(&bt,num);
	}
	printf("Inorder traversal is:\n");
	inorder(bt);
	printf("do u want to delete an element:\n");
	choice = getche();
	while(choice == 'Y')
	{
		printf("Enter the elemet to be delete:\n");
		scanf("%d",&delelement);
		delete(bt,delelement);
		printf("Inorder traversal is:\n");
		inorder(bt);
		printf("Want to delete more element:\n");
		choice = getche();
	}
	getch();
	return 0;
}
