//Exerci'cio 10 - Bino e Cino 
#include <stdio.h>
#define TAMANHO 4

void multiplo(int valor, int *mult){
    if(valor%5==0)
        mult[3]++;
    if(valor%4==0)
        mult[2]++;
    if(valor%3==0)
        mult[1]++;
    if(valor%2==0)
        mult[0]++;
}

void main(){

/*Declaracao de varia'veis------*/    
    
    int i=0,n=0,num=0;

    //Mu'ltiplos de 2, 3, 4 e 5
    int mult[TAMANHO]={0,0,0,0};
    int val[TAMANHO]={2,3,4,5};

/*------------------------------*/
    
    //Atribuicao de valores baseado no 'input' do usua'rio

    //Quantidade de Linhas
    do{
        scanf("%d",&n);
    }while((n<1)||(n>1000));

    //Numeros de 'lista' Bino
    for(i=0;i<n;i++){    
        do{
        scanf("%d",&num);
        }while((n<1)||(n>100));

        multiplo(num,mult);
    }

    for(i=0;i<TAMANHO;i++)
        printf("%d Multiplo(s) de %d\n",mult[i],val[i]);



}
