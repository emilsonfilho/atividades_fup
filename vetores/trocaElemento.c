#include <stdio.h>

void changeValues(int *array, int pos1, int pos2) {
    int intermediateValue = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = intermediateValue;
}

void printArray(int lengthArray, int *array) {
    for (int i = 0; i < lengthArray; i++) {
        printf("%d", array[i]);
        if (i != lengthArray - 1) printf(" ");
    }
    printf("\n");
}

int main()
{
    int length = 0, pos1 = 0, pos2 = 0;
    scanf("%d", &length);
    int values[length];
    
    for (int i = 0; i < length; i++) {
        int value = 0;
        scanf("%d", &value);
        values[i] = value;
    }
    
    scanf("%d%d", &pos1, &pos2);
    
    changeValues(values, pos1, pos2);
    printArray(length, values);
    
    return 0;
}