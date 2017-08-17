/*
 ============================================================================
 Name        : detectcycleinLL.c
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
struct node *insertloop(struct node *);
void display(struct node *);
void detectcycle(struct node *);

int main(void) {
	struct node *head = NULL;
	head = insert(head,1,0);
	head = insert(head,56,0);
	head = insert(head,8,0);
	head = insert(head,9,0);
	head = insert(head,17,2);
	head = insert(head,3,5);
	head = insert(head,99,4);
	head = insertloop(head);
	//display(head);
	detectcycle(head);
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

void detectcycle(struct node *head){
	struct node *slow = head, *fast = head;
	int count=1;
	while(slow->link && fast->link){
		slow = slow->link;
		fast = fast->link->link;
		if(slow == fast){
			printf("Loop detected...\n");
			break;
		}
	}
	if(slow == fast){
		slow = head;
		while(slow != fast){
			slow = slow->link;
			fast = fast->link;
			count++;
		}
		printf("The Node no at which loop starts is: %d\n", count);
		slow = fast;
		slow = slow->link;
		count = 1;
		while(slow != fast){
			slow = slow->link;
			count++;
		}
		printf("The length of loop is : %d\n", count);

	}
	else
		printf("\nThe loop is not present\n");
}

struct node *insertloop(struct node *head){
	struct node *traverse=head, *temp;
	while(traverse->link != NULL){
		if(traverse->data == 17)
			temp = traverse;
		traverse = traverse->link;
	}
	traverse->link = temp;
	return head;
}
