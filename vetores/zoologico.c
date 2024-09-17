#include <stdio.h>
#include <stdlib.h>

// Função para ordenar um array em ordem crescente
void sortArray(int* array, int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (array[i] > array[j]) {
                // Troca os elementos se estiverem fora de ordem
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void printArray(int* array, int length) {
    for (int i = 0; i < length; ++i) {
        printf("%d", array[i]);
        if (i != length - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

// Função para ler um array de tipo genérico T em C
void* readArray(int length, size_t size) {
    void* array = malloc(length * size);
    
    if (array == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < length; i++) {
        scanf("%d", (int*)array + i);
    }
    
    return array;
}

int* push(int* arr, int len, int newValue) {
    arr = (int*)realloc(arr, (len + 1) * sizeof(int));
    arr[len] = newValue;
    return arr;
}

int main() {
    int len = 0, lastElement = -1, currentLength = 0;
    scanf("%d", &len);
    int* values = (int*)readArray(len, sizeof(int));
    int* uniques = NULL;
    sortArray(values, len);
    
    for (int i = 0; i < len; i++) {
        if (values[i] != lastElement) {
            lastElement = values[i];
            uniques = push(uniques, currentLength, values[i]);
            currentLength++;        
        }
    }
    
    printArray(uniques, currentLength);
    
    return 0;
}
    