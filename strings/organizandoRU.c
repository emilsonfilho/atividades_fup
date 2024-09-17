#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *value;
    int length;
    int memory;
} String;

int isContained(char ch, char* arr, int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        if (ch == arr[i]) {
            return 1;
        }
    }

    return 0;
}

int isVowel(char letter) {
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

    if (isContained(letter, vowels, 5)) {
        return 1;
    } else {
        return 0;
    }
}

/*
* Mesmo quando alocado memória maior,
* essa função vai retornar quantos elementos a string tem
*/
int strLen(char *str)
{
    int count = 0, i = 0;

    while (str[i] != '\0')
    {
        count++;
        i++;
    }

    return count;
}

String readString()
{
    String str;
    str.value = (char *)malloc(100 * sizeof(char));
    str.length = 100;

    scanf("%[^\n]", str.value);
    scanf("%*[^\n]");
    scanf("%*c");

    str.length = strLen(str.value);
    str.memory = str.length;

    str.value = (char *)realloc(str.value, str.length * sizeof(char));

    return str;
}

char* concatChar(char* arr, int* arr_size, int* memory, char ch) {
    char* new_arr = arr;
    if (*arr_size + 1 >= *memory) {
        if (*arr_size == 0) { 
            new_arr = (char *)realloc(arr, (2 + 1) * sizeof(char));

            *memory = 3;
        } else {
            new_arr = (char*) realloc(arr, ((2 * (*arr_size)) + 1) * sizeof(char));
            *memory = 2 * (*memory) + 1;
        }

    }

    new_arr[*arr_size] = ch;
    new_arr[*arr_size + 1] = '\0';
    (*arr_size)++;

    return new_arr;
}

String createString() {
    String str;
    str.value = (char*) malloc(sizeof(char));
    str.value[0] = '\0';
    str.length = 0;
    str.memory = 0;

    return str;
}

int main()
{
    String str = readString(), vowels = createString(), consonants = createString();

    for (int i = 0; i < str.length; i++) {
        char c = str.value[i];

        if (c != ' ') {
            if (isVowel(c)) {
                vowels.value = concatChar(vowels.value, &vowels.length, &vowels.memory, c);
            } else {
                consonants.value = concatChar(consonants.value, &consonants.length, &vowels.memory, c);
            }
        }
    }

    printf("%s\n", vowels.value);
    printf("%s\n", consonants.value);

    return 0;
}