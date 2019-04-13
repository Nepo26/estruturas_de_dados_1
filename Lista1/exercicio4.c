//Exerci'cio 4 - Quantidade Minima de Cedulas
#include <stdio.h>


void main(){

    unsigned int notas[2][7] ={ {100,50,20,10,5,2,1},{0,0,0,0,0,0,0} };
    unsigned int total = 0, temp = 0;
    int i;
    
    //Pega o valor total
    scanf("%d",&total);


    printf("%d\n",total);
    for(i=0; i<7; i++){
        //A fim de se ter o maximo possivel de uma nota deve-se dividir o "valor total" pelo "valor da nota"
        notas[1][i]=total/notas[0][i];

        //Tem que ser modificado o valor total para que possa ser novamente dividido
        total -= notas[1][i]*notas[0][i];
        printf("%d nota(s) de R$%d,00\n",notas[1][i],notas[0][i]);
    }

}
