#include <stdio.h>

int main()
{
    float gasoline, ethanol = 0;

    scanf("%f%f", &gasoline, &ethanol);

    if (gasoline > (1.3 * ethanol))
    {
        printf("Alcool\n");
    } else {
        printf("Gasolina\n");
    }
    
    return 0;
}