//Exercicios 13 - Linha de matriz

#include <stdio.h>

void main(){

    int linha=0,i=0, j=0;
    double m[12][12]; //Matriz "provedora"
    double soma=0, media=0;
    char opera = 'a';

    //Recebendo input de usua'rio e atribuindo seus valores 'as varia'veis
    do{
    scanf("%d",&linha);
    }while((linha<0)||(linha>11));

    do{
    scanf("%c",&opera);
    }while((opera!='S')&&(opera!='M'));

    for(i=0;i<12;i++)
        for(j=0;j<12;j++)
            scanf("%lf",&m[i][j]);

    if(opera == 'S'){
        for(i=0;i<12;i++)
        soma+=m[linha][i];

        printf("%.1lf\n",soma);
    }
    else{
        for(i=0;i<12;i++)
        soma+=m[linha][i];

        media=soma/12;
        printf("%.1lf\n",media);
    }





}
