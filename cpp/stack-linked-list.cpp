/* Program to implement stacks as linked lists */

#include "conio.h"
#include <iostream>
#include <process.h>

using namespace std;

struct node {
    int roll;
    node *next;
} * top, *save, *ptr, *newptr, *np;

node *create(int a) {
    ptr = new node;
    ptr->roll = a;
    ptr->next = NULL;
    return ptr;
}

void push(node *np) {
    if (top == NULL) {
        top = np;
    } else {
        save = top;
        top = np;
        np->next = save;
    }
}

void pop() {
    if (top == NULL) {
        cout << "Underflow";
    } else {
        ptr = top;
        top = top->next;
        delete ptr;
    }
}

void display(node *np) {
    while (np != NULL) {
        cout << np->roll << "->";
        np = np->next;
    }
}

int main() {
    top = NULL;
    int m, n;
    char k, ch;
    do {
        cout << "\nChoose from the menu: ";
        cout << "\n 1. Push";
        cout << "\n 2. Pop";
        cout << "\n 3. Display";
        cout << "\n 4. Quit";
        cout << endl << "Enter your choice (1..4): ";
        cin >> n;
        switch (n) {
        case 1:
            k = 'y';
            while (k == 'y' || k == 'Y') {
                cout << "Enter element to be inserted: ";
                cin >> m;
                newptr = create(m);
                if (newptr == NULL) {
                    cout << "\n Cannot create!!";
                } else
                    push(newptr);
                cout << "\n The stack formed is: ";
                display(top);
                cout << "\n Want to enter again ? ";
                cin >> k;
            }
            break;
        case 2:
            k = 'y';
            while (k == 'y' || k == 'Y') {
                pop();
                cout << "\n The stack formed is: ";
                display(top);
                cout << "\n Want to delete again ? ";
                cin >> k;
            }
            break;
        case 3:
            cout << "\n The stack formed is: ";
            display(top);
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "\n Please enter desired keyword: ";
        }
        cout << "\n Do you want to continue ? ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    getch();
    return 0;
}
