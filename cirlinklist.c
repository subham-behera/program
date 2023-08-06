#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head=NULL;

void create();
void display();
void insert_beg();
void insert_end();
void insert_pos();
void delete_beg();
void delete_end();
void delete_pos();
void delete_num();

int main(){
	int op;
	while(1){
		printf("\n1.Create\n2.Display\n3.insert_beg\n4.insert_end\n5.insert_pos\n6.delete_beg\n7.delete_end\n8.delete_pos\n9.delete_num\n10.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&op);
		switch(op){
			case 1:
				create();
				break;
			case 2:
				display();
				break;
			case 3:
				insert_beg();
				break;
			case 4:
				insert_end();
				break;
			case 5:
				insert_pos();
				break;
			case 6:
				delete_beg();
				break;
			case 7:
				delete_end();
				break;
			case 8:
				delete_pos();
				break;
			case 9:
				delete_num();
				break;
			default:
				exit(0);
		}
	}
	return 0;
}

void create(){
	struct node *temp,*newnode;
	int ch=1;
	while(ch){
		newnode=(struct node *)malloc(sizeof(struct node));
		if(newnode==NULL){
			printf("No memory Allocation\n");
		}
		else{
			printf("Enter data:");
			scanf("%d",&newnode->data);
			newnode->next=NULL;
			if(head==NULL){
				temp=head=newnode;
			}
			else{
				temp=head;
				while(temp->next!=head){
					temp=temp->next;
				}
				temp->next=newnode;
				temp=newnode;
			}
			temp->next=head;
			printf("Continue-->(0/1)");
			scanf("%d",&ch);
		}
	}
}

void display(){
	struct node *temp;
	if(head==NULL){
		printf("Empty list\n");
	}
	else{
		temp=head;
		while(temp->next!=head){
			printf("<--%d-->",temp->data);
			temp=temp->next;
		}
		printf("<--%d-->",temp->data);
	}
}

void insert_beg(){
	struct node *newnode,*temp;
	newnode=(struct node *)malloc(sizeof(struct node));
	if(newnode==NULL){
		printf("No memory allocation\n");
	}
	else{
		if(head==NULL){
			printf("Enter data:");
			scanf("%d",&newnode->data);

			head=newnode;
			newnode->next=head;
		}
		else{
			printf("Enter data:");
			scanf("%d",&newnode->data);
			temp=head;
			while(temp->next!=head){
				temp=temp->next;
			}
			newnode->next=head;
			temp->next=newnode;
			head=newnode;
		}
	}
}

void insert_end(){
	struct node *newnode,*temp;
	newnode=(struct node *)malloc(sizeof(struct node));
	if(newnode==NULL){
		printf("No memory allocation\n");
	}
	else{
		printf("Enter Data:");
		scanf("%d",&newnode->data);
		if(head==NULL){
			head=newnode;
			newnode->next=head;
		}
		else{
			temp=head;
			while(temp->next!=head){
				temp=temp->next;
			}
			newnode->next=head;
			temp->next=newnode;
		}
	}
}

void insert_pos(){
	struct node *newnode,*temp;
	newnode=(struct node *)malloc(sizeof(struct node));
	int pos;
	if(newnode==NULL){
		printf("No memory Allocation\n");
	}
	else{
		printf("Enter data:");
		scanf("%d",&newnode->data);
		temp=head;
		printf("Enter Position:");
		scanf("%d",&pos);
		while(--pos>1){
			temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}
}

void delete_beg(){
	struct node *temp,*last;
	temp=head;
	if(head==NULL){
		printf("Empty List");
	}
	else{
		if(head->next==head){
			head=NULL;
			free(temp);
		}
		else{
			while(temp->next!=head){
				temp=temp->next;
			}
			last=temp;
			temp=head;
			last->next=head=head->next;
			free(temp);
		}
	}
}

void delete_end(){
	struct node *temp=head,*last;
	if(head==NULL){
		printf("Empty List\n");
	}
	else{	
		if(temp->next==head){
			head=NULL;
			free(temp);
			return ;
		}
		while(temp->next!=head){
			last=temp;
			temp=temp->next;
		}
		last->next=head;
		temp->next=NULL;
		free(temp);
	}
}

void delete_pos(){
	struct node *temp=head,*last;
	int pos;
	if(head==NULL){
		printf("Empty List\n");
	}
	else{
		printf("Enter Position:");
		scanf("%d",&pos);
		while(pos>1){
			pos-=1;
			last=temp;
			temp=temp->next;
		}
		last->next=temp->next;
		temp->next=NULL;
		free(temp);
	}
}

void delete_num(){
	struct node *temp=head,*last;
	int num;
	if(head==NULL){
		printf("Empty List\n");
	}
	else{
		printf("Enter Number:");
		scanf("%d",&num);
		while(temp->data!=num && temp->next!=head){
			last=temp;
			temp=temp->next;
		}
		last->next=temp->next;
		temp->next=NULL;
		free(temp);
	}
}

