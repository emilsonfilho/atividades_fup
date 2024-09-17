#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *value;
    int length;
} String;

int str_len(char *str)
{
    int count = 0, i = 0;

    while (str[i] != '\0')
    {
        count++;
        i++;
    }

    return count;
}

String read_string()
{
    String str;
    str.value = (char *)malloc(100 * sizeof(char));
    str.length = 100;

    scanf("%[^\n]", str.value);
    scanf("%*[^\n]");
    scanf("%*c");

    str.length = str_len(str.value);

    str.value = (char *)realloc(str.value, str.length * sizeof(char));

    return str;
}

int main()
{
    String str = read_string();
    char letter;
    int qtd = 0;
    scanf("%c", &letter);

    for (int i = 0; i < str.length; i++) {
        if (str.value[i] == letter) qtd++;
    }

    printf("%d\n", qtd);

    return 0;
}