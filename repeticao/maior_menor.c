#include<stdio.h>

int main()
{
    int n, x, menor, maior = 0;
    int primeiraVez = 1; // true
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        
        if (primeiraVez) {
            menor = x;
            maior = x;
            primeiraVez--;
        } else {
            if (x < menor) {
                menor = x;
            } else if (x > maior) {
                maior = x;
            }
        }
    }
    
    printf("%d %d\n", maior, menor);
    
    return 0;
}