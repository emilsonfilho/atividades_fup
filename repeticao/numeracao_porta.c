#include <stdio.h>
#include <math.h>

int main() {
    int n = 0, resultado = 0;
    double phi = (1 + sqrt(5)) / 2;
    
    scanf("%d", &n);
    
    resultado = round((pow(phi, n) - pow(1 - phi, n)) / sqrt(5));
    printf("%d", resultado);
    
    return 0;
}
