#include <stdio.h>
#include <math.h>

int main() {
    float x1, x2, y1, y2, distance = 0;

    scanf("%f", &x1);
    scanf("%f", &y1);
    scanf("%f", &x2);
    scanf("%f", &y2);

    distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

    printf("%.2f\n", distance);
    
    return 0;
}