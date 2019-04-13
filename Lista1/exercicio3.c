//Exercicio 3 - Programa para efetuar equacao de bhaskara
//x`  = (b^2+(b^2-4*a*c))/(2*a) 
//x`` = (b^2-(b^2-4*a*c))/(2*a) 

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void main(){
    
    //Criacao de variaveis e atribuicao de valores as mesmas
    double a=1.0, b=1.0, c=1.0, delta=1.0;
    double x[2] = {0.0,0.0};
    bool flag = true;
    

    //Atribuicao de valores as variaveis a partir da entrada do usuario
    scanf("%lf %lf %lf",&a,&b,&c);
    
    //Um condicional que testa se "a" e zero, caso o seja ja termina o programa e informa que nao e' possivel calcular
    if(a==0){
        puts("Impossivel Calcular !!");
    }
    else{ 

        //Calculo de Delta
        delta = ( pow(b,2) - 4*a*c );

        if (delta!=0)
         if (delta > 0){
             //Quando Delta e' diferente de zero e positivo
            x[0] = ( b + sqrt(delta) )/(2.0*a);
            x[1] = ( b - sqrt(delta) )/(2.0*a);
         }
         else{
            //Quando Delta e' negativo
            puts("Impossivel Calcular !!");
         }
        else{
            //Quando Delta e' igual a zero
            x[0] = ( b + 1 )/(2.0*a);
            x[1] = ( b - 1 )/(2.0*a);
        }
        
        //Mostrando os resultados
        printf("R1 = %.5f\nR2 = %.5f\n",x[1],x[0]);
    }






}
