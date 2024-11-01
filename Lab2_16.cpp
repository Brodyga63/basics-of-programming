#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#define m 10000
int number;
int A[m];

int main() {
    setlocale(LC_ALL, "RU");
    while (true) {
        printf("Введите число: ");
        scanf("%d", &number);
        if (number > 0) {
            break;
        }
    }
    
    for (int i=1; i < number+1; i++) {
        A[i] = i;
    }
    for (int i=1; i < number+1; i++) {
        printf("%d ", A[i]);
    }
    


    
 /*   for (int i = 2; i < number; i++) {
        int count = 0;
        for (int j = 1; j < number; j++) {
            if (i % j == 0) {
                count += 1;
            }
        }
        if (count == 2) {
            printf("%d, ", i);
        }
    }*/
}
