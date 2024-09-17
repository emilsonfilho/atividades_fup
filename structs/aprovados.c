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

void printTotalAverage(float av1, float av2) {
    printf("%.2f\n", (av1 + av2) / 2);
}

void printStudent(StudentReg student, float average) {
    printf("%s %.2f\n", student.name.value, average);
}

int main() {
    StudentReg student1 = readStudent();
    StudentReg student2 = readStudent();
    StudentReg student3 = readStudent();

    float average1 = calcAverage(student1);
    float average2 = calcAverage(student2);
    float average3 = calcAverage(student3);

    if (average1 >= 7) {
        printStudent(student1, average1);
    }
    if (average2 >= 7) {
        printStudent(student2, average2);
    }if (average3 >= 7) {
        printStudent(student3, average3);
    }

    free(student1.grades);
    free(student2.grades);
    free(student3.grades);

    return 0;
}