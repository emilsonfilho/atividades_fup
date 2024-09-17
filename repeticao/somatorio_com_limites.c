#include<stdio.h>

int main()
{
    int n, somatorio = 0;
    
    scanf("%d", &n);
    
        for (int i = 3; i <= n; i++) {
            somatorio += (i + 2);
        }
    
        printf("%d\n", somatorio);
    
    
    return 0;
}