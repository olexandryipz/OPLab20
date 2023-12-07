#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void mergeArrays(int x[], int y[], int a, int b, int merged[], int* mergedSize) {
    int i, j, k;

    for (i = 0; i < a; i++) {
        merged[i] = x[i];
    }
    *mergedSize = a;

    for (j = 0; j < b; j++) {
        int isUnique = 1;
        for (i = 0; i < a; i++) {
            if (y[j] == x[i]) {
                isUnique = 0;
                break;
            }
        }
        if (isUnique) {
            merged[*mergedSize] = y[j];
            (*mergedSize)++;
        }
    }
}

void findCommonElements(int x[], int y[], int a, int b, int common[], int* commonSize) {
    *commonSize = 0;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (x[i] == y[j]) {
                common[*commonSize] = x[i];
                (*commonSize)++;
            }
        }
    }
}

int main() {
    int a, b;
    printf("Введіть розмір масиву x: ");
    scanf_s("%d", &a);
    printf("Введіть розмір масиву y: ");
    scanf_s("%d", &b);

    int* x = (int*)malloc(a * sizeof(int));
    int* y = (int*)malloc(b * sizeof(int));

    printf("Введіть елементи масиву x:\n");
    for (int i = 0; i < a; i++) {
        printf("x[%d]: ", i);
        scanf_s("%d", &x[i]);
    }

    printf("Введіть елементи масиву y:\n");
    for (int i = 0; i < b; i++) {
        printf("y[%d]: ", i);
        scanf_s("%d", &y[i]);
    }

    int* merged = (int*)malloc((a + b) * sizeof(int));
    int* common = (int*)malloc((a < b ? a : b) * sizeof(int));

    int mergedSize, commonSize;

    mergeArrays(x, y, a, b, merged, &mergedSize);

    findCommonElements(x, y, a, b, common, &commonSize);

    printf("\nЕлементи обох масивів:\n");
    for (int i = 0; i < mergedSize; i++) {
        printf("%d ", merged[i]);
    }

    printf("\nСпільні елементи:\n");
    for (int i = 0; i < commonSize; i++) {
        printf("%d ", common[i]);
    }
    free(x);
    free(y);
    free(merged);
    free(common);

    return 0;
}
