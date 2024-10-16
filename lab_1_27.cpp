/*
  Родионов Антон 6114-100503D
    Лабораторная работа #1
         Вариант 27
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#define m 100
#define n 50
#define k 50


int chr[m][n] = { 0 }, result[k];
int width, height, aboba, abobam;


int main() {
    setlocale(LC_ALL, "RU");
    while (true) {
        printf("Введите количество строк: ");
        scanf("%d", &height); 
        if (height > 0 && height <= m) { 
            break; 
        }
       
    }
    while (true) {
        printf("Введите количество столбцов: ");
        scanf("%d", &width); 
        if (width > 0 && width <= n) { 
            break;
        }
        
        }

        printf("строк = %d, столбцов = %d \n\n", height, width);

        // Ввод элементов матрицы
        printf("Введите элементы матрицы A:\n");
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                printf("Элемент A[%d][%d]: ", i + 1, j + 1);
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
        // Обработка матрицы
        for (int i = 0; i < height; i++) {
            int max = -10000;
            int min = 10000;
            for (int j = 0; j < width; j++) {
                if (chr[i][j] > max) {
                    max = chr[i][j];
                    aboba = chr[i][j];
                }
                if (chr[i][j] < min) {
                    min = chr[i][j];
                    abobam = chr[i][j];
                }
            }
            result[i] = aboba + abobam;
        }

        // Вывод результата
        printf("\nresult = ");
        for (int i = 0; i < height; i++) {
            printf("%d ", result[i]);
        }
    }
