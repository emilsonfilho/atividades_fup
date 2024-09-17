#include <stdio.h>
#include <string.h>

// Complexity O(n)
int isValoresIguais(int *arr1, int *arr2, int tamArr1, int tamArr2) {
    if (tamArr1 != tamArr2) {
        return 0; // Os tamanhos dos arrays são diferentes
    }

    for (int i = 0; i < tamArr1; i++) {
        if (arr1[i] != arr2[i]) {
            return 0; // Os elementos correspondentes dos arrays são diferentes
        }
    }

    return 1; // Os arrays são iguais
}

// Complexity O(n)
void lerValores(int tam, int *array) {
    for (int i = 0; i < tam; i++) {
        int valor = 0;
        scanf("%d", &valor);
        array[i] = valor;
    }
}

// Complexity O(n)
void compararEImprimirResultado(int *arr1, int *arr2, int tam1, int tam2) {
    char res[11];
    strcpy(res, isValoresIguais(arr1, arr2, tam1, tam2) ? "Iguais" : "Diferentes");
    printf("%s\n", res);
}

int main()
{
    int tam1 = 0, tam2 = 0;
    
    scanf("%d", &tam1);
    int vals1[tam1];
    lerValores(tam1, vals1);
    
    scanf("%d", &tam2);
    int vals2[tam2];
    lerValores(tam2, vals2);
    
    compararEImprimirResultado(vals1, vals2, tam1, tam2);
    
    return 0;
}