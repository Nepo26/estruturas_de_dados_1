//Exerci'cio8 - Todos os valores entre 1 e 10000 que dao resto 2
#include <stdio.h>

#define VALOR_MIN 1
#define VALOR_MAX 10000
#define VALOR_TESTE 2

void main(){

    int n=-10, i=0; // G: Pq n começão com -10?

    //Atribuicao das variaveis inseridas pelo usuario
    do{
    scanf("%d",&n); // G: o problema garante que n vai ser sempre entre MIN e MAX, não é necessário verificar
    }while(n>VALOR_MAX || n<=VALOR_MIN);

    //Passa por cada valor entre VALOR_MIN e VALOR_MAX
    for(i=0; i<VALOR_MAX; i++){

        //Testa se o contador e' divisi'vel por VALOR caso seja imprime seu valor
// G: VALOR não foi declarado, o programa não compila!
        if(i%n==VALOR)
        printf("%d\n",i);
    }

}
