#include <stdio.h>

int main() {
    int n1, n2, n3, iguais = 0;
    
    scanf("%d%d%d", &n1, &n2, &n3);
    
    if (n1 == n2 && n2 == n3) {
        iguais = 3;
    } else if (n1 == n2 || n2 == n3 || n1 == n3) {
        iguais = 2;
    } else {
        iguais = 1;
    }
    
    printf("%d", iguais);
}