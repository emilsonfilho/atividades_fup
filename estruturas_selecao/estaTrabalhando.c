#include <stdio.h>

int main () {
    int dia, hora, min = 0;

    scanf("%d%d%d", &dia, &hora, &min);

    if (dia != 1)
    {
        // Dias pasśiveis de trabalho
        if (dia != 7)
        {
            // Semana útil
            if (1 < dia && dia < 7)
            {
                if ((8 <= hora && hora <= 11) || (14 <= hora && hora <= 17))
                {
                    // Horário de trabalho (hora)
                    if (0 <= min && min <= 59)
                    {
                        printf("SIM\n");
                    } else {
                        printf("invalida\n");
                    }  
                } else {
                    printf("NAO\n");
                }
                
            } else {
                printf("invalida\n");
            }
            
        } else {
            // Fim de semana
            if (8 <= hora && hora <= 11)
            {
                // Horário de trabalho (horas)
                if (0 <= min && min <= 59)
                {
                    // Horário de trabalho (minutos)
                    printf("SIM\n");
                } else {
                    printf("invalida\n");
                }
            } else {
                // Fora do horário
                printf("NAO\n");
            }
            
        }
        
    } else {
        // Dias que não são passíveis de trabalho
        printf("NAO\n");
    }
    
    
    return 0;
}