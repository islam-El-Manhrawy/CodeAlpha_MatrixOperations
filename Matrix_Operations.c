#include <stdio.h>
#include <stdlib.h>

void readMatrix(int matrix[10][10], int rows, int cols, char name) {
    printf("\n--- Enter elements for Matrix %c ---\n", name);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Matrix %c [%d][%d]: ", name, i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int A[10][10], int B[10][10], int C[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void transposeMatrix(int A[10][10], int T[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            T[j][i] = A[i][j];
        }
    }
}

void multiplyMatrices(int A[10][10], int B[10][10], int C[10][10], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
        }
    }
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[10][10], B[10][10], C[10][10];
    int rows, cols;
    int choice = 1; 

    while (choice != 0) {
        system("cls"); 
        
        printf("=== Matrix Operations Program ===\n");
        printf("Enter Number Of Rows & Cols (Size Of Matrix [a * b]) : ");
        if (scanf("%d %d", &rows, &cols) != 2) {
            break;
        }

        readMatrix(A, rows, cols, 'A');
        readMatrix(B, rows, cols, 'B');

        printf("\n=================================");
        printf("\n=== Result of Addition (A + B) down below ===\n");
        addMatrices(A, B, C, rows, cols);
        printMatrix(C, rows, cols);

        printf("\n=================================");
        printf("\n=== Transpose of Matrix A (A') down below ===\n");
        transposeMatrix(A, C, rows, cols);
        printMatrix(C, cols, rows);

        printf("\n=================================");
        printf("\n=== Transpose of Matrix B (B') down below ===\n");
        transposeMatrix(B, C, rows, cols);
        printMatrix(C, cols, rows);

        printf("\n=================================");
        printf("\n=== Result of Multiplication (A * B) down below ===\n");
        multiplyMatrices(A, B, C, rows, cols, cols);
        printMatrix(C, rows, cols);

        printf("\n=================================\n");
        printf("Operations finished for these matrices.\n");
        printf("To continue with new matrices operations press 1 and Enter to Exit press 0 and Enter :");
        scanf("%d", &choice);
    }

    printf("\n-- Thank you for using my program -- Have a nice day --\n");
    system("pause");
    return 0;
}