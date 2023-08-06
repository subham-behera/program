/*Input restricted double ended queue*/

#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void insertFront(int x) {
  if (front<1) {
    printf("Not Possible");
  }
  else if (front == rear && front>0) {
    front-=1;
    queue[front] = x;
  }
  else {
    front--;
    queue[front] = x;
  }
  printf("\n");
}

int deleteFront() {
  int x;
  if (front == -1) {
    printf("Queue is empty\n");
    return -1;
  } else if (front == rear) {
    x = queue[front];
    front = -1;
    rear = -1;
    return x;
  } else {
    x = queue[front];
    front++;
    return x;
  }
}

int deleteRear() {
  int x;
  if (front == -1) {
    printf("Queue is empty\n");
    return -1;
  } else if (front == rear) {
    x = queue[front];
    front = -1;
    rear = -1;
    return x;
  } else {
    x = queue[rear];
    rear--;
    return x;
  }
}

void printQueue() {
  int i;
  if (front == -1) {
    printf("Queue is empty\n");
  } else {
    for (i = front; i <= rear; i++) {
      printf("%d ", queue[i]);
    }
    printf("\n");
  }
}

void create(){
  if(rear==MAX-1){
    printf("Not possible\n");
  }
  else if(front==-1){
    int a;
    printf("Enter Element:");
    scanf("%d",&a);
    front=rear=0;
    queue[front]=a;
  }
  else{
    int a;
    printf("Enter Element:");
    scanf("%d",&a);
    rear++;
    queue[rear]=a;
  }
}


int main() {
  int x, choice;
  printf("Input restricted double ended queue\n");
  while (1) {
    printf("1. Insert front\n2. Delete front\n3. Delete rear\n4. Print\n5. Create\n6.Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Enter the element to insert: ");
        scanf("%d", &x);
        insertFront(x);
        break;
      case 2:
        x = deleteFront();
        if (x != -1) {
          printf("Element deleted from front is %d\n", x);
        }
        break;
      case 3:
        x = deleteRear();
        if (x != -1) {
          printf("Element deleted from rear is %d\n", x);
        }
        break;
      case 4:
        printQueue();
        break;
      case 5:
        create();
        break;
      default:
        printf("Invalid choice\n");
        exit(0);
    }
  }
  return 0;
}

