/*
 ============================================================================
 Name        : levelorder.c
 Author      : Pawan Keshari
 Version    
 :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct qnode
{
	struct qnode *qdata;
	struct qnode *next;
};

struct queue
{
	struct qnode *front;
	struct qnode *rear;
};

struct binarytreenode
{
	int data;
	struct binarytreenode *left;
	struct binarytreenode *right;
};

struct queue *createqueue()
{
	struct queue *q = (struct queue *)malloc(sizeof(struct queue));
	
if(!q)
		return 0;
	q->front = q->rear = NULL;
	return q;
}

int emptyqueue(struct queue *q)
{
	return (q->front==NULL);
}

void enqueue(struct queue *q,struct binarytreenode *item)
{
	
struct qnode *newnode = (struct qnode *)malloc(sizeof(struct qnode));
	if(!newnode)
	   return ;

	newnode->qdata = item;
	newnode->next = NULL;
	if(q->rear)
		q->rear->next = newnode;
	
q->rear = newnode;
	if(q->front==NULL)
		q->front = q->rear;
}

struct binarytreenode *dequeue(struct queue *q)
{
	struct binarytreenode *root;
	struct qnode *temp;

	if(emptyqueue(q))
	{
		printf("Queue is empty");
		return 0;
	}

	else
	{
		temp = q->front;
		root = temp->qdata;
	
	q->front = q->front->next;
		free(temp);
	}
	return root;
}

void deletequeue(struct queue *q)
{
	struct qnode *temp;
	
while(q->front)
	{
		temp = q->front;
		q->front = q->front->next;
		free(temp);
	}
	
free(q->front);
}
struct binarytreenode *createtree(struct binarytreenode **b,int data)
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

void levelorder(struct binarytreenode *b)

{
	struct binarytreenode *temp;
	
struct queue *q = createqueue();
	
if(!b)
		
return ;
	
enqueue(q,b);
	
while(!emptyqueue(q))
	
{
		
temp = dequeue(q);
		
printf("%d\n",temp->data);
		
if(temp->left)
			
enqueue(q,temp->left);
		
if(temp->right)
			
enqueue(q,temp->right);

	}
	
deletequeue(q);

}

int main()
{
	int n,i,num;
	struct binarytreenode *bt = NULL;
	printf("Enter the number of elements in tree:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the element:\n");
		scanf("%d",&num);
		bt = createtree(&bt,num);
	}
	printf("Levelorder traversal is:\n");
	levelorder(bt);
	getch();
	return 0;
}
