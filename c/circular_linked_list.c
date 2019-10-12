#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct {
    node *last;
} LL;

void insertBeginning(LL *l, int ele) {
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->data = ele;
    if (l->last == NULL) {
        newnode->next = newnode;
        l->last = newnode;
    } else {
        newnode->next = l->last->next;
        l->last->next = newnode;
    }
}

void insertEnd(LL *l, int ele) {
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->data = ele;

    if (l->last == NULL) {
        newnode->next = newnode;
        l->last = newnode;

    } else {
        newnode->next = l->last->next;
        l->last->next = newnode;
        l->last = newnode;
    }
}

int deleteBeginning(LL *l) {
    node *p;
    if (l->last == NULL)
        return -1;
    p = l->last->next;
    if (p->next == p)
        l->last = NULL;
    else
        l->last->next = p->next;
    return p->data;
}

int deleteEnd(LL *l) {
    node *p, *q;
    if (l->last == NULL)
        return -1;
    p = l->last;
    if (p->next == p)
        l->last = NULL;
    else {
        q = l->last->next;
        while (q->next != l->last)
            q = q->next;
        q->next = p->next;
        l->last = q;
    }
    return p->data;
}

void display(LL *l) {
    node *p;
    if (l->last == NULL) {
        printf("Linked List is empty\n");
        return;
    }
    p = l->last->next;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != l->last->next);
    printf("\n");
}

int main() {
    LL l1;
    int ch, ele;
    l1.last = NULL;
    while (1) {
        printf("1: InsertBeginning\n2: InsertEnd\n3: DeleteBeginning\n4: "
               "DeleteEnd\n");
        printf("5: Display\n6: Exit\n");
        printf("Enter choice\n");
        scanf("%d", &ch);
        if (ch == 6)
            break;
        switch (ch) {
        case 1:
            printf("Enter element to insert at Beginning\n");
            scanf("%d", &ele);
            insertBeginning(&l1, ele);
            printf("\nUpdated list\n");
            display(&l1);
            break;
        case 2:
            printf("Enter element to insert at End\n");
            scanf("%d", &ele);
            insertEnd(&l1, ele);
            printf("\nUpdated list\n");
            display(&l1);
            break;
        case 3:
            ele = deleteBeginning(&l1);
            if (ele == -1)
                printf("Linked List is empty");
            else
                printf("Element deleted from beginning = %d\n", ele);
            printf("\nUpdated list\n");
            display(&l1);
            break;
        case 4:
            ele = deleteEnd(&l1);
            if (ele == -1)
                printf("Linked List is empty");
            else
                printf("Element deleted from from End = %d\n", ele);
            printf("\nUpdated list\n");
            display(&l1);
            break;
        case 5:
            display(&l1);
            break;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
