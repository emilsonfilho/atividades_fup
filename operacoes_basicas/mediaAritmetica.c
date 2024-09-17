#include<stdio.h>

int main()
{
    float a, b = 0;
    
    scanf("%f", &a);
    scanf("%f", &b);
    
    printf("%.2f\n", (a + b) / 2);
    
    return 0;
}