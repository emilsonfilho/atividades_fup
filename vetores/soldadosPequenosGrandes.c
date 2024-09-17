#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printArray(char** array, int length) {
    for (int i = 0; i < length; ++i) {
        printf("%s", array[i]);
        if (i != length - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

char classify(double value, double reference) {
    if (value > reference) {
        return 'G';
    } else if (value == reference) {
        return 'M';
    } else {
        return 'P';
    }
}

char** compareHeights(double* array, int length, double reference) {
    char** heights = (char**)malloc(length * sizeof(char*));
    for (int i = 0; i < length; ++i) {
        heights[i] = (char*)malloc(2 * sizeof(char));
        heights[i][0] = classify(array[i], reference);
        heights[i][1] = '\0';
    }
    return heights;
}

double calculateMean(double* vector, int length) {
    if (length == 0) {
        return 0.0;
    }

    double sum = 0.0;
    for (int i = 0; i < length; ++i) {
        sum += vector[i];
    }
    return sum / length;
}

double* readArray(int length) {
    double* array = (double*)malloc(length * sizeof(double));
    for (int i = 0; i < length; ++i) {
        scanf("%lf", &array[i]);
    }
    return array;
}

int main() {
    int nValues;
    scanf("%d", &nValues);
    double* values = readArray(nValues);

    double mean = calculateMean(values, nValues);

    char** heights = compareHeights(values, nValues, mean);

    printf("%.2f\n", mean);
    printArray(heights, nValues);

    // Liberar a memória alocada
    for (int i = 0; i < nValues; ++i) {
        free(heights[i]);
    }
    free(heights);
    free(values);
    
    return 0;
}
