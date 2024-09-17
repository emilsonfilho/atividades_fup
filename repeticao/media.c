#include<stdio.h>

int main()
{
    int n, x, soma = 0;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        soma += x;
    }
    
    printf("%.2f", (float) soma / n);
    
    return 0;
}