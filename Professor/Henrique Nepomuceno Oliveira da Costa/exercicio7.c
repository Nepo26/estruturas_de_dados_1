//Exerci'cio 7 - Ordenacao de pares e impares
#include <stdio.h>
#include <math.h>


int isEven(unsigned long int n){

    printf("Entrando...Even\n"); //

    if(n%2==0)
        return 1;
    else
        return 0;
}
// G: correto, mas seria bem mais simples da seguinte forma:
int isEven(unsigned long int n) {
    return n % 2 == 0;
}
// G: mais simples ainda, vc poderia definir uma macro
#define IS_EVEN(x) ((x) % 2 == 0)


// G: é uma boa prática utilizar uma mesma convenção de nomenclatura, se vc utilizou a função isEven (camel case) poderia nomear essa de dataPut, ou trocar isEven por is_even
//Funcao que ordena os inteiros que entram 
void data_put(unsigned long int *undefined,int inserted,int total){
    
    int even = isEven(undefined[total]);
    
    printf("Entrando data_put\n"); //
    
    total -= 1 ;

    if(inserted==0){
    undefined[inserted]=undefined[total];
    }
    else{
      //Caso seja par ele ordena de forma crescente
        if(even){
            printf("Primeiro Teste \n");//
            if( undefined[total] <= undefined[inserted] ){
            printf("Original...\n");//
            undefined[inserted+1]=undefined[total];
            }
            else
            {
            printf("Else_ \n");//
            undefined[inserted+1]=undefined[inserted];
            undefined[inserted]=undefined[total];
            }
        }
        //Caso impar ele ordena de forma decrescente
          else{
          
          }
    }
}

void main(){
    //Para conseguir armazenas valores ate' a ordem de 10^5 declare-se como "unsigned long int"
    unsigned long int lines=0;
    unsigned long int number[lines]; // G: lines = 0 nesse ponto, pq alocar um vetor de tamanho 0?

    number[lines] = 0; // G: comportamento indefinido, o vetor tem tamanho 0
    number[0];
    int i=0, stop=0; 

    do{
       scanf("%d",&lines);
    }while( (lines <= 1) || (lines>=pow(10,5)) );


    for(i=0;i<lines;i++){
     scanf("%lu",&number[lines]);
printf("Mioloi\n");//
     data_put(number,i,lines);
    }

    for(i=0;i<lines;i++){
    printf("%lu\n",number[i]);
    }

}
