/*
    Linear Representation Of Sparse Matrix
*/
#include "conio.h"
#include <iostream>
#define ROWS 20
#define COLS 20

using namespace std;

int main() {
    int row, col, k = 0, counter = 0;
    int matrix[ROWS][COLS];
    cout << "Enter Size Of Rows And Colums : ";
    cin >> row >> col;
    cout << "Enter Matrix Elements : \n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] != 0)
                counter++;
        }
    }
    if (counter <= (row * col) / 2) {
        cout << "Given Matrix Is Not Sparse!!";
        sleep(1);
        exit(0);
    }
    int denseMatrix[2][counter];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] != 0) {
                denseMatrix[0][k] = i;
                denseMatrix[1][k] = j;
                denseMatrix[2][k] = matrix[i][j];
                k++;
            }
        }
    }
    cout << "Linear Representation Of Sparse Matrix : \n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < k; j++) {
            cout << denseMatrix[i][j] << " ";
        }
        cout << endl;
    }
    getch();
    return 0;
}