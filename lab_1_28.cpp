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


int chr[m][n] = { 0 };
int width, height;


int main() {
  setlocale(LC_ALL, "RU");
  printf("Введите количество строк: ");
  scanf("%d \n", &width);
  printf("Введите количество столбцов: ");
  scanf("%d\n", &height);

  printf("%d %d", width, height);


}
