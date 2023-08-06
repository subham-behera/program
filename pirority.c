#include<stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int rear = -1;
int front = -1;

void enqueue() {
    int a;
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full.\n");
        return;
    }
    printf("Enter Value:");
    scanf("%d",&a);

    if (front == -1) {
        front = 0;
    }

    int i;
    for (i = rear; i >= front; i--) {
        if (a > queue[i]) {
            queue[i + 1] = queue[i];
        } else {
            break;
        }
    }

    queue[i + 1] = a;
    rear++;
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Deleted item: %d\n", queue[front]);

    front++;
}

void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main(){
	int ch;
	while(1){
		printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		printf("Enter the operation:");
		scanf("%d",&ch);
		switch(ch){
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