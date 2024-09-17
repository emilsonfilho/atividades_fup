#include <stdio.h>
#include <stdlib.h>

// Lê (length) valores em um array e retorna o array
int* readArray(int length) {
    int* array = (int*)malloc(length * sizeof(int));
    
    for (int i = 0; i < length; i++) {
        int value = 0;
        scanf("%d", &value);
        array[i] = value;
    }
    
    return array;
}

int main() {
    int nValues = 0;
    scanf("%d", &nValues);
    int* values = readArray(nValues);
    
    int jedi = 0;
    for (int i = 0; i < nValues / 2; ++i) {
        jedi += values[i];
    }

    int sith = 0;
    for (int i = nValues - 1; i >= nValues / 2; --i) {
        sith += values[i];
    }

    if (jedi > sith) {
        printf("Jedi\n");
    } else if (jedi == sith) {
        printf("Empate\n");
    } else {
        printf("Sith\n");
    }
    
    free(values); // Liberar a memória alocada
    
    return 0;
}
