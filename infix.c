#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define max 100

void int_to_post(char *);
void push(char);
char pop();
int precedence(char);
int isfull();
int isempty();

static int top=-1;
int stack[max];
char infix[max];
char poxt[max];

int main(){
	printf("Enter the infix expression:");
	scanf("%s",infix);
	int_to_post(infix);
	printf("\n");
}

void int_to_post(char *infix){
	int i,p,q;
	char symbol,next;
	int j=0;
	for(i=0;i<strlen(infix);i++){
		symbol=infix[i];
		switch(symbol){
			case '(':
				push(symbol);
				break;
			case ')':
				while(next=pop()!='(')
					poxt[j++]=next;
				break;
			case '^':
			case '+':
			case '-':
			case '*':
			case '/':
				while(!isempty() && (precedence(stack[top])>=precedence(symbol)))
					poxt[j++]=pop();
					push(symbol);
					break;
			default:
				poxt[j++]=symbol;
		}
	}
	while(!isempty())
		poxt[j++]=pop();
		poxt[j]='\0';
		printf("%s",poxt);
}

int precedence(char symbol){
	switch(symbol){
		case '^':
			return 3;
		case '/':
		case '*':
			return 2;
		case '+':
		case '-':
			return 1;
		default:
			return 0;
	}
}

int isfull(){
	return top == max-1;
}

int isempty(){
	return top==-1;
}

void push(char op){
	if(isfull()){
		printf("Stack is Full.\n");
	}
	else{
		top+=1;
		stack[top]=op;
	}
}

char pop(){
	char ch;
	if(isempty()){
		return -1;
	}
	else{
		ch=stack[top];
		top-=1;
		return (ch);
	}
}
