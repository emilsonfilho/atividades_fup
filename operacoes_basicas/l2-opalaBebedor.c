#include <stdio.h>

int main() {
    int velocity, time = 0;
    float consumption, performance = 0;
    
    scanf("%d", &velocity);
    scanf("%d", &time);
    scanf("%f", &consumption);

    performance = (velocity * ((float) time / 60)) / consumption;

    printf("%.2f\n", performance);
    
    return 0;
}