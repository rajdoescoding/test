#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int isEmpty(struct Queue* queue);
int isFull(struct Queue* queue);
void insert(struct Queue* queue, int item);
int del(struct Queue* queue);
void display(struct Queue* queue);
struct Queue {
int front, rear, size;
int arr[MAX_SIZE];
};
struct Queue* createQueue() {
struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
queue->front = queue->rear = -1;
queue->size = 0;
return queue;
}
int main() {
struct Queue* queue = NULL;
int choice, item;
do {
printf("1. Create Queue\n");
printf("2. Insert an element\n");
printf("3. Delan element\n");
printf("4. Display\n");
printf("5. Exit\n");
printf("\nEnter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
if (queue != NULL) {
printf("Queue already exists. Deleting the old queue.\n");
free(queue);
}
queue = createQueue();
printf("Queue created.\n");
break;
case 2:
if (queue == NULL) {
printf("Queue does not exist. Create a queue first.\n");
} else {
printf("Enter the element to insert: ");
scanf("%d", &item);
insert(queue, item);
}
break;
case 3:
if (queue == NULL) {
printf("Queue does not exist. Create a queue first.\n");
} else {
item = del(queue);
printf("deleted item: %d\n", item);
}
break;
case 4:
if (queue == NULL) {
printf("Queue does not exist. Create a queue first.\n");
} else {
display(queue);
}
break;
case 5:
if (queue != NULL) {
free(queue);
}
printf("Exiting the program.\n");
break;
default:
printf("Invalid choice. Please enter a valid option.\n");
}
} while (choice != 5);
return 0;
}
int isEmpty(struct Queue* queue) {
return (queue->size == 0);
}
int isFull(struct Queue* queue) {
return (queue->size == MAX_SIZE);
}
// insert
void insert(struct Queue* queue, int item) {
if (queue->front == -1)
queue->front = 0;
queue->rear = (queue->rear + 1) % MAX_SIZE;
queue->arr[queue->rear] = item;
queue->size++;
printf("%d insertd to the queue.\n", item);
}
// del
int del(struct Queue* queue) {
int item = queue->arr[queue->front];
if (queue->front == queue->rear) {
queue->front = queue->rear = -1;
} else {
queue->front = (queue->front + 1) % MAX_SIZE;
}
queue->size--;
return item;
}
void display(struct Queue* queue) {
if (isEmpty(queue)) {
printf("Queue is empty.\n");
return;
}
printf("Queue elements: ");
int i;
for (i = queue->front; i != queue->rear; i = (i + 1) % MAX_SIZE) {
printf("%d ", queue->arr[i]);
}
printf("%d\n", queue->arr[i]);
}