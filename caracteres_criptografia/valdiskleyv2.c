#include <stdio.h>
#include <stdlib.h>

#define ALPHABET_LENGTH 26

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

int main() {
    char first, second, operation;
    scanf(" %c %c %c", &first, &operation, &second);
    char* alphabet = createAlphabet();

    int firstValue = indexOf(alphabet, ALPHABET_LENGTH, first);
    int secondValue = indexOf(alphabet, ALPHABET_LENGTH, second);
    if (operation == '-') secondValue = -secondValue;

    int result = (firstValue + secondValue + ALPHABET_LENGTH) % ALPHABET_LENGTH;

    printf("%c\n", alphabet[result]);

    free(alphabet);

    return 0;
}