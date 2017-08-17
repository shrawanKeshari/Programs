/*
 ============================================================================
 Name        : avltree.c
 Author      : Pawan Keshari
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct avlnode
{
	int data;
	int height;
	struct avlnode *left;
	struct avlnode *right;
};
int height(struct avlnode *a)
{
	if(!a)
		return 0;
	return (a->height);
}
int max(int num1, int num2)
{
	return ((num1 > num2)? num1 : num2);
}
struct avlnode *SRL(struct avlnode *a)
{
	struct avlnode *temp = a->left;
	a->left = temp->right;
	temp->right = a;
	a->height = max(height(a->left),height(a->right)) + 1;
	temp->height = max(height(temp->left), a->height) + 1;
	return temp;
}
struct avlnode *SRR(struct avlnode *a)
{
	struct avlnode *temp = a->right;
	a->right = temp->left;
	temp->left = a;
	a->height = max(height(a->left),height(a->right)) + 1;
	temp->height = max(height(temp->right),a->height) + 1;
	return temp;
}
struct avlnode *DRL(struct avlnode *a)
{
	a->left = SRR(a->left);
	return (SRL(a));
}
struct avlnode *DRR(struct avlnode *a)
{
	a->right = SRL(a->right);
	return (SRR(a));
}
struct avlnode *createtree(struct avlnode **a, int item)
{
	if(*a == NULL)
	{
		*a = (struct avlnode *)malloc(sizeof(struct avlnode));
		if(*a == NULL)
			return 0;
		(*a)->data = item;
		(*a)->height = 0;
		(*a)->left = NULL;
		(*a)->right = NULL;
	}
	else if(item < (*a)->data)
	{
		(*a)->left = createtree(&((*a)->left),item);
		if((height((*a)->left) - height((*a)->right)) > 1)
		{
			if(item < (*a)->left->data)
				*a = SRL(*a);
			else
				*a = DRL(*a);
		}
	}
	else if(item > (*a)->data)
	{
		(*a)->right = createtree(&((*a)->right),item);
		if((height((*a)->right) - height((*a)->left)) > 1)
		{
			if(item > (*a)->right->data)
				*a = SRR(*a);
			else
				*a = DRR(*a);
		}
	}
	(*a)->height = max(height((*a)->left),height((*a)->right)) + 1;
	return *a;
}
void preorder(struct avlnode *a)
{
	if(a)
	{
		printf("%d\n",a->data);
		preorder(a->left);
		preorder(a->right);
	}
}
int main()
{
	int n,i,num;
	struct avlnode *at = NULL;
	printf("Enter the number of element of tree:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the element:\n");
		scanf("%d",&num);
		at = createtree(&at,num);
	}
	printf("preorder traversal is:\n");
	preorder(at);
	getch();
	return 0;
}
