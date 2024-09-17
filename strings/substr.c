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

// Precisa de desalocação no espoco onde a função é chamada
char* substr(String str, int index, int numChars) {
    char* subString;

    if (index > str.length) {
        subString = (char *)malloc(sizeof(char));
        subString[0] = '\0';

        return subString;
    }

    subString = (char*) malloc(numChars * sizeof(char));

    int j = 0;
    for (int i = 0; i < numChars; i++) {
        subString[j++] = str.value[index];
        index++;
    }

    return subString;
}

int main() {
    String input = readString();
    int index, numChars;
    scanf("%d%d", &index, &numChars);

    char* response = substr(input, index, numChars);

    printf("%s\n", response);

    free(response);

    return 0;
}