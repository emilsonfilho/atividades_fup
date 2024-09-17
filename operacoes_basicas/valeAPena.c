#include <stdio.h>

int main() {
    int max_quantity = 0;
    float price, unit_value = 0;

    scanf("%d", &max_quantity);
    scanf("%f", &price);

    unit_value = price / max_quantity;

    printf("%f ", unit_value * 4);
    printf("%f ", unit_value * 8);
    printf("%f ", unit_value * 12);
    printf("%f ", unit_value * 16);
    
    return 0;
}