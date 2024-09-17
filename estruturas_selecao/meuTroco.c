#include <stdio.h>
#include <math.h>

float resto(float troco, float moeda) {
    return fmod(troco, moeda);
}

void calcularTroco(float *troco, float moeda, int *quantidade) {
    if (*troco >= moeda) {
        *quantidade = floorf(*troco / moeda);
        *troco = resto(*troco, moeda);
    } else {
        *quantidade = 0;
    }
}

int main() {
    float total, recebido, troco = 0;
    int c100, c50, c20, c10, c5, c2, m1, m50, m25, m10, m5, m01 = 0;
    
    scanf("%f%f", &total, &recebido);
    
    if (recebido > total) {
        troco = recebido - total;
        calcularTroco(&troco, 100, &c100);
        calcularTroco(&troco, 50, &c50);
        calcularTroco(&troco, 20, &c20);
        calcularTroco(&troco, 10, &c10);
        calcularTroco(&troco, 5, &c5);
        calcularTroco(&troco, 2, &c2);
        calcularTroco(&troco, 1, &m1);
        calcularTroco(&troco, 0.5, &m50);
        calcularTroco(&troco, 0.25, &m25);
        calcularTroco(&troco, 0.1, &m10);
        calcularTroco(&troco, 0.05, &m5);
        calcularTroco(&troco, 0.01, &m01);
        
        printf("Cédulas de R$100.00: %d\nCédulas de R$50.00: %d\nCédulas de R$20.00: %d\nCédulas de R$10.00: %d\nCédulas de R$5.00: %d\nCédulas de R$2.00: %d\nMoeda de R$1.00: %d\nMoeda de R$0.50: %d\nMoeda de R$0.25: %d\nMoeda de R$0.10: %d\nMoeda de R$0.05: %d\nMoeda de R$0.01: %d\n", c100, c50, c20, c10, c5, c2, m1, m50, m25, m10, m5, m01);
    } else {
        printf("Valor Insuficiente, faltaram R$ %.2f", total - recebido);
    }
    
    return 0;
}