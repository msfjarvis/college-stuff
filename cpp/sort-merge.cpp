/*
    Program To Merge And Sort Two Arrays
*/

#include "conio.h"
#include <iostream>

using namespace std;

int *sortArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                arr[i] = arr[i] + arr[j];
                arr[j] = arr[i] - arr[j];
                arr[i] = arr[i] - arr[j];
            }
        }
    }
    return arr;
}

int main() {
    int size1, size2, a[30], b[30];
    cout << "Enter Size For Array 1 : ";
    cin >> size1;
    cout << "Enter Element Of Array 1 : " << endl;
    for (int i = 0; i < size1; i++) {
        cout << "Array1[" << i << "] : ";
        cin >> a[i];
    }
    cout << "Enter Size For Array 2 : ";
    cin >> size2;
    cout << "Enter Element Of Array 2 : " << endl;
    for (int i = 0; i < size2; i++) {
        cout << "Array2[" << i << "] : ";
        cin >> b[i];
    }
    // Merge array
    for (int i = size1, k = 0; i < size1 + size2 && k < size2; i++, k++) {
        a[i] = b[k];
    }
    int *c = sortArray(a, size1 + size2);
    cout << "Merged And Sorted Array : " << endl;
    for (int j = 0; j < size1 + size2; j++) {
        cout << c[j] << " ";
    }
}