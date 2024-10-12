#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
int a, b;
double c;

int main() {
  setlocale(LC_ALL, "RU");
  //Задание 2
  printf("hello world \n");
  
  //Задание 3
  printf("Привет мир \n");
  
  //Задание 4
  printf("a = ");
  scanf_s("%d", &a);
  printf("b = ");
  scanf_s("%d", &b);
  c = (double)a / b;
  if (b != 0) {
    printf("%d/%d = %.1lf\n", a, b, c);
  }
  else {
    printf("Деление на ноль");
  }

  //5 Задание
  printf("a = ");
  scanf_s("%d", &a);
  printf("b = ");
  scanf_s("%d", &b); 

  if (a < b) {
    c = (a * a) + (b * b);
    printf("%.1lf\n", c);
  }
  else {
    c = (a * a) - (b * b);
    printf("%.1lf\n", c); 
    }


  return 0;
}
