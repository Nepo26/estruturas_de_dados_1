#include <stdio.h>
#include <stdlib.h>

typedef struct no_int NoInt;
struct no_int {
    int item;       // valor armazenado no nó
    NoInt *proximo; // ponteiro para o nó seguinte
};

NoInt *
no_int_novo(int item, NoInt *proximo) {
    NoInt *no = malloc(sizeof(NoInt));

    no->item = item;
    no->proximo = proximo;

    return no;
}

NoInt *
no_int_adiciona_inicio(NoInt *cabeca, int item) {
    return no_int_novo(item, cabeca);
}

NoInt *
no_int_adiciona_fim(NoInt *cabeca, int item) {
    if (cabeca == NULL)
        return no_int_adiciona_inicio(cabeca, item);

    NoInt *no = cabeca;

    while (no->proximo != NULL)
        no = no->proximo;

    no->proximo = no_int_novo(item, NULL);

    return cabeca;
}

NoInt *
no_int_adiciona(NoInt *cabeca, int posicao, int item) {
  if (cabeca == NULL)
      return no_int_adiciona_inicio(cabeca, item);

  NoInt *no = cabeca;

  while (no->proximo != NULL && posicao-- > 0)
      no = no->proximo;

  no->proximo = no_int_novo(item, NULL);

  return cabeca;
}

NoInt *
no_int_remove_inicio(NoInt *cabeca) {
    if (cabeca == NULL)
        return NULL;

    NoInt *temp = cabeca;
    cabeca = cabeca->proximo;
    free(temp);

    return cabeca;
}

size_t
lista_no_tamanho(ListaNo *cabeca) {
    if (cabeca == NULL)
        return 0;

    return 1 + lista_no_tamanho(cabeca->proximo);
}

NoInt*
no_int_obtem(NoInt *cabeca, int posicao){
    NoInt *no = cabeca;

    while(no != NULL){
    no=no->proximo;
    if(posicao-- == 0)
        return no;
    }
    
    return NULL;
}

NoInt*
no_int_inverte(NoInt *cabeca){

    NoInt *temp=NULL;
    NoInt *nova_cabeca;

    while(cabeca!=NULL){
    if(temp==NULL) {
    temp=cabeca;
    cabeca=cabeca->proximo;
    temp->proximo=NULL;

    continue;
    }
   
    nova_cabeca=temp;
    temp = cabeca;
    cabeca=cabeca->proximo;
    
    temp->proximo=nova_cabeca;
    }

    return nova_cabeca;
}

NoInt*
no_int_filtro(NoInt* cabeca, int valor_filtrado){
    NoInt* temp;
    NoInt* anterior = NULL;
    NoInt* no = cabeca ;    
    

    while(no != NULL){
    if(no->item==valor_filtrado){
        if(anterior == NULL){
            no=no->proximo;
            cabeca = no;
            continue;
        }
        
        no=no->proximo;
        anterior->proximo=no;
    }
    anterior=no;
    }
    
    return cabeca;
}
