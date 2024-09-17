#include<stdio.h>

int main()
{
    int hour, min, day, month, year = 0;
    
    scanf("%d", &hour);
    scanf("%d", &min);
    scanf("%d", &day);
    scanf("%d", &month);
    scanf("%d", &year);
    
    printf("%2.2d:%2.2d %2.2d/%2.2d/%2.2d\n", (hour % 12), min, day, month, (year % 100));
    
    return 0;
}