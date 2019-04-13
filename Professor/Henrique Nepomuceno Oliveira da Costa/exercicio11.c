//Exercicio 11 - Mundo "Feliz" (Todos que nao forem positivos serao descartados)
#include <stdio.h>

//Funcao de Substituicao
void sub(int *vetor){
    int i=0;

    for(i=0;i<10;i++){
    if(vetor[i]<=0)
        vetor[i]=1;
    }
      

}

void main(){

    int i=0, vetor[10];
    


    for(i=0;i<10;i++){
    scanf("%d",&vetor[i]);
    }
    
    sub(vetor);
    
    for(i=0;i<10;i++){
    printf("X[%d] = %d\n",i,vetor[i]);
    }
    
}
