//Exercicio 2 - Calculo de Notas
#include <stdio.h>

#define PESO0 3.5
#define PESO1 7.5
#define NOTAMAX 10.0
#define NOTAMIN 0.0

void main(){

    //Criacao de variaveis e atribuicao de valores as mesmas 
    double media=0, nota[2]={-10.0,-10.0};

    //Atribuicao de valor as variaveis de nota por input
    do{
        scanf("%lf %lf",&nota[0],&nota[1]);
    }while (((nota[0] > NOTAMAX) || (nota[1] > NOTAMAX)) || ((nota[0] < NOTAMIN)|| (nota[1]) < NOTAMIN));
    
    //Calculo da Media
    media = (nota[0]*PESO0 + nota[1]*PESO1)/2;

    //Mostrar o valor da Media
    printf("MEDIA = %.1f/n",media);
       


}
