/*
 ============================================================================
 Name        : nthnodefromend.c
 Author      : Pawan Keshari
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;
};

void nthnodefromend(struct node*, int endloc);
struct node *insert(struct node *,int, int);
void display(struct node *);

int main(void) {
	struct node *head = NULL;
	head = insert(head,1,0);
	head = insert(head,56,0);
	head = insert(head,8,0);
	head = insert(head,9,0);
	head = insert(head,17,2);
	head = insert(head,3,5);
	head = insert(head,99,4);
	nthnodefromend(head,1);
	display(head);
	return 0;
}

void nthnodefromend(struct node *head, int endloc){
	struct node *first = head,*second = head;
	int count=1;
	if(head == NULL){
		printf("List Empty!!!\n");
		return;
	}
	if(endloc == 0){
		printf("Cannot find 0th Node from end!!!\n");
		return;
	}
	while(first->link != NULL){
		if(count < endloc)
			first = first->link;
		else{
			first = first->link;
			second = second->link;
		}
		count++;
	}
	if(count < endloc)
		printf("The List is not Large enough to locate the desired node\n");
	else
		printf("The %d node from end is : %d\n", endloc, second->data);
}

struct node *insert(struct node *head, int num, int pos){
	struct node *temp=head, *newnode;
	int count =1;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = num;
	if(head == NULL){
		newnode->link = NULL;
		head = newnode;
	}
	else if(pos == 0){
		newnode->link = head;
		head = newnode;
	}
	else if(pos != 0){
		while(count < pos){
			temp = temp->link;
			count++;
		}
		newnode->link = temp->link;
		temp->link = newnode;
	}
	return head;
}

void display(struct node *head){
	struct node *temp=head;
	printf("List is : ");
	while(temp != NULL){
		(temp->link)?(printf("%d->",temp->data)):(printf("%d",temp->data));
		temp = temp->link;
	}
}
