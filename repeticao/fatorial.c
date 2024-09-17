#include<stdio.h>

int main()
{
    int n = 0, fatorial = 1;
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        fatorial *= i;
    }
    
    printf("%d\n", fatorial);
    
    return 0;
}