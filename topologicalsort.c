/*
 ============================================================================
 Name        : topologicalsort.c
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
int *visited;
struct stacknode
{
	int vn;
	struct stacknode *next;
};
struct graph
{
	int v,e;
	struct stacknode **adj;
};
struct stacknode *createstack()
{
	return NULL;
}
void push(struct stacknode **top,int data)
{
	struct stacknode *temp=(struct stacknode *)malloc(sizeof(struct stacknode));
	if(!temp)
		return ;
	temp->vn=data;
	temp->next=*top;

	*top=temp;
	//printf("%d",temp->vn);
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
		printf("stack is empty");
		return 0;
	}
	else
	{
		temp=*top;
		*top=temp->next;
		data=temp->vn;
		free(temp);
	}
	return data;
}
struct graph *adjlist(struct graph *g)
{
	int i,x,y;
	struct stacknode *temp1, *move;
	if(!g)
		return 0;
	g->adj=(struct stacknode **)malloc(g->v*sizeof(struct stacknode));
	for(i=0;i<g->v;i++)
	{
		g->adj[i]=(struct stacknode *)malloc(sizeof(struct stacknode));
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
		temp1=(struct stacknode *)malloc(sizeof(struct stacknode));
		temp1->vn=y;
		temp1->next=NULL;
		move->next=temp1;
	}
	return g;
}
void topologicalsort(struct graph *g,int vertex, struct stacknode **s)
{
	struct stacknode *temp=g->adj[vertex];
	visited[vertex]=1;
	while(temp->next)
	{
		temp=temp->next;
		if(!visited[temp->vn])
		{
			topologicalsort(g,temp->vn,s);
		}
	}
	push(s,vertex);
}
void topological(struct graph *g)
{
    struct stacknode *s=createstack();
	int i,ver;
	visited=(int *)malloc(g->v*sizeof(int));
	for(i=0;i<g->v;i++)
		visited[i]=0;
	for(i=0;i<g->v;i++)
	{
		if(!visited[i])
		{
			topologicalsort(g,i,&s);
		}
	}
	 while(s!=NULL)
	 {
	     ver=pop(&s);
		 printf("%d",ver);
	 }
}
int main()
{
	struct graph *g=(struct graph *)malloc(sizeof(struct graph));
	printf("Enter the vertices and edegs:\n");
	scanf("%d %d",&g->v,&g->e);
	g = adjlist(g);
	printf("Topological sort is:");
	topological(g);
	getch();
	return 0;
}
