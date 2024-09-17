#include<stdio.h>

int main()
{
    int i = 1, n = 0, soma = 0, x = 3;
    
    scanf("%d", &n);
    
    while (i <= n) {
        if (x % 3 == 0 && x % 7 != 0) {
            soma += x;
            i++;
        }
        x++;
    }
    
    printf("%d", soma);
    
    return 0;
}