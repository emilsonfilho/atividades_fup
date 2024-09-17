#include <stdio.h>
#include <string.h>

int main() {
    float weight, height, imc = 0;
    char situation[25] = "";
    
    scanf("%f%f", &weight, &height);
    
    imc = weight / (height * height);
    
    if (imc < 17) {
        strcpy(situation, "muito abaixo do peso");
    } else if (17 <= imc && imc < 18.5) {
        strcpy(situation, "abaixo do peso");
    } else if (18.5 <= imc && imc < 25) {
        strcpy(situation, "peso normal");
    } else if (25 <= imc && imc < 30) {
        strcpy(situation, "acima do peso");
    } else if (30 <= imc && imc < 35) {
        strcpy(situation, "obesidade");
    } else if (35 <= imc && imc < 40) {
        strcpy(situation, "obesidade severa");
    } else {
        strcpy(situation, "obesidade morbida");
    }
    
    printf("%s", situation);
}