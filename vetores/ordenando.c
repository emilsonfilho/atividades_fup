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
        printf("%d\n", array[i]);
        /*if (i != length - 1) {
            printf(" ");
        }*/
    }
    //printf("\n");
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

int main() {
    int nLen1 = 0;
    scanf("%d", &nLen1);
    int* vec1 = (int*)readArray(nLen1, sizeof(int));
    sortArray(vec1, nLen1);
    
    printArray(vec1, nLen1);
    
    return 0;
}
