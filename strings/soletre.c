#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char* value;
    int length;
} String;

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
    // str.memory = str.length;

    str.value = (char *)realloc(str.value, str.length * sizeof(char));

    return str;
}

void printSpelledString(String str) {
    printf("[");
    for (int i = 0; i < str.length; i++) {
        printf("%c", str.value[i]);
        if (i != str.length - 1) {
            printf("-");
        }
    }
    printf("]\n");
}

int main() {
    String input = readString();
    
    printSpelledString(input);

    return 0;
}