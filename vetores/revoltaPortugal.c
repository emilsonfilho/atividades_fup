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

int main() {
    int nValues;
    scanf("%d", &nValues);
    int* values = readArray(nValues);
    
    int even = 0;
    int odd = 0;
    
    for (int i = 0; i < nValues; i++) {
        if (values[i] % 2 == 0) {
            even += values[i];
        } else {
            odd += values[i];
        }
    }

    if (even > odd) {
        printf("rebeldes\n");
    } else if (even == odd) {
        printf("empate\n");
    } else {
        printf("soldados\n");
    }
    
    free(values); // Liberar a memória alocada
    
    return 0;
}
