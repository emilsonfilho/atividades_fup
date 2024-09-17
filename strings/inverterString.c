#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *value;
    int length;
} String;

char *reverse(char *arr, int len)
{
    if (arr == NULL || len == 0)
        return NULL;

    char *reversed_array = (char *)malloc(len * sizeof(char));

    for (int i = 0; i < len; i++)
    {
        reversed_array[i] = arr[len - 1 - i];
    }

    return reversed_array;
}

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
    
    str.value = reverse(str.value, str.length);

    printf("%s\n", str.value);

    return 0;
}