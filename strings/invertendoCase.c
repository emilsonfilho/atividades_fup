#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct
{
    char* value;
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

    str.value = (char *)realloc(str.value, (str.length + 1) * sizeof(char));

    return str;
}

char reverseCase(char ch)
{
    return (isupper(ch) ? tolower(ch) : toupper(ch));
}

String reverseStringCase(String ref)
{
    String response;
    response.value = (char*) malloc((ref.length + 1) * sizeof(char));
    response.length = ref.length;
    
    for (int i = 0; i < ref.length; i++) {
        response.value[i] = reverseCase(ref.value[i]);
    }

    return response;
}

int main()
{
    String text = readString();

    String reversedCaseString = reverseStringCase(text);

    printf("%s\n", reversedCaseString.value);

    free(text.value);
    free(reversedCaseString.value);

    return 0;
}