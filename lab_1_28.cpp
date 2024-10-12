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
#define k 100

int vector_A[m] = { 0 }, vector_B[n] = { 0 }, L, LAB, result[k];

int main() {
    setlocale(LC_ALL, "RU");
    printf("Введите количество элементов в векторах A и B: ");
    scanf("%d", &L);

    LAB = L + L;

    printf("\nВведите элементы вектора A:\n");
    for (int i = 0; i < L; i++) {
        printf("Введите элемент [%d]: ", i + 1);
        scanf("%d", &vector_A[i]);
    }
    printf("\nВведите элементы вектора B:\n");
    for (int i = 0; i < L; i++) {
        printf("Введите элемент [%d]: ", i + 1);
        scanf("%d", &vector_B[i]);
    }

    printf("\nvector A = { ");
    for (int i = 0; i < L; i++) {
        printf("%d ", vector_A[i]);
    }
    printf("} \n");
    printf("vector B = { ");
    for (int i = 0; i < L; i++) {
        printf("%d ", vector_B[i]);
    }
    printf("} \n\n");

    

    for (int i = 0, o = 0; i < L; i++) {
        if (vector_A[i] < vector_B[i]) {
            result[o] = vector_B[i];
            result[o + 1] = vector_A[i];
            o += 2;
        }
        else {
            result[o] = vector_A[i];
            result[o + 1] = vector_B[i];
            o += 2;
        }
    }

    

    // Печать результата
    printf("result = { ");
    for (int i = 0; i < LAB; i++) {
        printf("%d ", result[i]);
    }
    printf("}");
    return 0;
}
