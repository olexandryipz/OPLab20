#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void deleteRow(int*** matrix, int* rows, int cols, int rowToDelete) {
    if (*rows <= 1 || rowToDelete < 0 || rowToDelete >= *rows) {
        return;
    }
    free((*matrix)[rowToDelete]);

    for (int i = rowToDelete; i < *rows - 1; ++i) {
        (*matrix)[i] = (*matrix)[i + 1];
    }

    --(*rows);

    int** temp = (int**)realloc(*matrix, (*rows) * sizeof(int*));
    if (temp != NULL) {
        *matrix = temp;
    }
}

int main() {
    int rows, cols;

    printf("Введіть кількість рядків: ");
    scanf_s("%d", &rows);
    printf("Введіть кількість стовпців: ");
    scanf_s("%d", &cols);

    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; ++i) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    printf("Введіть елементи матриці:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("Елемент [%d][%d]: ", i, j);
            scanf_s("%d", &matrix[i][j]);
        }
    }

    int minRow = 0;
    for (int i = 1; i < rows; ++i) {
        if (matrix[i][0] < matrix[minRow][0]) {
            minRow = i;
        }
    }

    deleteRow(&matrix, &rows, cols, minRow - 1);
    deleteRow(&matrix, &rows, cols, minRow);

    printf("Матриця після видалення рядків:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; ++i) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
