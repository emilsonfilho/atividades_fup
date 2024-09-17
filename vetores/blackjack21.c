#include <stdio.h>
int main() {
    int i, n, valor=0, q1=0;
    scanf("%d", &n);
    int v[n];
    for(i=0;i<n;i++) {
        scanf("%d", &v[i]);
    }
    for(i=0;i<n;i++) {
        if(v[i]>=11 && v[i]<=13) {
            valor+= 10;
        } else if(v[i]==1) {
            valor+= 11;
            q1++;
        } else {
            valor+= v[i];
        }
    }
    while(valor>21 && q1>0) {
        valor-= 10;
        q1--;
    }
    printf("%d\n", valor);
    return 0;
}