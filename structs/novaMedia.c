#include <stdio.h>
#include <stdlib.h>

#define NUM_GRADES 3

typedef struct
{
    char *value;
    int length;
} String;

typedef struct
{
    String name;
    float *grades;
} StudentReg;

int strLen(char *str)
{
    int length = 0;

    while (str[length] != '\0')
    {
        length++;
    }

    return length;
}

String readString()
{
    String str;
    str.value = (char *)malloc(100 * sizeof(char));
    str.length = 100;

    scanf("%s", str.value);

    str.length = strLen(str.value);
    str.value = (char *)realloc(str.value, (str.length + 1) * sizeof(char));

    return str;
}

float* readFloats(int size)
{
    float *arr = (float*) malloc(size * sizeof(float));

    for (int i = 0; i < size; i++) {
        scanf("%f", &arr[i]);
    }

    return arr;
}

StudentReg readStudent() {
    StudentReg student;

    student.name = readString();
    student.grades = readFloats(NUM_GRADES);

    return student;
}

float calcAverage(StudentReg student) {
    float sum = 0;

    for (int i = 0; i < NUM_GRADES; i++) {
        sum += student.grades[i];
    }

    return sum / NUM_GRADES;
}

int main() {
    StudentReg student = readStudent();

    float average = calcAverage(student);

    printf("%.2f\n", average);

    free(student.grades);

    return 0;
}