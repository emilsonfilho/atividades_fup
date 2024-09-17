#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
    char *value;
    int length;
    int memory;
} String;

int isContained(char ch, char *arr, int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        if (ch == arr[i])
        {
            return 1;
        }
    }

    return 0;
}

int isVowel(char letter)
{
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

    if (isContained(letter, vowels, 5))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

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

char *concatChar(char *arr, int *arr_size, int *memory, char ch)
{
    char *new_arr = arr;
    if (*arr_size + 1 >= *memory)
    {
        if (*arr_size == 0)
        {
            new_arr = (char *)realloc(arr, (2 + 1) * sizeof(char));

            *memory = 3;
        }
        else
        {
            new_arr = (char *)realloc(arr, ((2 * (*arr_size)) + 1) * sizeof(char));
            *memory = 2 * (*memory) + 1;
        }
    }

    new_arr[*arr_size] = ch;
    new_arr[*arr_size + 1] = '\0';
    (*arr_size)++;

    return new_arr;
}

String createString()
{
    String str;
    str.value = (char *)malloc(sizeof(char));
    str.value[0] = '\0';
    str.length = 0;
    str.memory = 0;

    return str;
}

int count_tokens(char *str, char delimiter)
{
    int count = 1;

    while (*str != '\0')
    {
        if (*str == delimiter)
            count++;
        str++;
    }

    return count;
}

String *split(String input, char delimiter, int *num_tokens)
{
    int tokens_count = count_tokens(input.value, delimiter);
    *num_tokens = tokens_count;

    String *result = (String *)malloc(tokens_count * sizeof(String));
    int token_index = 0;
    char *start = input.value;
    char *end = input.value;

    while (*end != '\0')
    {
        if (*end == delimiter)
        {
            int token_length = end - start;
            result[token_index].value = (char *)malloc((token_length + 1) * sizeof(char));

            strncpy(result[token_index].value, start, token_length);
            result[token_index].value[token_length] = '\0';
            result[token_index].length = token_length;
            result[token_index].memory = token_length;

            token_index++;
            start = end + 1;
        }
        end++;
    }

    // For the last token
    int token_length = end - start;
    result[token_index].value = (char *)malloc((token_length + 1) * sizeof(char));

    strncpy(result[token_index].value, start, token_length);
    result[token_index].value[token_length] = '\0';
    result[token_index].length = token_length;
    result[token_index].memory = token_length;

    return result;
}

int main()
{
    String text = readString();
    int num_splitted_words = 0;

    String* words = split(text, ' ', &num_splitted_words);
    
    for (int i = 0; i < num_splitted_words; i++) {
        for (int j = 1; j <= 2; j++) {
            printf("%s", words[i].value);

            if (i != num_splitted_words - 1 || j != 2) {
                printf(" ");
            }
        }
    }

    printf("\n");

    return 0;
}