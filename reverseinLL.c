/*
 ============================================================================
 Name        : reverseinLL.c
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

struct node *insert(struct node *,int, int);
void display(struct node *);
struct node *reverseiteration(struct node *);
struct node *reverserecursively(struct node *);

int main(void) {
	struct node *head = NULL;
	head = insert(head,1,0);
	head = insert(head,56,0);
	head = insert(head,8,0);
	head = insert(head,9,0);
	head = insert(head,17,2);
	head = insert(head,3,5);
	head = insert(head,99,4);
	head = reverseiteration(head);
	head = reverserecursively(head);
	display(head);
	return 0;
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

struct node *reverseiteration(struct node *head){
	struct node *newlist=NULL, *remaninglist=head;
	while(remaninglist != NULL){
		remaninglist = remaninglist->link;
		head->link = newlist;
		newlist = head;
		head = remaninglist;
	}
	return newlist;
}
struct node * reverserecursively(struct node *head){
	struct node *remaininglist=head, *recursivelist_head=NULL;
	if(head == NULL)
		return NULL;
	else if (head->link == NULL)
		return head;
	else {
		remaininglist = head->link;
		head->link = NULL;
		recursivelist_head = reverserecursively(remaininglist);
		remaininglist->link = head;
		return recursivelist_head;
	}
}
