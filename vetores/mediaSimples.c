#include <stdio.h>

int main()
{
    int n = 0;
    float somatorio = 0;
    
    scanf("%d", &n);
    
    int valores[n + 1];
    
    for (int i = 0; i < n; i++) {
        float valor = 0;
        scanf("%f", &valor);
        valores[i] = valor;
    }
    
    for (int i = 0; i < n; i++) {
        somatorio += valores[i];
    }
    
    printf("%.1f\n", somatorio / n);
    
    return 0;
}