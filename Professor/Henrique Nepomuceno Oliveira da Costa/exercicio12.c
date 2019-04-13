//Exercicio 11 - Fibonacci em vetor
#include <stdio.h>


unsigned long int getFibo(int n, unsigned long int *vetor){
    int i=0,pos=2;

    // G: a cada vez que a função é chamada o fibonacci é calculado novamente a partir da posição 2. A solução correta seria manter a posição até onde foi calculado na chamada anterior e continuar a partir desse ponto
    for(pos=2; pos<=n; pos++){
    vetor[pos] = vetor[pos-1]+vetor[pos-2];
    }
    return vetor[n];
}

void main(){
    int i=0,t=0,n=0;
    unsigned long int vetor[60]; 
    vetor[0]=1;
    vetor[1]=1;
    //Quantidade de casos de teste
    scanf("%d",&t);
    
    for(i=0;i<t;i++){
        do{
        scanf("%d",&n);
        }while((n<0)||(n>60));
        printf("\nFib(%d) = %lu\n",n,getFibo(n,vetor));
        }
    


}
