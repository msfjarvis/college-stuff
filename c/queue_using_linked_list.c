#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct {
    node *start;
} LL;

// insertEnd() of Singly LL
void Enqueue(LL *l, int ele) {
    node *newnode, *p;
    newnode = (node *)malloc(sizeof(node));
    newnode->data = ele;
    newnode->next = NULL;

    if (l->start == NULL)
        l->start = newnode;
    else {
        p = l->start;
        while (p->next != NULL)
            p = p->next;
        p->next = newnode;
    }
}

// display() of Singly LL
void display(LL *l) {
    node *p;
    if (l->start == NULL) {
        printf("Queue is empty\n");
        return;
    }
    p = l->start;

    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// deleteBeginning() of Singly LL
int Dequeue(LL *l) {
    // p must refer to node to delete
    node *p;
    if (l->start == NULL) {
        return -1;
    }
    p = l->start;
    l->start = l->start->next;
    return p->data;
}

int Queuefront(LL *l) {
    if (l->start == NULL)
        return -1;
    else
        return l->start->data;
}

int main() {
    int ch, ele;
    LL l;
    l.start = NULL;
    while (1) {
        printf("1: Enqueue\n2: Dequeue\n3: Queue Front\n4: Display\n5: Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        if (ch == 5)
            break;
        switch (ch) {
        case 1:
            printf("Enter element to enque: ");
            scanf("%d", &ele);
            Enqueue(&l, ele);
            printf("Updated queue\n");
            display(&l);
            break;
        case 2:
            ele = Dequeue(&l);
            if (ele == -1)
                printf("Queue underflow\n");
            else
                printf("Element dequeued = %d\n", ele);
            printf("Updated queue\n");
            display(&l);
            break;
        case 3:
            ele = Queuefront(&l);
            if (ele == -1)
                printf("Queue underflow\n");
            else
                printf("Queue front element = %d\n", ele);
            break;
        case 4:
            display(&l);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}
