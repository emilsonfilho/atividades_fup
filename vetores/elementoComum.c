#include <stdio.h>
#include <stdlib.h>

int hasOneEqual(int len1, int* array1, int len2, int* array2) {
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (*(array1 + i) == *(array2 + j)) {
                return 1;
            }
        }
    }
    
    return 0;
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
    int nLen1 = 0, nLen2 = 0;
    scanf("%d", &nLen1);
    int* vec1 = (int*)readArray(nLen1, sizeof(int));
    
    scanf("%d", &nLen2);
    int* vec2 = (int*)readArray(nLen2, sizeof(int));
    
    int result = hasOneEqual(nLen1, vec1, nLen2, vec2);
    
    printf("%s\n", result == 1 ? "Existe" : "Nao existe");
    
    return 0;
}