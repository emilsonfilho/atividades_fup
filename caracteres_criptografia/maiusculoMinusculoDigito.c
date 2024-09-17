#include <stdio.h>
#include <stdlib.h>

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
    int len = 0, count = 0;
    scanf("%d", &len);
    int* values = (int*)readArray(len, sizeof(int));
    
    for (int i = 0; i < len - 2; i++) {
        if (values[i] == 1 && values[i + 1] == 0 && values[i + 2] == 0) {
            count++;
        }
    }
    
    printf("%d\n", count);
    
    return 0;
}