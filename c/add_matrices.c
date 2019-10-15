// Addition of two matrix in C
#include <stdio.h>

#define M 10
#define N 10

void add_matrices(int m1[M][N], int m2[M][N], int res[M][N]);

int main() {
    int first[M][N], second[M][N], sum[M][N], idx = 0;

    printf("Enter the elements of first matrix\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            first[i][j] = idx;
            idx++;
        }
    }

    printf("Enter the elements of second matrix\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            second[i][j] = idx;
            idx++;
        }
    }

    add_matrices(first, second, sum);

    printf("Sum of entered matrices:-\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("sum[%d][%d] = %d\n", i, j, sum[i][j]);
        }
    }

    return 0;
}

void add_matrices(int m1[M][N], int m2[M][N], int res[M][N]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            res[i][j] = m1[i][j] + m2[i][j];
        }
    }
}
