#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head=NULL;
struct node *newnode;

void create();
void display();
void insert_beg();
void insert_end();
void insert_pos();
void delete_beg();
void delete_end();
void delete_pos();
void delete_data();
void reverse();

int main()
{
	int op;
	while(1)
	{
		printf("\n1.Create\n2.Display\n3.Insert at beginning\n4.Insert at End\n5.Insert at position\n6.Delete from beginning\n7.Delete from end\n8.Delete from position\n9.Delete data\n10.Reverse\n11.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&op);
		switch(op)
		{
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
				/*
			case 9:
				delete_data();
				break;
			case 10:
				reverse();
				break;*/
			default:
				exit(0);
		}
		printf("\n");
	}
	return 0;
}

void create()
{
	struct node *temp;
	int ch=1;
	while(ch)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter the data:");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		newnode->prev=NULL;
		if(head==NULL)
		{	
			head=temp=newnode;
		}
		else{

			temp->next=newnode;
			newnode->prev=temp;
			temp=newnode;
		}
		printf("Continue?(0/1)");
		scanf("%d",&ch);
	}
}

void insert_beg()
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter data:");
	scanf("%d",&newnode->data);
	newnode->next==NULL;
	newnode->prev==NULL;
	head->prev==newnode;
	newnode->next=head;
	head=newnode;
}

void insert_end()
{
	struct node *newnode,*temp;
	temp=head;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter Data:");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	newnode->prev=NULL;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->prev=temp;
}

void insert_pos(){
	struct node *temp1,*temp2;
	int pos;
	temp1=head;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter the position:");
	scanf("%d",&pos);
	printf("Enter Data:");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	newnode->prev=NULL;
	while(pos>2){
		temp1=temp1->next;
		pos--;
	}
	temp2=temp1->next;
	newnode->next=temp1->next;
	temp1->prev=temp1;
	temp1->next=newnode;
	temp2->prev=newnode;
}

void delete_beg(){
	struct node *temp;
	if(head==NULL){
		printf("Underflow.\n");
	}
	else if(head->next==NULL){
		head=NULL;
		free(head);
		printf("Node Deleted\n");
	}
	else{
		temp=head;
		head=head->next;
		head->prev=NULL;
		free(temp);
		printf("Node Deleted.\n");
	}
}

void delete_end(){
	struct node *temp;
	if(head==NULL){
		printf("Underflow\n");
	}
	else if(head->next==NULL){
		head=NULL;
		free(head);
		printf("Node deleted\n");
	}
	else{
		temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->prev->next=NULL;
		free(temp);
		printf("Node deleted\n");
	}
}

void delete_pos(){
	struct node *temp,*temp2;
	int pos;
	temp=head;
	printf("Enter the position to delete:");
	scanf("%d",&pos);
	while(pos>1){
		temp=temp->next;
		pos--;
	}
	/*
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
	*/
	temp2=temp->prev;

	temp2->next=temp->next;
	temp->next->prev=temp->prev;
	free(temp);
	printf("Node deleted\n");
}
/*
void delete_data(){
	struct node *temp,*temp2;
	temp=head;
	int key;
	printf("Enter the key:");
	scanf("%d",&key);
	while(temp->data!=key){
		temp=temp->next;
	}
	temp2=temp->prev;
	temp2->next=temp->next;
	temp->next->prev=temp->prev;
	free(temp);
	printf("Node Deleted\n");
}

void reverse(){
	struct node *temp;
	temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	printf("Head<-->");
	while(temp->prev!=NULL){
		printf("%d<-->",temp->data);
		temp=temp->prev;
	}
	printf("%d<-->",temp->data);
	printf("Tail\n");
}
*/
void display()
{
	struct node *temp;
	temp=head;
	printf("Head<-->");
	while(temp!=NULL){
		printf("%d",temp->data);
		printf("<-->");
		temp=temp->next;
	}
	printf("Tail\n");
}
