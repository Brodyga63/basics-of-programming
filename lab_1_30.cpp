/*
  Родионов Антон 6114-100503D
    Лабораторная работа #1
       Вариант 30
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#define m 50
#define n 50
#define k 100

int vector_A[m] = { 0 }, vector_B[n], L, LAB, result[k] = { 0 };

int main() {
    setlocale(LC_ALL, "RU");
    printf("Введите количество элементов векторов A и B: ");
    scanf("%d", &L);


    LAB = L + L;

    printf("Введите элементы вектора A: \n");
    for (int i = 0; i < L; i++) {
        scanf("%d", &vector_A[i]);
    }
    printf("Введите элементы вектора B: \n");
    for (int i = 0; i < L; i++) {
        scanf("%d", &vector_B[i]);
    }
    printf("\n");
    for (int i = 0; i < L; i++) {
        printf("%d ", vector_A[i]);
    }
    printf("\n");
    for (int i = 0; i < L; i++) {
        printf("%d ", vector_B[i]);
    }
    printf("\n\n");

    for (int i = 0, o = 0; i < L; i++) {
        if (vector_A[i] < vector_B[i]) {
            printf("\033[32m");
            printf("%d ", vector_B[i]);
            printf("%d ", vector_A[i]);
            printf("\033[0m");
            
        }
        if (vector_A[i] >= vector_B[i]) {
            printf("%d ", vector_A[i]);
            printf("%d ", vector_B[i]);
            
        }
    }
}
