#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

#define max 20

void push(int);
int pop();
int isfull();
int isempty();

static int top=-1;
int stack[max];
char postfix[max];

int main(){
	int i,a,b,result,peval;
	char ch;
	printf("Enter the postfix operation:");
	scanf("%s",postfix);
	for(i=0;postfix[i]!='\0';i++){
		ch=postfix[i];
		if(isdigit(ch)){
			push(ch-'0');
		}
		else if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
			b=pop();
			a=pop();
			switch(ch){
				case '+':
					result=a+b;
					break;
				case '-':
					result=a-b;
					break;
				case '*':
					result=a*b;
					break;
				case '/':
					result=a/b;
					break;
			}
			push(result);
		}
	}
	peval=pop();
	printf("Postfix expression value is:%d\n",peval);
	return 0;
}
/*
int isfull(){
	if(top==max-1){
		return 1;
	}
	else{
		return 0;
	}
}

int isempty(){
	if(top==-1){
		return 1;
	}
	else{
		return 0;
	}
}
*/
void push(int a){
	if(top==max-1){
		printf("Stack is Full.\n");
	}
	else{
		top+=1;
		stack[top]=a;
	}
}

int pop(){
	if(top==-1){
		printf("Stack is empty.\n");
		return 0;
	}
	else{
		top-=1;
		return stack[top+1];
	}
}
