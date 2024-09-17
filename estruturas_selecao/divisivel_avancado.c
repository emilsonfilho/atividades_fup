#include <stdio.h>

int main() {
    int num = 0;

    scanf("%d", &num);

    (num % 3 == 0 && num % 5 == 0 && num % 7 != 0) ? printf("sim\n") : printf("nao\n");
    
    return 0;
}