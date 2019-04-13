//Exercicio 5 - Idade em dias
#include <stdio.h>

//Definicao  de constantes representando o valor de um ano e de um mes
#define ANO 365
#define MES 30

void main(){
    
    //Declaracao de Variaveis
    unsigned int dias=0, meses=0, anos=0;

    //Atribui valor a variavel dias com base na entrada do usuario
    scanf("%d",&dias);

    //A quantidade de anos e' equivalente 'a quantidade de dias dividido pela constante "ANO"
    anos = dias/ANO;

    //Retira-se a quantidade de dias equivalente a quantidade anos  da quantidade de dias total para se efetuar mais divisoes
    dias -= anos*ANO;

    //A quantidade de meses restantes e' equivalente 'a quantidade restante de dias dividida pela constante "MES"
    meses = dias/MES;

    //Retira-se a quantidade de dias equivalentes 'a quantidade de meses da quantidade de dias para que se sobrem somente a quantidade de dias restante
    dias -= meses*MES;

    printf("%d ano(s)\n",anos);
    printf("%d mes(es)\n",meses);
    printf("%d dia(s)\n",dias);

    
   
}
