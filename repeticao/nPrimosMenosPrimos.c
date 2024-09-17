#include <stdio.h>

int isPrimo(int n) {
    if (n > 1) {
        for (int i = 2; i <= n; i++) {
            if (n % i == 0 && i != n) {
                return 0;
            }
        }
        
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int n = 0, somaPrimos = 0, somaNotPrimos = 0;
    
    scanf("%d", &n);
    
    for (int i = 0; i <= n; i++) {
        if (isPrimo(i)) {
            somaPrimos += i;
        } else {
            somaNotPrimos += i;
        }
    }
    
    printf("%d", somaNotPrimos - somaPrimos);
    
    return 0;
}
