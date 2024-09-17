#include <stdio.h>

int main() {
    int n = 0;
    
    scanf("%d", &n);
    
    if (n > 1) {
        for (int i = 2; i <= n; i++) {
            if (n % i == 0 && i != n) {
                printf("nao");
                return 0;
            }
        }
        
        printf("sim");
    } else {
        printf("nao");
    }
    
    return 0;
}
