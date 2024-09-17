#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct
{
    char *value;
    int length;
} String;

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

    str.value = (char *)realloc(str.value, str.length * sizeof(char));

    return str;
}

int main()
{
    String str = readString();
    char letter;
    int qtd = 0;
    scanf("%c", &letter);

    for (int i = 0; i < str.length; i++)
    {
        if (tolower(str.value[i]) == tolower(letter))
            qtd++;
    }

    printf("%d\n", qtd);

    return 0;
}