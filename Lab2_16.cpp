#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
int number;

int main() {
    setlocale(LC_ALL, "RU");
    while (true) {
        printf("Введите число: ");
        scanf("%d", &number);
        if (number > 0) {
            break;
        }
    }
    for (int i = 2; i < number; i++) {
        int count = 0;
        for (int j = 1; j < number; j++) {
            if (i % j == 0) {
                count += 1;
            }
        }
        if (count == 2) {
            printf("%d, ", i);
        }
    }
}