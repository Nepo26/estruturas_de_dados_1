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
    unsigned long int number[lines];

    number[lines] = 0;
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
