/*
 ============================================================================
 Name        : dijkstra.c
 Author      : Pawan Keshari
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <conio.h>

struct dijkstranode
{
	int vn;
	int priority;
	struct dijkstranode *next;
};
struct graph
{
	int v,e;
	struct dijkstranode **adj;
};

struct minheap
{
	int count;
	int size;
	struct dijkstranode **array;
};

int *distance;
int *path;
struct graph *adjlist(struct graph *);
void dijkstra(struct graph *,int );
struct minheap *createminheap(int );
void insert(struct minheap *,struct dijkstranode *);
struct minheap *resizeheap(struct minheap *);
int emptyheap(struct minheap *);
struct dijkstranode *deletemin(struct minheap **);
struct minheap *minheapify(struct minheap *,int );
void swap(struct dijkstranode **,struct dijkstranode **);

int main()
{
	int start;
	struct graph *g=(struct graph *)malloc(sizeof(struct graph));
	distance=(int *)malloc(g->v*sizeof(int));
	path=(int *)malloc(g->v*sizeof(int));
	printf("Enter the vertices and edges:\n");
	scanf("%d %d",&g->v,&g->e);
	g= adjlist(g);
	printf("Enter the source;\n");
	scanf("%d",&start);
	dijkstra(g,start);
	getch();
	return 0;
}

struct graph *adjlist(struct graph *g)
{
	int i,src,dest,weight;
	struct dijkstranode *temp, *move;
	if(!g)
		return 0;
	g->adj=(struct dijkstranode **)malloc(g->v*sizeof(struct dijkstranode));
	for(i=0;i<g->v;i++)
	{
		g->adj[i]=(struct dijkstranode *)malloc(sizeof(struct dijkstranode));
		g->adj[i]->vn=i;
		g->adj[i]->priority = 0;
		g->adj[i]->next=NULL;
	}
	for(i=0;i<g->e;i++)
	{
		printf("enter the edges:\n");
		scanf("%d %d",&src,&dest);
		printf("enter the weight:\n");
		scanf("%d",&weight);
		move=g->adj[src];
		while(move->next)
			move=move->next;
		temp=(struct dijkstranode *)malloc(sizeof(struct dijkstranode));
		temp->vn=dest;
		temp->priority=weight;
		temp->next=NULL;
		move->next=temp;
	}
	return g;
}

void dijkstra(struct graph *g,int source)
{
	int i,d;
	struct dijkstranode *temp, *min = NULL;
	struct minheap *h=createminheap(g->v);
	for(i=0;i<g->v;i++)
	{
		distance[i]=INT_MAX;
		path[i]=source;
	}
	distance[source]=0;
	insert(h,g->adj[source]);
	while(!emptyheap(h))
	{
		min=deletemin(&h);
		temp=min->next;
		while(temp)
		{
			d= distance[min->vn] + temp->priority;
			if(distance[temp->vn]==INT_MAX)
			{
				distance[temp->vn]=d;
				insert(h,g->adj[temp->vn]);
				path[temp->vn]=min->vn;
			}
			if(distance[temp->vn]>d)
			{
				distance[temp->vn]=d;
				insert(h,g->adj[temp->vn]);
				path[temp->vn]=min->vn;
			}
			temp = temp->next;
		}
	}
	for(i=0;i<g->v;i++)
	{
		printf("distance of: %d from source: %d is %d\n",i,source,distance[i]);
		printf("path of shortest distance:%d\n",path[i]);
	}
	//for prims algorith
	printf("\nThe minimum spannig tree is:\n");
	for(i=1;i<g->v;i++)
	{
		printf("%d----%d = %d\n",path[i],i,(distance[i] - distance[path[i]]));
	}
}

struct minheap *createminheap(int capacity)
{
	struct minheap *h=(struct minheap *)malloc(sizeof(struct minheap));
	if(!h)
		return 0;
	h->count=0;
	h->size=capacity;
	h->array=(struct dijkstranode **)malloc(capacity * sizeof(struct dijkstranode));
	if(!h->array)
		return 0;

	return h;
}

void insert(struct minheap *h,struct dijkstranode *newnode)
{
	int i;
    if(h->count == h->size)
   	     h = resizeheap(h);
	h->count++;
    i = h->count - 1;
	while(i>0 && (distance[newnode->vn] < distance[h->array[(i-1)/2]->vn]))
	{
		h->array[i] = h->array[(i-1)/2];
		i=((i-1)/2);
	}
	h->array[i] = newnode;
}

struct minheap *resizeheap(struct minheap *h)
{
	int i;
	struct dijkstranode **new_array = h->array;
	h->array = (struct dijkstranode **)malloc(h->size * 2 * sizeof(struct dijkstranode));
	for(i = 0; i<h->size; i++)
		new_array[i] = h->array[i];
	h->size = h->size*2;
	free(new_array);
	return h;
}

int emptyheap(struct minheap *h)
{
	return (h->count==0);
}

struct dijkstranode *deletemin(struct minheap **h)
{
	struct dijkstranode *min;
	if(emptyheap(*h))
		return 0;
	min = (*h)->array[0];
	(*h)->array[0] = (*h)->array[(*h)->count - 1];
	(*h)->count -= 1;
	*h = minheapify(*h,0);
	return min;
}

struct minheap *minheapify(struct minheap *h,int index)
{
	int left,right,min;
	min=index;
	left=2*index+1;
	right=2*index+2;
	if((left < h->count)&&(h->array[left]->priority < h->array[min]->priority))
		min=left;
	if((right < h->count)&&(h->array[right]->priority < h->array[min]->priority))
		min=right;
	if(min!=index)
	{
		swap(&h->array[index],&h->array[min]);
		h = minheapify(h,min);
	}
return h;
}

void swap(struct dijkstranode **current,struct dijkstranode **swapped)
{
	struct dijkstranode *temp;
	temp=*current;
	*current=*swapped;
	*swapped=temp;
}

