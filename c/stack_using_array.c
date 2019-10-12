#include <stdio.h>
#define MAX 10

/*typedef keyword creates a type definition that simplifies code and makes a
program easier to read. here stack is implemented using structure as it avoid
declaring multiple arrays and their tops when multiple structures are needed.
here name of the structure is "stack".*/

typedef struct {
    int a[MAX];
    int top;
} stack;

void push(stack *s, int ele) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->top++;
    s->a[s->top] = ele;
}

int isempty(stack *s) {
    if (s->top == -1)
        return -1;
    return 0;
}

int pop(stack *s) {
    int x;
    if (isempty(s))
        return -1;
    x = s->a[s->top];
    s->top--;
    return x;
}

int stacktop(stack *s) {
    if (isempty(s))
        return -1;
    return s->a[s->top];
}

void display(stack *s) {
    int i;
    if (isempty(s)) {
        printf("Stack Underflow\n");
        return;
    }
    for (i = s->top; i >= 0; i--)
        printf("%d\n", s->a[i]);
}

int main() {
    stack s1; // No need to use struct keyword because typedef is used.
    int ch, ele;
    s1.top = -1;

    while (1) {
        printf("Menu\n1.Push\n2.Pop\n3.Stacktop\n4.Display\n5.Exit\n");
        printf("Enter Choice : ");
        scanf("%d", &ch);
        if (ch == 5)
            break;

        switch (ch) {
        case 1:
            printf("Enter Element : ");
            scanf("%d", &ele);
            push(&s1, ele); // passing the stack address as an argument to the
                            // push function
            break;

        case 2:
            ele = pop(&s1);
            if (ele == -1)
                printf("Stack Underflow\n");
            else
                printf("Popped element = %d\n", ele);
            break;

        case 3:
            ele = stacktop(&s1);
            if (ele == -1)
                printf("Stack Underflow\n");
            else
                printf("Top of stack = %d \n", ele);
            break;
        case 4:
            display(&s1);
            break;

        default:
            printf("Invalid choice \n");
            break;
        }
    }
    return 0;
}
