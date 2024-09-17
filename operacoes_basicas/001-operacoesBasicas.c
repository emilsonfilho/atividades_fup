#include<stdio.h>

int main() {
    int a, b = 0; 
    
    scanf("%d", &a);
    scanf("%d", &b);
    
    printf("%d\n", a + b);
    printf("%d\n", a - b);
    printf("%d\n", a * b);
    printf("%.2f\n", (float) a / b);
    printf("%d\n", a % b);
    
    return 0;
}