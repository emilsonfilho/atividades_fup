#include<stdio.h>

int main()
{
    int inferior, superior, soma = 0;
    
    scanf("%d%d", &inferior, &superior);
    
    for (int i = inferior; i <= superior; i++) {
        if (i % 2 != 0) {
            soma += i;
        }
    }
    
    printf("%d", soma);
    
    return 0;
}