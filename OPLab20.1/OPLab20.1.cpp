#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
#define ROWS 4
#define COLS 4

void findMinElements(int matrix[ROWS][COLS], int minElements[COLS], int minElementAddresses[COLS][2]) {
    for (int j = 0; j < COLS; ++j) {
        int minElement = matrix[0][j];
        int minElementRow = 0;

        for (int i = 1; i < ROWS; ++i) {
            if (matrix[i][j] < minElement) {
                minElement = matrix[i][j];
                minElementRow = i;
            }
        }

        minElements[j] = minElement;
        minElementAddresses[j][0] = minElementRow;
        minElementAddresses[j][1] = j;
    }
}

int main() {
    int matrix[ROWS][COLS] = {
        {5, 12, 7, 9},
        {8, 15, 6, 11},
        {10, 4, 3, 14},
        {2, 1, 13, 16}
    };

    int minElements[COLS];
    int minElementAddresses[COLS][2];

    findMinElements(matrix, minElements, minElementAddresses);

    printf("Мінімальні елементи та їх адреси:\n");
    for (int j = 0; j < COLS; ++j) {
        printf("Стовпець %d: Мінімальний елемент: %d, Адреса: [%p]\n", j + 1, minElements[j], &matrix[minElementAddresses[j][0]][minElementAddresses[j][1]]);
    }

    return 0;
}