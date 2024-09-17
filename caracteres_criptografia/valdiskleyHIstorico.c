#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    char* value;
    int length;
} String;

int str_len(char* str) {
    int count = 0, i = 0;

    while (str[i] != '\0') {
        count++;
        i++;
    }
    

    return count;
}

int indexOf(String str, char ch) 
{
    for (int i = 0; i < str.length; i++) {
        if (str.value[i] == ch) return i;
    }

    return -1;
}

String read_string() {
    String str;
    str.value = (char*) malloc(100 * sizeof(char));
    str.length = 100;

    scanf("%[^\n]", str.value);
    scanf("%*[^\n]");
    scanf("%*c");

    str.length = str_len(str.value);

    str.value = (char*) realloc(str.value, str.length * sizeof(char));

    return str;
}

char transformChar(char ch, String str1, String str2) {
    int isUpper = isupper(ch);
    char lowerChar = tolower(ch);

    int index = indexOf(str1, lowerChar);
    if (index != -1) {
        char newChar = str2.value[index];
        return isUpper ? toupper(newChar) : newChar;
    }

    return ch;
}

int main() {
    String text = read_string();
    String word1 = read_string();
    String word2 = read_string();

    for (int i = 0; i < text.length; i++) {
        char* ch = &text.value[i];
        if (indexOf(word1, *ch) != -1) {
            *ch = transformChar(*ch, word1, word2);
        }
        else if (indexOf(word2, *ch) != -1)
        {
            *ch = transformChar(*ch, word2, word1);
        }
    }

    printf("%s\n", text.value);

    free(text.value);
    free(word1.value);
    free(word2.value);

    return 0;
}