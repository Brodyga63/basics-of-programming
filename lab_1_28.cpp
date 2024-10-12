/*
  Родионов Антон 6114-100503D
  Лабораторная работа #1
     Вариант 28
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#define m 50
#define n 50
#define k 50


int chr[m][n] = { 0 }, result[k];
int width, height;


int main() {
    setlocale(LC_ALL, "RU");
    printf("Введите количество строк: ");
    scanf("%d", &height);
    printf("Введите количество столбцов: ");
    scanf("%d", &width);

    printf("строк = %d, столбцов = %d \n\n", height, width);

    // Ввод элементов матрицы
    printf("Введите элементы матрицы A:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("Элемент [%d][%d]: ", i, j);
            scanf_s("%d", &chr[i][j]);
        }
    }
    printf("\n");
    // Вывод матрицы в двухмерном виде
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%4d", chr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < height; i++) {
        int max = -10000;
        for (int j = 0; j < width; j++) {
            if (chr[i][j] > max) {
                max = chr[i][j];
            }
        }
        result[i] = max;
    }

    printf("\nresult = {");
    for (int i = 0; i < height; i++) {
        printf(" %d", result[i]);
        ;
        }
    printf(" }");
}
