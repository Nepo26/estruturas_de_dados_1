#include <stdio.h>
#include "pilha_encadeada"

char
letra_ou_digito(int carac){
    if(carac >= 'A' && carac <= 'Z')
        return 'L';
    if(carac >= '0' && carac <= '9')
        return 'D';

    return NULL;
}


void
posfixa(char* cad_carac){
   Pilha valores = pilha_nova(); 
   
   while(cad_carac != '\0'){
    
   }

} 

char*
le_simbolo(*op){


}

char*
concatena(char* t1, char* t2){


}

int
prioridade(int operador){
    if(operador == '+' || operador == '-' ) //Operadores de prioridade "1"
        return 1;
    if(operador == '*' || operador == '/') //Operadores de prioridade "2"
        return 2;

    return 0; //Caso ainda nao implementado o operador 
}

char*
infixa_para_posfixa( char *infixa  ) {
  Pilha pilha = pilha_nova();
  char* posfixa = "";

  char simbolo = NULL;
  char opr = NULL;


  while (simbolo = le_simbolo(infixa)) {
    if (letra_ou_digito(simbolo)=='L') { //Define se e' operando ??
      concatena(posfixa, simbolo)
    } else if (simbolo == '(') {
      empilha(pilha, simbolo)
    } else if (simbolo == ')') {
      // desempilha todos operadores e adiciona à saída até encontrar '('
      while ((opr = desempilha(pilha)) != '(')
        concatena(posfixa, opr)    
    } else { // símbolo é um operador
      // desempilha todos operadores e adiciona à saída até encontrar um operador
      // de prioridade menor ou parênteses
      while (!vazia(pilha)) {
        opr = topo(pilha)
        if (opr != '(' && prioridade(opr) > prioridade(simbolo)) {
          concatena(posfixa, desempilha(opr))
        } else {
          break
        }
      }
      empilha(simbolo)
    }
  }

  while (!vazia(pilha))
    concatena(posfixa, desempilha(pilha))
}

