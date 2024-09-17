#include <stdio.h>

int main()
{
    int n1, n2 = 0;
    char operador;

    scanf("%d%d", &n1, &n2);
    scanf(" %c", &operador);

    switch (operador)
    {
    case '+':
        printf("%d\n", n1 + n2);
        break;
    case '-':
        printf("%d\n", n1 - n2);
        break;
    case '*':
        printf("%d\n", n1 * n2);
        break;
    case '/':
        if (n2 == 0)
        {
            printf("invalida\n");
        }
        else
        {
            printf("%f\n", (float)n1 / n2);
        }

        break;

    default:
        printf("invalida\n");
        break;
    }

    return 0;
}