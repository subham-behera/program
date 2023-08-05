#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;

void enqueue();
void dequeue();
void display();

int main(){
	int op;
	while(1){
		printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		printf("Enter the choice:");
		scanf("%d",&op);
		switch(op){
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			default:
				exit(0);
			}
	}
	return 0;
}

void enqueue(){
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	if(newnode==NULL){
		printf("No memory Allocation.\n");
	}
	else{
		printf("Enter data:");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if(front==NULL && rear==NULL){
			front=rear=newnode;
		}
		else{
			rear->next=newnode;
			rear=newnode;
		}
	}
}

void dequeue(){
	struct node *temp;
	if(front==NULL){
		printf("Underflow\n");
	}
	else{
		temp=front;
		front=front->next;
		free(temp);
	}
}

void display(){
	struct node *temp;
	temp=front;
	printf("Front->");
	while(temp!=NULL){
		printf("<-%d->",temp->data);
		temp=temp->next;
	}
	printf("Rear\n");
}
