#include<stdio.h>
#include <math.h>

int main()
{
    int digit = 0, number = 0, count = 0, rest = 0, base10 = 0;
    
    scanf("%d %d", &digit, &number);
    
    rest = number;
    
    for (int i = 7; i >= 0; i--) {
        base10 = (int) pow(10, i);
        
        if ((int) (floorf(rest / base10)) == digit) {
            count++;
            printf("entrei\n");
        }
        
        rest = rest % base10;
    }
    
    printf("%d", count);
    
    return 0;
}