/*
 ============================================================================
 Name        : shortpathunweighted.c
 Author      : Pawan Keshari
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct listnode
{
	int vn;
	struct listnode *next;
};
struct queue
{
	struct listnode *front;
	struct listnode *rear;
};
struct graph
{
	int v,e;
	struct listnode **adj;
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
		return;
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
	int data;
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
void deletequeue(struct queue *q)
{
	struct listnode *temp;
	while(q->front)
	{
		temp=q->front;
		if(q->front==q->rear)
		{
			q->front=q->rear=NULL;
		}
		else
		{
			q->front=q->front->next;
		}
		free(temp);

	}
	free(q);
}
struct graph *adjlist(struct graph *g)
{
	int i,x,y;
	struct listnode *temp,*move;
	if(!g)
		return 0;
	g->adj=(struct listnode **)malloc(g->v*sizeof(struct listnode));
	for(i=0;i<g->v;i++)
	{
		g->adj[i]=(struct listnode *)malloc(sizeof(struct listnode));
		g->adj[i]->vn=i;
		g->adj[i]->next=NULL;
	}
	for(i=0;i<g->e;i++)
	{
		printf("Enter the edges:\n");
		scanf("%d %d",&x,&y);
		move=g->adj[x];
		while(move->next)
			move=move->next;
		temp=(struct listnode *)malloc(sizeof(struct listnode));
		temp->vn=y;
		temp->next=NULL;
		move->next=temp;
	}
	return g;
}
void shortpathunweighted(struct graph *g,int source)
{
	struct queue *q=createqueue();
	int i,vertex;
	struct listnode *temp;
	int *distance=(int *)malloc(g->v*sizeof(int));
	int *path=(int *)malloc(g->v*sizeof(int));
	enqueue(q,source);
	for(i=0;i<g->v;i++)
		distance[i]=-1;
	distance[source]=0;
	while(!emptyqueue(q))
	{
		vertex=dequeue(q);
		temp=g->adj[vertex];
		while(temp->next)
		{
			temp=temp->next;
			if(distance[temp->vn]==-1)
			{
				distance[temp->vn]=distance[vertex]+1;
				printf("distance of: %d from source: %d is %d\n",temp->vn,source,distance[temp->vn]);
				path[temp->vn]=vertex;
				printf("path of shortest distance:%d\n",path[temp->vn]);
				enqueue(q,temp->vn);
			}
		}
	}
	deletequeue(q);
}
int main()
{
	int start;
	struct graph *g=(struct graph *)malloc(sizeof(struct graph));
	printf("enter the vertices and edges:\n");
	scanf("%d %d",&g->v,&g->e);
	g=adjlist(g);
	printf("enter the source:\n");
	scanf("%d",&start);
	shortpathunweighted(g,start);
	getch();
	return 0;
}
