#include <stdio.h>

int main() {
    int n1, n2, n3, n4, res = 0;

    scanf("%d%d%d%d", &n1, &n2, &n3, &n4);

    if (n1 >= n2 && n1 >= n3 && n1 >= n4)
    {
        res = n1;
    } else if (n2 >= n1 && n2 >= n3 && n2 >= n4) {
        res = n2;
    } else if (n3 >= n1 && n3 >= n2 && n3 >= n4) {
        res = n3;
    } else {
        res = n4;
    }

    printf("%d\n", res);
    
    return 0;
}