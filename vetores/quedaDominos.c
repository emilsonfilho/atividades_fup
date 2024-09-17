#include <stdio.h>
#include <stdlib.h>

// Lê (length) valores em um array e retorna o array
int* readArray(int length) {
    int* array = (int*)malloc(length * sizeof(int));
    
    for (int i = 0; i < length; i++) {
        scanf("%d", &array[i]);
    }
    
    return array;
}

// Verifica se dois arrays são iguais
int areArraysEqual(int* arr1, int* arr2, int len) {
    for (int i = 0; i < len; i++) {
        if (arr1[i] != arr2[i]) {
            return 0; // Retorna falso se encontrar elementos diferentes
        }
    }
    return 1; // Retorna verdadeiro se os arrays forem iguais
}

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

int main() {
    int nElements = 0;
    scanf("%d", &nElements);
    int* numbers = readArray(nElements);
    int* orderedNumbers = (int*)malloc(nElements * sizeof(int));

    // Copia os valores de numbers para orderedNumbers
    for (int i = 0; i < nElements; i++) {
        orderedNumbers[i] = numbers[i];
    }
    
    // Ordena o array orderedNumbers
    sortArray(orderedNumbers, nElements);
    
    // Verifica se o array original está ordenado
    int isOriginalOrdered = areArraysEqual(numbers, orderedNumbers, nElements);
    
    if (isOriginalOrdered) {
        printf("ok\n");
    } else {
        printf("precisa de ajuste\n");
    }

    // Libera a memória alocada
    free(numbers);
    free(orderedNumbers);
        
    return 0;
}
