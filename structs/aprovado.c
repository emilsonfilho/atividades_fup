#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *value;
    int length;
} String;

typedef struct
{
    String name;
    int registration;
    String discipline;
    float grade;
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

int readInt()
{
    int value = 0;
    scanf("%d", &value);
    return value;
}

float readFloat()
{
    float value = 0;
    scanf("%f", &value);
    return value;
}

StudentReg readStudent()
{
    StudentReg student;

    String name = readString();
    int registration = readInt();
    String discipline = readString();
    float grade = readFloat();

    student.name = name;
    student.registration = registration;
    student.discipline = discipline;
    student.grade = grade;

    return student;
}

int isApproved(StudentReg student)
{
    return student.grade >= 7;
}

void printAcademicSituation(StudentReg student, int approved)
{
    printf("%s %s(a) em %s\n", student.name.value, approved ? "aprovado" : "reprovado", student.discipline.value);
}

int main()
{
    StudentReg student = readStudent();

    int wasApproved = isApproved(student);

    printAcademicSituation(student, wasApproved);

    return 0;
}