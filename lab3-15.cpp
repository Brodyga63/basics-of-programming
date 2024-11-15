#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <windows.h>
using namespace std; 

// Преобразование строки в нижний регистр
void toLower(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Проверка наличия слога в слове
bool containsSyllable(const char* word, const char* syllable) {
    char temp[256];
    strcpy(temp, word);
    toLower(temp);
    return strstr(temp, syllable) != nullptr;
}

// Обработка текста
void processText(char* text, char* result) {
    char* word = strtok(text, " \n");
    bool firstWord = true;

    while (word) {
        if (containsSyllable(word, "на") || containsSyllable(word, "при") || containsSyllable(word, "за")) {
            if (!firstWord) strcat(result, " ");
            strcat(result, "(");
            strcat(result, word);
            strcat(result, ")");
            firstWord = false;
        }
        else {
            if (!firstWord) strcat(result, " ");
            strcat(result, word);
            firstWord = false;
        }
        word = strtok(nullptr, " \n");
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RU");
    char inputText[1024] = { 0 };  // Буфер для ввода текста
    char processedText[2048] = { 0 };  // Буфер для хранения результата
    char continueChoice[4];  // Буфер для ввода "да"/"нет"

    do {
        printf("Введите текст (несколько строк, закончите ввод пустой строкой):\n");

        // Чтение текста
        inputText[0] = '\0';  // Очищаем буфер
        char line[256];
        while (fgets(line, sizeof(line), stdin) && strlen(line) > 1) {
            strcat(inputText, line);  // Добавляем строку к общему тексту
        }

        // Выводим исходный текст
        printf("\nИсходный текст:\n%s", inputText);

        // Обрабатываем текст
        processText(inputText, processedText);

        // Выводим преобразованный текст
        printf("\n\nПреобразованный текст:\n%s\n", processedText);

        // Запрос на продолжение
        printf("\n\nХотите ввести другой текст? (да/нет): ");
        fgets(continueChoice, sizeof(continueChoice), stdin);
        continueChoice[strcspn(continueChoice, "\n")] = 0;  // Удаление перевода строки
    } while (strcmp(continueChoice, "да") == 0);

    printf("Спасибо за использование программы!\n");
    return 0;
}
