#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    float num1;
    float num2;
    char operator;
} Expression;

float readFloat()
{
    float value = 0;
    scanf("%f", &value);
    return value;
}

char readChar() {
    char value = ' ';
    scanf(" %c", &value);
    return value;
}

Expression readExpression() {
    Expression response;

    float num1 = readFloat();
    float num2 = readFloat();
    char operator = readChar();

    response.num1 = num1;
    response.num2 = num2;
    response.operator = operator;

    return response;
}

float calc(Expression exp) {
    float a = exp.num1, b = exp.num2;
    char op = exp.operator;

    switch (op)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        return a / b;
        break;
    default:
        printf("Operação não encontrada.\n");
        break;
    }
}

int main() {
    Expression exp = readExpression();

    float result = calc(exp);

    if (exp.operator == '/') {
        printf("%.1f\n", calc(exp));
    } else {
        printf("%d\n", (int) calc(exp));
    }

    return 0;
}