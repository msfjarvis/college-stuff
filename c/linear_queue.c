#include "conio.h"
#include <stdio.h>
#include <stdlib.h>

#define max_size 5
int queue[max_size], front = -1, rear = -1;

void insert();
void del();
void display();

int main() {
    int choice;
    do {

        printf("\n\n--------QUEUE OPERATIONS-----------\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("-----------------------");
        printf("\nEnter your choice:\t");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            insert();
            break;
        case 2:
            del();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nInvalid choice:\n");
            break;
        }
    } while (choice != 4);
    return 0;
}
void insert() //  Inserting an element into the queue
{
    int item;
    if (rear == (max_size - 1)) {
        printf("\nQueue Overflow:");
    } else {
        printf("Enter the element to be inserted:\t");
        scanf("%d", &item);
        rear = rear + 1;
        queue[rear] = item;

        if (front == -1)
            front = 0;
    }
}

void del() //  Deleting an element from the queue
{
    int item;
    if (front == -1) {
        printf("\nQueue Underflow:");
    } else {
        item = queue[front];
        printf("\nThe deleted element: %d\t", item);
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = front + 1;
        }
    }
}
void display() //  To display the queue elements
{
    int i;
    if (front == -1) {
        printf("\nQueue is Empty:");
    } else {
        printf("\nThe queue elements are:\n");
        for (i = front; i <= rear; i++) {
            printf("%d\t", queue[i]);
        }
    }
}
