#include <stdio.h>
#include <string.h>

void strtrim(char *destino, char *origem){
    
    int i=0, times=0;
    int tam = strlen(origem);
    printf("%d\n",tam);
   
    for(i=0;i<tam;i++){
        if(origem[i]=='\0'){
            if(i==tam)
            break;
        continue;
        }
        else{ 
           destino[times]=origem[i];
           times++;
        }
    }
    printf("%d\n",strlen(destino));
}  

void main(){

char destino[51], origem[51];

fgets(origem,51,stdin);

strtrim(destino,origem);

printf("%s\n",destino);

}
