/*
 ============================================================================
 Name        : bellmanford.c
 Author      : Pawan Keshari
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <limits.h>

struct graph *adjlist(struct graph *);
void bellmanford(struct graph *,int );
struct queue *createqueue();
void enqueue(struct queue *,int );
int emptyqueue(struct queue *);
int dequeue(struct queue *);

struct adjlistnode
{
	int vn;
	int weight;
	struct adjlistnode *link;
};

struct graph
{
	int v,e;
	struct adjlistnode **adj;
};

struct listnode
{
	int data;
	struct listnode *next;
};

struct queue
{
	struct listnode *front;
	struct listnode *rear;
};

int main()
{
	int start;
	struct graph *g=(struct graph *)malloc(sizeof(struct graph));
	printf("Enter the vertices and edges:\n");
	scanf("%d %d",&g->v,&g->e);
	g = adjlist(g);
	printf("Enter the source:\n");
	scanf("%d",&start);
	bellmanford(g,start);
	getch();
	return 0;
}

struct graph *adjlist(struct graph *g)
{
	int i,x,y,w;
	struct adjlistnode *temp, *move;
	if(!g)
		return 0;
	g->adj=(struct adjlistnode **)malloc(g->v*sizeof(struct adjlistnode));
	for(i=0;i<g->v;i++)
	{
		g->adj[i]=(struct adjlistnode *)malloc(sizeof(struct adjlistnode));
		g->adj[i]->vn=i;
		g->adj[i]->weight =0;
		g->adj[i]->link=NULL;
	}
	for(i=0;i<g->e;i++)
	{
		printf("Enter the edges:\n");
		scanf("%d %d",&x,&y);
		printf("enter the weight:\n");
	    scanf("%d",&w);
		move=g->adj[x];
		while(move->link)
			move = move->link;
		temp=(struct adjlistnode *)malloc(sizeof(struct adjlistnode));
		temp->vn=y;
		temp->weight=w;
		temp->link=NULL;
		move->link=temp;
	}
	return g;
}

void bellmanford(struct graph *g,int source)
{
	struct adjlistnode *temp;
	struct queue *q=createqueue();
	int i,vertex,newdist,src,dist;
	int *distance = (int *)malloc(g->v * sizeof(int));
	int *path = (int *)malloc(g->v * sizeof(int));
	int *check = (int *)malloc(g->v * sizeof(int));
	for(i=0;i<g->v;i++)
	{
		distance[i] = INT_MAX;
		path[i] = source;
		check[i] = 0;
	}
	distance[source]=0;
	enqueue(q,source);
    while(!emptyqueue(q))
    {
    	vertex=dequeue(q);
    	temp=g->adj[vertex];
    	while(temp->link)
    	{
    	    temp=temp->link;
    		newdist=distance[vertex] + temp->weight;
    		if(distance[temp->vn] > newdist )
    		{
    				distance[temp->vn]=newdist;
    				path[temp->vn]=vertex;
    				if(check[temp->vn] == 0)
    				{
    					enqueue(q,temp->vn);
    					check[temp->vn] = 1;
    				}
    		}
    	}
    }
    for(i=source;i<g->v;i++)
    {
    	src=g->adj[i]->vn;
    	temp=g->adj[i];
    	while(temp->link)
    	{
    		temp=temp->link;
    		dist=temp->vn;
    		if((distance[src] + temp->weight) < distance[dist])
    		{
    			printf("Graph has negative edge cycle:");
    			return;
    		}
    	}
    }
    for(i=0;i<g->v;i++)
    {
    	printf("distance of:%d from source:%d is:%d\n",i,source,distance[i]);
    	printf("path of shortest:%d\n",path[i]);
    }
}

struct queue *createqueue()
{
	struct queue *q=(struct queue *)malloc(sizeof(struct queue));
	if(!q)
		return 0;
	q->front = q->rear = NULL;
	return q;
}

void enqueue(struct queue *q,int data)
{
	struct listnode *newnode=(struct listnode *)malloc(sizeof(struct listnode));
	if(!newnode)
		return;
	newnode->data=data;
	newnode->next=NULL;
	if(q->rear)
		q->rear->next=newnode;
	q->rear=newnode;
	if(q->front==NULL)
		q->front=q->rear;
}

int emptyqueue(struct queue *q)
{
	return (q->front==NULL);
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
		data=q->front->data;
		q->front=q->front->next;
		free(temp);
	}
	return data;
}


