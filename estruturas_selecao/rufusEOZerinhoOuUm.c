#include <stdio.h>

int main() {
    int jog1, jog2, jog3 = 0;

    scanf("%d%d%d", &jog1, &jog2, &jog3);

    if (jog1 == jog2 && jog2 == jog3)
    {
        printf("empate\n");
    } else if (jog2 == jog3) {
        printf("jog1\n");
    } else if (jog1 == jog3) {
        printf("jog2\n");
    } else {
        printf("jog3\n");
    }
    
    return 0;
}