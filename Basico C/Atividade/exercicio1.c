#include <stdio.h>
#include <string.h>

void strtrim(char *destino, char *origem){
    
    int i=0, times=0;
    int tam = strlen(origem);
    int vaz_antes = 0, vaz_depois = 0;

    for(i=0;i<tam;i++){
        if(!(origem[i]=='\0'||origem[i]==' '||origem[i]=='\r'||origem[i]=='\v'||origem[i]=='\f'||origem[i]=='\r'))
            break;
    vaz_antes+=1;
    }

    for(i=tam-1;i>0;i++){
        if(!(origem[i]=='\0'||origem[i]==' '||origem[i]=='\r'||origem[i]=='\v'||origem[i]=='\f'||origem[i]=='\r'))
            break;
    vaz_depois+=1;
    
    }
    for(i=vaz_antes;i<tam-(vaz_depois+1);i++){
           destino[times]=origem[i];
           times++;
    }
    printf("%d\n",strlen(destino));
}  

void main(){

char destino[51], origem[51];

fgets(origem,51,stdin);

strtrim(destino,origem);

printf("%s||\n",destino);

}
