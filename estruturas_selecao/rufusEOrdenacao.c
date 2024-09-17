#include <stdio.h>

int main() {
    int n1, n2, n3;

    scanf("%d%d%d", &n1, &n2, &n3);

    if (n1 != n2 && n2 != n3 && n1 != n3)
    {
        if (n1 < n2 && n2 < n3)
        {
            printf("P M G\n");
        } else if (n1 < n3 && n3 < n2) { 
            printf("P G M\n");
        } else if (n3 < n1 && n1 < n2) {
            printf("M G P\n");
        } else if (n2 < n1 && n1 < n3) {
            printf("M P G");
        } else if (n2 < n3 && n3 < n1) {
            printf("G P M\n");
        } else {
            printf("G M P\n");
        }
    } else {
        printf("invalida\n");
    }
    
    return 0;
}