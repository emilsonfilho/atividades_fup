#include <stdio.h>
#include <stdlib.h>

// Função para ler um array de tipo genérico T em C
void* readArray(int length, size_t size) {
    // Aloca memória para o array
    void* array = malloc(length * size);
    
    // Verifica se a alocação foi bem-sucedida
    if (array == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    
    // Lê os elementos do array
    for (int i = 0; i < length; i++) {
        //scanf("%zu", (char*)array + i * size);
        scanf("%d", (int*)array + i);
    }
    
    return array;
}

void changeValues(int *array1, int pos1, int *array2, int pos2) {
    int intermediateValue = *(array1 + pos1);
    *(array1 + pos1) = *(array2 + pos2);
    *(array2 + pos2) = intermediateValue;
}

void printArray(const void *array, size_t size, size_t elementSize, void (*printElement)(const void *)) {
    const char *arrayPtr = (const char *)array;
    for (size_t i = 0; i < size; ++i) {
        printElement(arrayPtr);
        arrayPtr += elementSize;
        if (i != size - 1) {
            printf(" ");
        }
    }
}

void printInt(const void *element) {
    const int *intPtr = (const int *)element;
    printf("%d", *intPtr);
}

int main() {
    int length = 0;
    scanf("%d", &length);
    int* vec1 = (int*)readArray(length, sizeof(int));
    int* vec2 = (int*)readArray(length, sizeof(int));
    
    for (int i = 0; i < length; i++) {
        changeValues(vec1, i, vec2, i);
    }
    
    printArray(vec1, length, sizeof(int), printInt);
    printf("\n");
    printArray(vec2, length, sizeof(int), printInt);
    printf("\n");
    
    return 0;
}