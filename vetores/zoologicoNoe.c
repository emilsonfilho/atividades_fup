#include <stdio.h>
#include <stdlib.h>

int countCouples(int *array, int length) {
    int count = 0;
    int *visited = (int*)calloc(length, sizeof(int)); // Array para marcar os elementos já visitados
    
    if (visited == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    
    for (int i = 0; i < length; i++) {
        if (!visited[i]) { // Se o elemento ainda não foi visitado
            for (int j = i + 1; j < length; j++) {
                if (!visited[j] && array[i] == -array[j]) { // Se o elemento j ainda não foi visitado e forma um casal com o elemento i
                    visited[i] = 1; // Marca o elemento i como visitado
                    visited[j] = 1; // Marca o elemento j como visitado
                    count++; // Incrementa o contador de casais
                    break; // Sai do loop interno para evitar contar o mesmo casal duas vezes
                }
            }
        }
    }
    
    free(visited); // Libera a memória alocada para o array de visitados
    return count;
}

int* readArray(int length) {
    int *array = (int*)malloc(length * sizeof(int));
    
    if (array == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    
    for (int i = 0; i < length; i++) {
        scanf("%d", &array[i]);
    }
    
    return array;
}

int main() {
    int nBeings = 0;
    scanf("%d", &nBeings);
    int *beings = readArray(nBeings);
    
    int nCouples = countCouples(beings, nBeings);
    printf("%d\n", nCouples);
    
    free(beings);
    
    return 0;
}
