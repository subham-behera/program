#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
}*start=NULL;

void insert_begin();
void insert_end();
void insert_loc();
void delete_begin();
void delete_end();
void delete_loc();
void sorting();
void search();
void print();

int main(){
	int op;
	while(1){
		printf("1.Insert at beginning\n2.Insert at end\n3.Insert at location\n4.Delete from beginning\n5.Delete from end\n6.Delete from location\n7.Print\n8.Sorting\n9.search\n10.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&op);
		switch(op){
			case 1:
				insert_begin();
				break;
			case 2:
				insert_end();
				break;
			case 3:
				insert_loc();
				break;
			case 4:
				delete_begin();
				break;
			case 5:
				delete_end();
				break;
			case 6:
				delete_loc();
				break;
			case 7:
				print();
				break;
			case 8:
				sorting();
				break;
			case 9:
				search();
				break;
			deafult:
				exit(0);
		}
	}
	return 0;
}

void insert_begin(){
	struct node *p;
	int value;
	p=(struct node *)malloc(sizeof(struct node));
	if(p==NULL){
		printf("No memory Allocation.\n");
		return ;
	}
	else{
		printf("Enter the value:");
		scanf("%d",&value);
		p->data=value;
		p->next=start;
		start=p;
	}
}

void insert_end(){
	struct node *p,*temp;
	int value;
	p=(struct node *)malloc(sizeof(struct node));
	if(p==NULL){
		printf("Overflow.\n");
		return ;
	}
	else{
		printf("Enter value:");
		scanf("%d",&value);
		p->data=value;
		if(start==NULL){
			p->next=NULL;
			start=p;
		}
		else{
			temp=start;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=p;
			p->next=NULL;
		}
	}
}

void insert_loc(){
	int i,loc,value;
	struct node *p,*temp;
	p=(struct node *)malloc(sizeof(struct node));
	if(p==NULL){
		printf("Overflow\n");
		return ;
	}
	else{
		printf("Enter Value:");
		scanf("%d",&value);
		p->data=value;
		printf("Enter the location after which you wish to insert:");
		scanf("%d",&loc);
		temp=start;
		for(i=1;i<loc;i++){
			temp=temp->next;
			if(temp==NULL){
				printf("Cannot Insert.\n");
				return ;
			}
		}
		p->next=temp->next;
		temp->next=p;
	}
}

void delete_begin(){
	struct node *p;
	if(start==NULL){
		printf("List is empty.\n");
		return ;
	}
	else{
		p=start;
		start=p->next;
		free(p);
	}
}

void delete_end(){
	struct node *p,*p1;
	if(start==NULL){
		printf("List is empty.\n");
		return ;
	}
	else if(start->next==NULL){
		start=NULL;
		free(start);
		printf("Node Deleted.\n");
	}
	else{
		p=start;
		while(p->next!=NULL){
			p1=p;
			p=p->next;
		}
		p1->next=NULL;
		free(p);
	}
}	

void delete_loc(){
	struct node *p,*p1;
	int loc,i;
	printf("Enter the location to delete:");
	scanf("%d",&loc);
	p=start;
	for(i=1;i<=loc;i++){
		p1=p;
		p=p->next;
		if(p==NULL){
			printf("Can't Delete.\n");
			return ;
		}
	}
	p1->next=p->next;
	free(p);
	printf("Deleted Node %d\n",loc+1);
}

void print(){
	struct node *p;
	p=start;
	if(p==NULL){
		printf("No element.");
		return ;
	}
	else{
		printf("\nPrinting Values:\nHead ");
		while(p!=NULL){
			printf("%d-->",p->data);
			p=p->next;
		}
		printf(" Tail\n\n");
	}
}

void search(){
	struct node *p;
	int temp=-1,key,i=0;
	printf("Enter the key:");
	scanf("%d",&key);
	p=start;
	if(p==NULL){
		printf("No element.");
		return ;
	}
	else{
		while(p!=NULL){
			i+=1;
			if(p->data==key){
				printf("Index is %d\n",i);
				printf("Address %p",p->next);
				temp=0;
			}
			p=p->next;
		}
		if(temp==-1){
			printf("Sorry Key not found.");
		}
	}
	printf("\n");
}

void sorting(){
	struct node *ptr,*cptr;
	int temp;
	ptr=start;
	while(ptr->next!=NULL){
		cptr=ptr->next;
		while(cptr!=NULL){
			if(ptr->data>cptr->data){
				temp=ptr->data;
				ptr->data=cptr->data;
				cptr->data=temp;
			}
			cptr=cptr->next;
		}
		ptr=ptr->next;
	}
}
