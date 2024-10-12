/*
  Родионов Антон 6114-100503D
  Лабораторная работа #1
     Вариант 29
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
int x[50], y[50], count_x, count_y, product;


int main() {
    setlocale(LC_ALL, "RU");

    printf("Введите количество элементов вектора X:");
    scanf_s("%d", &count_x);
    printf("Введите элементы вектора X по одному: \n");
    for (int i = 0; i < count_x; i++) {
        printf("Введите элемент x[%d]: ", i);
        scanf_s("%d", &x[i]);
    }

    printf("\nВведите количество элементов вектора Y:");
    scanf_s("%d", &count_y);
    printf("Введите элементы вектора Y по одному: \n");
    for (int i = 0; i < count_y; i++) {
        printf("Введите элемент y[%d]: ", i);
        scanf_s("%d", &y[i]);
    }

    printf("\n\nВектор X = { ");
    for (int i = 0; i < count_x; i++) {
        printf("%d ", x[i]);
    }
    printf("} \nВектор Y = { ");
    for (int i = 0; i < count_y; i++) {
        printf("%d ", y[i]);
    }
    printf("}\n\n\n");
    
    for (int j = 0; j < count_y; j++) {
        for (int i = 0; i < count_x; i++) {
            product = x[i] * y[j];
            printf("%-3d * %-3d = %-10d", x[i], y[j], product);
        }
        printf("\n");
    }
}
