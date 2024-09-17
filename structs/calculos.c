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

Expression newExpression(float num1, float num2, char operator) {
    Expression response;

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
    float a = readFloat(), b = readFloat();
    
    Expression exp1 = newExpression(a, b, '+');
    Expression exp2 = newExpression(a, b, '-');
    Expression exp3 = newExpression(a, b, '/');
    Expression exp4 = newExpression(a, b, '*');

    printf("%d %d %.1f %d\n", (int)calc(exp1), (int)calc(exp2), calc(exp3), (int)calc(exp4));

    return 0;
}