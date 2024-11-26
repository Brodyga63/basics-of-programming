#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cctype>
#include <clocale>
#include <windows.h>

using namespace std;

// Прототипы функций
void processText(const char* inputText);
bool containsSyllable(const char* word);
void highlightSyllables(const char* word, char* output);
bool isWordDelimiter(char c);

// Основная функция
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");
    char inputText[1024];

    while (true) {
        cout << "Введите текст (для завершения введите 'exit'):\n";
        cin.getline(inputText, sizeof(inputText));

        if (strcmp(inputText, "exit") == 0) {
            break; // Выход из программы
        }

        processText(inputText);
        cout << endl;
    }

    return 0;
}

// Обработка текста
void processText(const char* inputText) {
    char outputText[2048] = ""; // Для сохранения выходного текста
    const char* wordStart = inputText;
    const char* wordEnd;

    // Ищем слова в тексте
    while (*wordStart) {
        while (isWordDelimiter(*wordStart)) {
            wordStart++; // Игнорируем разделители
        }

        wordEnd = wordStart;
        while (*wordEnd && !isWordDelimiter(*wordEnd)) {
            wordEnd++; // Ищем конец слова
        }

        if (wordEnd > wordStart) { // Если нашлось слово
            char highlightedWord[128];
            highlightSyllables(string(wordStart, wordEnd).c_str(), highlightedWord);
            strcat(outputText, highlightedWord);
            strcat(outputText, " "); // Добавляем пробел между словами
        }

        wordStart = wordEnd; // Переходим к следующему слову
    }

    cout << "Исходный текст:\n" << inputText << endl;
    cout << "Преобразованный текст:\n" << outputText << endl;
}

// Проверка на наличие одного из слогов
bool containsSyllable(const char* word) {
    const char* syllables[] = { "на", "при", "за" };
    for (const char* syllable : syllables) {
        if (strstr(word, syllable) != nullptr) {
            return true;
        }
    }
    return false;
}

// Подсветка слогов в слове
void highlightSyllables(const char* word, char* output) {
    const char* syllables[] = { "на", "при", "за" };
    strcpy(output, "");

    bool syllablesFound = false;
    const char* current = word;
    while (*current) {
        const char* nextSyllable = nullptr;
        const char* nextSyllablePos = nullptr;

        // Ищем ближайший слог
        for (const char* syllable : syllables) {
            const char* pos = strstr(current, syllable);
            if (pos && (!nextSyllablePos || pos < nextSyllablePos)) {
                nextSyllable = syllable;
                nextSyllablePos = pos;
            }
        }

        if (nextSyllablePos) {
            // Копируем часть до слога
            strncat(output, current, nextSyllablePos - current);
            // Подсвечиваем слог
            strcat(output, "(");
            strcat(output, nextSyllable);
            strcat(output, ")");
            current = nextSyllablePos + strlen(nextSyllable); // Переходим к следующей части слова
            syllablesFound = true; // Найден слог
        }
        else {
            // Копируем остаток слова
            strcat(output, current);
            break; // Завершаем цикл
        }
    }
    // Если найдены слоги, заключаем всё слово в скобки
    if (syllablesFound) {
        char tempOutput[128];
        strcpy(tempOutput, output); // Сохраняем текущее состояние
        sprintf(output, "[%s]", tempOutput); // Заключаем в скобки
    }
}

// Проверка, является ли символ разделителем слова
bool isWordDelimiter(char c) {
    return isspace(c) || ispunct(c);
}
