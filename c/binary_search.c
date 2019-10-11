#include <conio.h>
#include <stdio.h>
void main() {
    clrscr();
    int n, i, arr[10], search, first, last, middle;
    printf("Enter total number of elements :");
    scanf("%d", &n);
    printf("Enter %d number :", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter number to be found :");
    scanf("%d", &search);
    first = 0;
    last = n - 1;
    middle = (first + last) / 2;
    while (first <= last) {
        if (arr[middle] < search) {
            first = middle + 1;
        } else if (arr[middle] == search) {
            printf("%d found at index %d\n", search, middle);
            break;
        } else {
            last = middle - 1;
        }
        middle = (first + last) / 2;
    }
    if (first > last) {
        printf("Not found! %d is not present in the list.", search);
    }
    getch();
}
