//Exerci'cio 9 - Quadrado e ao cubo
#include <stdio.h>

void main(){

//Declaracao de varia'veis
unsigned int n=0;
int i=0;

//Recebimento da entrada do usua'rio
do{
scanf("%d",&n);
}while((n<1)||(n>1000));
    
//Passa por cada valor entre 1 e 'n' e printa seu quadrado e seu cubo ao lado de seu valor
for(i=1;i<=n;i++)
printf("%u %u %u\n",i,i*i,i*i*i);

}
