//Exerci'cio 6 - Comparacao de substring
#include <stdio.h>
#include <string.h>

int compare_chars(char *str1,char *str2);

void main(){
    char palavra[2][51];

    scanf("%s %s",&palavra[0][0],&palavra[1][0]);

    printf("%d\n",compare_chars(&palavra[0][0],&palavra[1][0]));

                
}

//Funcao para comparacao de strings:
//Quando encontra 'chars'iguais dentro de strings diferentes comeca um contador
//esse que e' incrementado caso os 'chars' subsequentes sejam tambem comparti-
//lhados entres as diferentes strings.
int compare_chars(char *str1,char *str2){

    int i=0, j=0, max=0,qntd=0;
    int str_size[2];
    
    //Define o tamanho do array
    str_size[0]= strlen(str1);
    str_size[1]= strlen(str2);

    //Passando por cada string e as comparando
for(i=0; i<str_size[0]; i++){
    for(j=0; j<str_size[1]; j++){
    
        if(str1[i]==str2[j]){

        //Tirando o caso inicial, impedindo ter um 'i' ou 'j' < 0
        if(i!=0 && j!=0){

        //Vendo se ja houve algum "match" anterior, ou seja, se ele nao e' o primeiro da cadeia
        if( (str1[i]==str2[j-1]) || (str1[i-1]==str2[j-1]) ){
         qntd++;
        }
        else{
        qntd=1;
        continue;
        }

        //Compara a quantidade de "matches" atual com a maxima ja registrada
        if(qntd>max){
         max=qntd;
        }
         continue;
        }

    qntd++;
    }
    }
}
return max;
}
