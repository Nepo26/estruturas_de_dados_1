//Exerci'cio 10 - Bino e Cino 
#include <stdio.h>
#define TAMANHO 4

int multiplo(int valor,int *valores);
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

        //Levando-se em conta que estao em ordem crescente e nao tem o 1 na lista
        mult[multiplo(num,val)-2]++;
        printf("num=%d, multiplo=%d",num,multiplo(num,val));
    }

    for(i=0;i<TAMANHO;i++)
        printf("%d Multiplo(s) de %d\n",mult[i],val[i]);



}

//Calcula se o valor e' multiplo de dados valores
int multiplo(int valor, int *valores){
    //Teste inicial assumindo ser ordem crescente
    if(valores[0]==0)
        return 0;

    
    /*Declaracao de variaveis*/
    int qntd = sizeof(valores)/sizeof(int);
    int i=0;
    /*-----------------------*/
    
    
    //Caso seja multiplo retorna seu multiplo
    for(i=0;i<qntd;i++){
    if(valor%valores[i]==0)
        return valores[i];
    }

    return 0;
}
