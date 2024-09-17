
#include <stdio.h>
#include <stdlib.h>

typedef int (*CompareFunction)(int);

int* readArray(int length) {
    int* array = (int*)malloc(length * sizeof(int));
    
    for (int i = 0; i < length; i++) {
        scanf("%d", &array[i]);
    }
    
    return array;
}

int calculate(int* array, int length, CompareFunction condition) {
    int qtd = 0;
    
    for (int i = 0; i < length; ++i) {
        if (condition(array[i]) && array[i - 1] == 0 && array[i + 1] == 0) {
            qtd++;
        }
    }
    
    return qtd;
}

int hasDoctor(int value) {
    return value != 1;
}

int main() {
    int nElements = 0;
    scanf("%d", &nElements);
    int* heights = readArray(nElements);
    
    int soldiers_without_doctor = calculate(heights, nElements, hasDoctor);
    
    printf("%d\n", soldiers_without_doctor);
    
    free(heights); // Liberar a memória alocada
    
    return 0;
}
