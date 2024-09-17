#include <stdio.h>
#include <string.h>

int main()
{
    int jog1, jog2, jog3, jog4, soma;
    char res[7];

    scanf("%d%d%d%d", &jog1, &jog2, &jog3, &jog4);

    soma = jog1 + jog2 + jog3 + jog4;

    if (soma == 0)
    {
        strcpy(res, "nenhum");
    }
    else
    {
        switch (soma % 4)
        {
        case 0:
            strcpy(res, "jog4");
            break;
        case 1:
            strcpy(res, "jog1");
            break;
        case 2:
            strcpy(res, "jog2");
            break;
        case 3:
            strcpy(res, "jog3");
            break;
        default:
            strcpy(res, "error");
            break;
        }
    }

    printf("%s\n", res);

    return 0;
}