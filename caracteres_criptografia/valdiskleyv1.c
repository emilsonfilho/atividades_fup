#include <stdio.h>
#include <stdlib.h>

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
    char letter;
    int after = 0;
    char* alphabet = createAlphabet();

    scanf(" %c", &letter);
    scanf("%d", &after);

    int indexInitial = indexOf(alphabet, 26, letter);
    int next = (indexInitial + after + 26) % 26;

    printf("%c\n", alphabet[next]);

    free(alphabet);

    return 0;
}