#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct {
    node *start;
} LL;

void push(LL *l, int ele) // insertBeginning() of Singly LL
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->data = ele;
    newnode->next = l->start;
    l->start = newnode;
}

void display(LL *l) // display of Singly LL
{
    node *p;
    if (l->start == NULL) {
        printf("Stack is empty\n");
        return;
    }
    p = l->start;

    while (p != NULL) {
        printf("%d\n", p->data);
        p = p->next;
    }
    printf("\n");
}

int pop(LL *l) // deleteBeginning() of Singly LL
{
    // p must refer to node to delete
    node *p;
    if (l->start == NULL) {
        return -1;
    }
    p = l->start;
    l->start = l->start->next;
    return p->data;
}

int stacktop(LL *l) {
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
        printf("1: Push\n2: Pop\n3: Stacktop\n4: Display\n5: Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        if (ch == 5)
            break;
        switch (ch) {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &ele);
            push(&l, ele);
            printf("Updated stack\n");
            display(&l);
            break;
        case 2:
            ele = pop(&l);
            if (ele == -1)
                printf("Stack underflow\n");
            else
                printf("Element popped = %d\n", ele);
            printf("Updated stack\n");
            display(&l);
            break;
        case 3:
            ele = stacktop(&l);
            if (ele == -1)
                printf("Stack underflow\n");
            else
                printf("Stack top element = %d\n", ele);
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
