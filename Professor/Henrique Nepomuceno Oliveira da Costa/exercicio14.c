//Exercicio 14 - 

#include <stdio.h>


void main(){
int size =  12;

int i=0, j=0;
double m[size][size];
double soma=0, media=0;
char opera = 'a';

do{
    scanf("%c",&opera);
}while((opera!='S')&&(opera!='M'));

for(i=0;i<size;i++)
    for(j=0;j<size;j++)
    scanf("%lf",&m[i][j]);

if(opera=='S'){
for(i=1;i=j;i++)
    for(j=11;i=j;j--){
    soma+=m[i][j];
    if(i=j)
        break;
    }

printf("%.1lf\n",soma);
}
else{
for(i=1;i=j;i++)
    for(j=11;i=j;j--){
    soma+=m[i][j];
    if(i=j)
        break;
    }


media=soma/size;
printf("%.1lf\n",media);
}

}


