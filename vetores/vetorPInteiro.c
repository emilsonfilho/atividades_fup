#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int size;
    
    // Pedindo ao usuário o tamanho do vetor
    scanf("%d", &size);
    
    // Criando o vetor
    int *vetor = (int*)malloc(size * sizeof(int));
    
    // Lendo os valores do vetor do usuário
    for (int i = 0; i < size; i++) {
        scanf("%d", &vetor[i]);
    }
    
    // Convertendo o vetor para um número inteiro
    int numero = 0;
    for (int i = 0; i < size; i++) {
        numero = numero * 10 + vetor[i];
    }
    
    // Exibindo o número inteiro correspondente
    printf("%d\n", numero);
    
    // Liberando a memória alocada para o vetor
    free(vetor);
    
    return 0;
}
