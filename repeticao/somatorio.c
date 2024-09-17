#include<stdio.h>

int main()
{
    int n, somatorio = 0;
    
    scanf("%d", &n);
    
    for (int i = 0; i <= n; i++) {
        somatorio += i;
    }
    
    printf("%d\n", somatorio);
    
    return 0;
}