// String comparison C program
#include <stdio.h>

#define MAX_LEN 1000

int compare_strings(char[], char[]);

int main() {
    char a[MAX_LEN], b[MAX_LEN];

    printf("Input a string\n");
    fgets(a, MAX_LEN, stdin);

    printf("Input a string\n");
    fgets(b, MAX_LEN, stdin);

    if (compare_strings(a, b) == 0)
        printf("Equal strings.\n");
    else
        printf("Unequal strings.\n");

    return 0;
}

int compare_strings(char a[], char b[]) {
    int c = 0;

    while (a[c] == b[c]) {
        if (a[c] == '\0' || b[c] == '\0')
            break;
        c++;
    }

    if (a[c] == '\0' && b[c] == '\0')
        return 0;
    else
        return -1;
}
