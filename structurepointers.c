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
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};

void append(struct node**,int);
void display(struct node*);
void nthnodefromend(struct node*, int);

int main(void) {
	struct node *head = NULL;

	append(&head,40);
	append(&head,2);
	append(&head,3);
	append(&head,4);
	append(&head,50);
	display(head);
	nthnodefromend(head,2);
	nthnodefromend(head,3);
	nthnodefromend(head,4);
	return 0;
}

void append(struct node**head,int num){
	struct node *traverse=*head, *newnode;

	newnode = (struct node *)malloc(sizeof(struct node *));
	(*newnode).data = num;
	newnode->link = NULL;

	if(traverse == NULL)
		*head = newnode;
	else{
		while(traverse->link != NULL){
			traverse = traverse->link;
		}
		traverse->link = newnode;
	}
}

void display(struct node *head){
	while(head != NULL){
		printf("%d->",head->data);
		head = head->link;
		if(head == NULL)
			printf("NULL\n");
	}
}

void nthnodefromend(struct node*head, int pos){
	struct node *traverse = head;
	int count = 0;
	while(traverse != NULL){
		count++;
		if(count-pos>0){
			head = head->link;;
		}
		traverse = traverse->link;
	}
	printf("The %d Node from End is : %d\n",pos,head->data);
}
