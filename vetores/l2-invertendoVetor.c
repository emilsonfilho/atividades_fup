#include <stdio.h>
#include <stdlib.h>

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

void reverseArray(int array[], int length) {
    int start = 0;
    int end = length - 1;
    
    while (start < end) {
        // Troca os elementos nas posições start e end
        int temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        
        // Move os índices start e end para o próximo par de elementos a serem trocados
        start++;
        end--;
    }
}

int main() {
    int len = 0;
    scanf("%d", &len);
    int* values = (int*)readArray(len, sizeof(int));
    
    reverseArray(values, len);
    
    printArray(values, len);
    
    return 0;
}
    