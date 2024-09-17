#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ALPHABET_LENGTH 26

typedef struct {
    char* value;
    int length;
} String;

int str_len(char* str) {
    int count = 0, i = 0;

    while (str[i] != '\0') {
        count++;
        i++;
    }
    

    return count;
}

int indexOf(char* arr, int arr_size, char ch) {
    for (int i = 0; i < arr_size; i++) {
        if (arr[i] == ch) {
            return i;
        }
    }

    return -1;
}

char* createAlphabet() {
    char* alphabet = (char*) malloc(26 * sizeof(char));

    char ch = 'a';
    for (int i = 0; i < 26; i++) {
        alphabet[i] = ch;
        ch++;
    }

    return alphabet;
}

int isCharInString(char ch, String string) {
    for (int i = 0; i < string.length; i++) {
        if (ch == string.value[i]) return 1;
    }

    return 0;
}

String read_string() {
    String str;
    str.value = (char*) malloc(100 * sizeof(char));
    str.length = 100;

    scanf("%[^\n]", str.value);
    scanf("%*[^\n]");
    scanf("%*c");

    str.length = str_len(str.value);

    str.value = (char*) realloc(str.value, str.length * sizeof(char));

    return str;
}

char* concat_char(char* str, int* str_size, char ch) {
    char* new_str = (char*) realloc(str, (*str_size + 1) * sizeof(char));
    new_str[*str_size] = ch;
    (*str_size)++;
    new_str[*str_size] = '\0';

    return new_str;
}

String getPassword(String text, String key) {
    String password;
    password.value = (char*) malloc(1 * sizeof(char));
    password.length = 0;

    password.value[0] = '\0';

    int index = 0;

    for (int i = 0; i < text.length; i++) {
        char ch = text.value[i];

        if (!isCharInString(ch, (String) { ".!-?", 4 })) {
            if (ch == ' ') {
                password.value = concat_char(password.value, &password.length, ch);
            } else {
                password.value = concat_char(password.value, &password.length, key.value[index % key.length]);
                index++;
            }
        }
    }

    return password;
}

char sumLetter(char* alphabet, char first, char operation, char second) {
    int isFirstUp = isupper(first) ? 1 : 0;
    int firstValue = indexOf(alphabet, ALPHABET_LENGTH, tolower(first));
    int secondValue = indexOf(alphabet, ALPHABET_LENGTH, second);
    if (operation == '-') secondValue = -secondValue;

    int result = (firstValue + secondValue + ALPHABET_LENGTH) % ALPHABET_LENGTH;

    return isFirstUp ? toupper(alphabet[result]) : alphabet[result];
}

String encrypt(String text, String password, char* alphabet, char operation) {
    String encrypted;
    encrypted.value = (char*) malloc(1 * sizeof(char));
    encrypted.length = 0;
    encrypted.value[0] = '\0';

    int delay = 0;

    for (int i = 0; i < text.length; i++) {
        char ch = text.value[i];

        if (!isCharInString(ch, (String) { ".!-? ", 5 })) {
            char transformedChar = sumLetter(alphabet, ch, operation, password.value[i - delay]);
            encrypted.value = concat_char(encrypted.value, &encrypted.length, transformedChar);
        } else {
            encrypted.value = concat_char(encrypted.value, &encrypted.length, ch);
            if (ch != ' ') {
                delay++;
            }
        }
    }

    return encrypted;
}

int main() {
    String text = read_string(), key = read_string();
    char operation;
    char* alphabet = createAlphabet();
    scanf(" %c", &operation);

    String password = getPassword(text, key);
    String encrypted = encrypt(text, password, alphabet, operation);

    printf("%s\n", encrypted.value);

    free(alphabet);
    free(text.value);
    free(key.value);
    free(password.value);
    free(encrypted.value);

    return 0;
}