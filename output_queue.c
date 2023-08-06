/*Output restricted double ended queue*/

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

void insertRear(int x) {
  if (rear == MAX - 1) {
    printf("Overflow.");
  } 
  else if (front == rear && front == -1) {
    front = 0;
    rear = 0;
    queue[rear] = x;
  }
  else {
    rear++;
    queue[rear] = x;
  }
  printf("\n");
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

int main() {
  int x, choice;
  printf("Output restricted double ended queue\n");
  while (1) {
    printf("1. Insert front\n2. Insert rear\n3. Delete rear\n4. Print\n5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Enter the element to insert: ");
        scanf("%d", &x);
        insertFront(x);
        break;
      case 2:
        printf("Enter the element to insert: ");
        scanf("%d", &x);
        insertRear(x);
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
        return 0;
      default:
        printf("Invalid choice\n");
    }
  }
  return 0;
}
