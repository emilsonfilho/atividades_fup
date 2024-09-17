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

int main() {
    int nVec1 = 0, nVec2 = 0, isContained = 1;
    scanf("%d", &nVec1);
    int* vec1 = (int*)readArray(nVec1, sizeof(int));
    scanf("%d", &nVec2);
    int* vec2 = (int*)readArray(nVec2, sizeof(int));
    
    for (int i = 0; i < nVec1; i++) {
        int existsElement = 0;
        for (int j = 0; j < nVec2; j++) {
            if (vec1[i] == vec2[j]) existsElement = 1;
        }
        if (existsElement == 0) {
            isContained = 0;
            break;
        }
    }
    
    isContained ? printf("sim\n") : printf("nao\n");
    
    return 0;
}