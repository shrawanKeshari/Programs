/*
 ============================================================================
 Name        : kruskal.c
 Author      : Pawan Keshari
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct stacknode *pop(struct stacknode **);
struct graph *adjlist(struct graph *);
void push(struct stacknode **,int ,int ,int );
void sort(struct stacknode **);
void kruskal(struct graph *,struct stacknode *);
int find(int );
void unionbyrank(int , int );
//structure for adjacency listnode
struct adjlistnode
{
	int vn;
	int weight;
	struct adjlistnode *next;
};
//structure for graph
struct graph
{
	int v,e;
	struct adjlistnode **adj;
};
//structure for stack node
struct stacknode
{
	int src;
	int dest;
	int priority;
	struct stacknode *link;
};
//creating a stack
struct stacknode *createstack()
{
	return NULL;
}
struct set
{
	int parent;
	int rank;
}*subset;
//driving funtion main
int main()
{   int i;
	struct graph *g = (struct graph *)malloc(sizeof(struct graph));
	struct stacknode *top = NULL;
	struct adjlistnode *move;
	printf("Enter the number of vertices and edges:\n");
	scanf("%d %d",&g->v,&g->e);
	if(g->v ==0 || g->e ==0)
		return 0;
	g = adjlist(g);
	for(i=0 ; i<g->v; i++)
	{
		move = g->adj[i];
		while(move->next)
		{
			move = move->next;
			push(&top,i,move->vn,move->weight);
		}
	}
	kruskal(g,top);
	getch();
	return 0;
}
//creating a adjacency list
struct graph *adjlist(struct graph *g)
{
	int start,end,weight,i;
	struct adjlistnode *temp, *temp1, *move;
	if((!g) || g->v == 0 || g->e == 0)
	{
		printf("graph is NULL");
		return 0;
	}
	g->adj = (struct adjlistnode **)malloc(g->v * sizeof(struct adjlistnode));
	for(i=0; i<g->v ; i++)
	{
		g->adj[i] = (struct adjlistnode *)malloc(sizeof(struct adjlistnode));
		g->adj[i]->vn = i;
		g->adj[i]->weight = 0;
		g->adj[i]->next = NULL;
	}
	for(i=0 ;i<g->e ; i++)
	{
		printf("Enter the edges and its priority:\n");
		scanf("%d %d %d",&start,&end,&weight);
		move = g->adj[start];
		while(move->next)
			move = move->next;
		temp = (struct adjlistnode *)malloc(sizeof(struct adjlistnode));
		temp->vn = end;
		temp->weight = weight;
		temp->next = NULL;
		move->next = temp;

		move=g->adj[end];
		while(move->next)
			move=move->next;
		temp1=(struct adjlistnode *)malloc(sizeof(struct adjlistnode));
		temp1->vn=start;
		temp1->weight=weight;
		temp1->next=NULL;
		move->next=temp1;
	}
	return g;
}
//checking stack is empty or not
int emptystack(struct stacknode *element)
{
	return (element == NULL);
}
//pushing data in stack
void push(struct stacknode **element,int src,int dest,int priority)
{
	struct stacknode *newnode = (struct stacknode *)malloc(sizeof(struct stacknode));
	if(!newnode)
		return ;

	newnode->src = src;
	newnode->dest = dest;
	newnode->priority = priority;
	newnode->link = *element;

	*element = newnode;
}
//function for poping out data from stack and returns a pointer
struct stacknode *pop(struct stacknode **element)
{
	struct stacknode *temp;
	if(emptystack(*element))
	{
		printf("Stack is empty");
		return 0;
	}
	else
	{
		temp = *element;
		*element = temp->link;
	}
	return temp;
}
//kruskal funtion
void kruskal(struct graph *g,struct stacknode *head)
{
	struct stacknode *result[g->v];
	subset = (struct set *)malloc(g->v * sizeof(struct set));
	int i,j = 0;
	int sum = 0;
	struct stacknode *temp;
	for(i=0 ; i<g->v ; i++)
	{
		subset[i].parent = i;
		subset[i].rank = 0;
		result[i] = NULL;
	}
    sort(&head);
    printf("The minimum spannig tree is:\n");
    while(j < (g->v - 1))
    {
    	if(!emptystack(head))
    	{
    		temp = pop(&head);
    		if(find(temp->src) != find(temp->dest))
    		{
    			result[j] = temp;
    			unionbyrank(temp->src,temp->dest);
    			printf("%d----%d = %d\n",result[j]->src,result[j]->dest,result[j]->priority);
    			sum += result[j]->priority;
    			j++;
    			free(temp);
    		}
    	}
    	else
    		j++;
    }
    printf("%d",sum);
}
//funtion for sorting the linked list
void sort(struct stacknode **element)
{
	struct stacknode *source,*current,*prev,*nextpoint,*temp;
	source = NULL;
	while(source != (*element)->link)
	{
		current = prev = *element;
		nextpoint = current->link;
		while(current != source)
		{
			if(current->priority > nextpoint->priority)
			{
				if(current == *element)
				{
					temp = nextpoint->link;
					nextpoint->link = current;
					current->link = temp;
					*element = nextpoint;
					prev = nextpoint;
				}
				else
				{
					temp = nextpoint->link;
					nextpoint->link = current;
					current->link = temp;
					prev->link = nextpoint;
					prev = nextpoint;
				}
			}
			else
			{
				prev = current;
				current = current->link;
			}
			nextpoint = current->link;
			if(nextpoint == source)
				source = current;
		}
	}
}
//find funtion for checking whether the giving vertices is of same tree or not by using path comparession method
int find(int item)
{
	if(subset[item].parent == item)
		return subset[item].parent;
	else
		return (subset[item].parent = find(subset[item].parent));
}
//union funtion using union by rank
void unionbyrank(int root1, int root2)
{
	int x = find(root1);
	int y = find(root2);

	if(subset[x].rank < subset[y].rank)
		subset[x].parent = y;
	else if(subset[x].rank > subset[y].rank)
		subset[y].parent = x;
	else
	{
		subset[y].parent = x;
		subset[x].rank++;
	}
}
