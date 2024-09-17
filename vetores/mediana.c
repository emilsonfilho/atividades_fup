#include <stdio.h>
#include <stdlib.h>

// Lê (length) valores em um array e retorna o array
float* readArray(int length) {
    float* array = (float*)malloc(length * sizeof(float));
    
    for (int i = 0; i < length; i++) {
        scanf("%f", &array[i]);
    }
    
    return array;
}

// Função para ordenar um array em ordem crescente
void sortArray(float* array, int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (array[i] > array[j]) {
                // Troca os elementos se estiverem fora de ordem
                float temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main() {
    int nElements = 0;
    float mediana = 0.0;
    scanf("%d", &nElements);
    int index = nElements / 2;
    float* values = readArray(nElements);
    sortArray(values, nElements);
    
    if (nElements % 2 == 0) {
        mediana = ((float) (*(values + index) + *(values + index - 1))) / 2;
    } else {
        mediana = (float) (*(values + index));
    }
    
    printf("%.1f", mediana);
    
    return 0;
}
