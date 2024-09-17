#include <stdio.h>
#include <stdlib.h>

void checkAllocation(void *ptr) {
    if (ptr == NULL) {
        printf("Error allocating memory.\n");
        exit(1);
    }
}

int readLength() {
    int len = 0;
    scanf("%d", &len);
    return len;
}

int* readArray(int length) {
    int *array = (int*) malloc(length * sizeof(int));
    
    checkAllocation(array);
    
    for (int i = 0; i < length; i++) {
        int value = 0;
        scanf("%d", &value);
        array[i] = value;
    }
    
    return array;
}

void printArray(int lengthArray, int *array) {
    for (int i = 0; i < lengthArray; i++) {
        printf("%d", array[i]);
        if (i != lengthArray - 1) printf(" ");
    }
    printf("\n");
}

int* subarray(int* arr, int start, int end) {
    int size = end - start;
    int* sub = (int*)malloc(size * sizeof(int));
    
    checkAllocation(sub);
    
    for (int i = start; i < end; i++) {
        sub[i - start] = arr[i];
    }
    
    return sub;
}

void merge(int *array, int begin, int mid, int end) {
    int *left = subarray(array, begin, mid + 1);
    int *right = subarray(array, mid + 1, end + 1);
    int left_size = mid - begin + 1;
    int right_size = end - mid;
    int i = 0, j = 0;
    
    for (int k = begin; k <= end; k++) {
        if (i >= left_size) {
            array[k] = right[j];
            j++;
        } else if (j >= right_size) {
            array[k] = left[i];
            i++;
        } else if (left[i] < right[j]) {
            array[k] = left[i];
            i++;
        } else {
            array[k] = right[j];
            j++;
        }
    }
    
    free(left);
    free(right);
}

void mergeSort(int *array, int begin, int end) {
    if (end > begin) {
        int mid = (end + begin) / 2;
        mergeSort(array, begin, mid);
        mergeSort(array, mid + 1, end);
        merge(array, begin, mid, end);
    }
}

int main()
{
    int length = 5;
    int *values = readArray(length);
    
    mergeSort(values, 0, length - 1);
    
    int firstElement = values[0];
    int lastElement = values[length - 1];
    
    printf("%d\n", firstElement + lastElement);
    
    free(values);
    
    return 0;
}
