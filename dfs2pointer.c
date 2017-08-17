/*
 ============================================================================
 Name        : d.c
 Author      : Pawan Keshari
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
*/




#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>
#define max 8
int visited[max];
struct listnode
{
	int vn;
	struct listnode *next;
};
struct graph
{
	int v;
	int e;
	struct listnode **adj;
};

struct queue
{
	struct listnode *front;
	struct listnode *rear;
};
struct queue *createqueue()
{

	struct queue *q=(struct queue *)malloc(sizeof(struct queue));
	if(!q)
		return 0;
	q->front=q->rear=NULL;
	return q;
}
int emptyqueue(struct queue *q)
{
	return (q->front==NULL);
}
void enqueue(struct queue *q,int data)
{
	struct listnode *newnode=(struct listnode *)malloc(sizeof(struct listnode));
	if(!newnode)
		return ;
	newnode->vn=data;
	newnode->next=NULL;
	if(q->rear)
		q->rear->next=newnode;
	q->rear=newnode;
	if(q->front==NULL)
		q->front=q->rear;
}
int dequeue(struct queue *q)
{
	int data=0;
	struct listnode *temp;
	if(emptyqueue(q))
	{
		printf("queue is empty");
		return 0;
	}
	else
	{
		temp=q->front;
		data=q->front->vn;
		q->front=q->front->next;
		free(temp);
	}
	return data;
}
struct graph *Adjlist(struct graph *g)
{
	int i,x,y;
	struct listnode *temp1,*temp2, *move;
	if(!g)
		return 0;

	g->adj=(struct listnode**)malloc(g->v*sizeof(struct listnode));
	//printf("a");
	for(i=0;i<g->v;i++)
	{
		g->adj[i]=(struct listnode *)malloc(sizeof(struct listnode));
		g->adj[i]->vn = i;
		g->adj[i]->next=NULL;

	}
	//printf("a");
	for(i=0;i<g->e;i++)
	{   printf("enter edges:\n");
		scanf("%d %d",&x,&y);
		//printf("a");
          move=g->adj[x];
         while(move->next)
        	 move=move->next;
		   temp1=(struct listnode *)malloc(sizeof(struct listnode));
		   temp1->vn=y;
		   temp1->next=NULL;
		   move->next=temp1;

		//for undirected graph
         move=g->adj[y];
         while(move->next)
        	 move=move->next;
		temp2=(struct listnode *)malloc(sizeof(struct listnode));
		temp2->vn=x;
		temp2->next=NULL;
		move->next=temp2;
	}
	//printf("5");
	return g;
}
void dfstraversal(struct graph *g, int vertex)
{
	struct listnode* temp = g->adj[vertex];
	visited[vertex]=1;
	printf("%d\n",vertex);
	//printf("3");
	while(temp->next)
	{   //printf("4");
		temp = temp->next;
		{   //printf("5");
			if(!visited[temp->vn])
			{   //printf("6");
				dfstraversal(g,temp->vn);
			}
			//printf("7");
		}
		//printf("8");
	}
	//printf("9");
}
void dfs(struct graph *g)
{
    int i;
	for(i=0;i<g->v;i++)
		visited[i]=0;
	for(i=0;i<g->v;i++)
		{if(!visited[i])
		    {//printf("2");
			 dfstraversal(g,i);
		    }
		}
}
int main()
{

	struct graph *g=(struct graph *)malloc(sizeof(struct graph));
	printf("enter the vertices and edges:\n");
	scanf("%d %d",&g->v,&g->e);
	//printf("1");
	g = Adjlist(g);
	printf("dfs of given graph:");
	dfs(g);
	getch();
	return 0;
}

