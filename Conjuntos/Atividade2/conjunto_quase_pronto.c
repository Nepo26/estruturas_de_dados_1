#include "conjunto.h"
#include <stdlib.h>
#include <assert.h>

#define NELEM(x) = (sizeof(x)/sizeof(x[0]))

typedef struct conjunto conjunto_t;

struct conjunto {
    /* elementos da estrutura */
    //int *elemento = (int *) malloc(50 * sizeof(int));
    int *elemento;
    int ocpd;
    size_t max ;
};

conjunto_t *
conjunto_novo(void) {
    /* aloca uma nova estrutura do tipo conjunto_t e inicializa os campos */
    conjunto_t *conj = (conjunto_t *) malloc(sizeof(conjunto_t));
    
    if(conj != NULL){
    conj->elemento=NULL;
    conj->ocpd=0;
    conj->max=50;

    return conj;
    }



    return NULL; // Quando nao se aloca??
}

conjunto_t *
conjunto_novo_lendo_vetor(int *vetor, size_t qtd) {
    int i=0;
    conjunto_t *conj = conjunto_novo();
    if (conj == NULL)
        return NULL;

    for (i = 0; i < qtd; i++) {
        // Se não consegue adicionar é pq não foi possível alocar memória
        // nesse caso libera o que já foi alocado na chamada conjunto_novo()
        // e retorna NULL
        if (!conjunto_adiciona(conj, vetor[i])) {
            conjunto_libera(conj);
            return NULL;
        }
    }

    return conj;
}
 
   
bool
conjunto_contem(conjunto_t *conj, int elemento) {
    /* Percorre o vetor verificando se o elemento já foi incluso */
    int i=0;

    for(i=0;i<(conj->ocpd-1);i++)
        if(conj->elemento[i]==elemento)
            return true;

    return false;
}

// Para diminuir a complexidade da função "conjunto_adiciona" foi criada
// uma função auxiliar encarregada de garantir que a quantidade de memó-
// ria alocada é suficiente.

bool
suficiente_memoria(conjunto_t *conj){

    if( conj->ocpd  == conj->max || conj->elemento==NULL){
        conjunto_t *conj2 = conjunto_novo(); 
//        conjunto_t *conj3 = conjunto_novo(); 
        
        //Caso a funcao seja nula ele alocara 
//        conj3 = realloc(conj,2*sizeof(conjunto_t));
        conj2->elemento = realloc(conj->elemento,conj->max+50*sizeof(int)); //So...no casting of realloc ?
        
        //Para garantir que nao se perca dados no caso de erro na realocacao
        if(conj2->elemento != NULL){
//            conj=conj3;
            conj->elemento = conj2->elemento ;
            conj->max=conj->max+50;
        
        //Reajustando a alocacao do geral
        
            free(conj2);
            return true;
        }

    }
}



bool
conjunto_adiciona(conjunto_t *conj, int elemento) {
    int i=0;
    // Antes de tudo a função deve verificar se o elemento já foi adicionado.
    // Para isso é possível utilizar a função conjunto_contem()
    if(conjunto_contem(conj,elemento)){
        return true;
    }
    
   //Verifica se a quantidade de elementos restantes o vetor e' suficiente
   //se nao for aloca mais memoria e retorna "true", caso nao haja mais 
   //memoria suficiente retorna "false"
   if(suficiente_memoria(conj)){
    
    // Por fim, a função deve adicionar o elemento ao vetor
    conj->elemento[(conj->ocpd)]=elemento;
    conj->ocpd+=1;
    return true;
   }

   return false;


    //Adicionar de forma aleatoria ? Como ?
    //
    //Ao que parece sequencial ja esta de bom tamanho
    // 

}



//O ultimo elemento e' usado como "descarte", e' copiado o 
//elemento que sera descartado para a ultima posicao e os
//outros elementos acima da sua posicao serao movidos para
//a posicao anterior a deles.
//
//
//
//Desperdicio de processamento ??


//Encontra o elemento e retorna se o encontrou
bool
conjunto_encontra(conjunto_t *conj, int elemento){
    int i=0;
    for(i=0;i<conj->max-1;i++)
        if(conj->elemento[i]==elemento)
            return true;

    return false;
}

//Encontra o elemento e retorna sua posicao
int
conjunto_encontra_posicao(conjunto_t *conj, int elemento){
    int i=0;
    for(i=0;i<conj->max-1;i++)
        if(conj->elemento[i]==elemento)
            return i;

    return 0;
}

bool
conjunto_remove(conjunto_t *conj, int elemento) {
    int loc=0;
    int i=0;

    loc = conjunto_encontra_posicao(conj,elemento);
    

    conj->elemento[conj->max] = conj->elemento[loc]; 

    for(i=loc;i<conj->max-1;i++){
        conj->elemento[i]=conj->elemento[i+1];
    }
    
    if(conjunto_encontra(conj,elemento) != false)
        return true;

    return false;
}


size_t
conjunto_qtd_itens(conjunto_t *conj) {
    return conj->ocpd;
}

/**
  Retorna um novo conjunto cujos elementos são a interseccao entre os conjuntos a e b.
  Retorna NULL se não consegue alocar memória para o novo conjunto
*/
conjunto_t *
conjunto_intersecao(conjunto_t *a, conjunto_t *b) {
    int i=0;
    conjunto_t *intersecao = conjunto_novo();

    if(a->ocpd > b->ocpd)
        for(i=0;i<a->ocpd;i++)
            if(a->elemento[i]==b->elemento[i])     
                if(conjunto_adiciona(intersecao,a->elemento[i])==false)
                    return NULL;
    else
        for(i=0;i<b->ocpd;i++)
            if(a->elemento[i]==b->elemento[i])
                if(conjunto_adiciona(intersecao,a->elemento[i])==false)
                    return NULL;

                

    if(intersecao != NULL) 
        return intersecao;

    return NULL;
}

/**
  Retorna um novo conjunto cujos elementos são a união entre os conjuntos a e b.
  Retorna NULL se não consegue alocar memória para o novo conjunto
*/
conjunto_t *
conjunto_uniao(conjunto_t *a, conjunto_t *b) {
    conjunto_t *uniao = conjunto_novo();

    // Obtem os elementos do vetor a e adiciona na uniao
    const int *vetor_a = conjunto_vetor(a);
    size_t qtd_a = conjunto_qtd_itens(a);

    for (int i = 0; i < qtd_a; i++) {
        // Se não for possível adicionar um elemento é porque não há memória
        // e portanto deve ser liberada a que já foi alocada
        if (!conjunto_adiciona(uniao, vetor_a[i])) {
            conjunto_libera(uniao);
            return NULL;
        }
    }

    // Faz a mesma coisa para o vetor b
    // Como essas duas partes fazem a mesma coisa, poderiam ser extraídas
    // para uma função
    const int *vetor_b = conjunto_vetor(b);
    size_t qtd_b = conjunto_qtd_itens(b);

    for (int i = 0; i < qtd_b; i++) {
        if (!conjunto_adiciona(uniao, vetor_b[i])) {
            conjunto_libera(uniao);
            return NULL;
        }
    }

    return uniao;
}

bool
conjunto_iguais(conjunto_t *a, conjunto_t *b) {
    // Se os dois conjuntos tem tamanhos diferentes já é possível saber que são
    // diferentes. Em seguida é possível utilizar a função conjunto_contem para
    // verificar se os elementos de um conjunto estão incluídos no outro
    int i=0,j=0;
    bool sign=false;

    if(a->ocpd != b->ocpd)
        return sign;
    
    for(i=0;i<a->ocpd;i++)
        if(conjunto_contem(b,a->elemento[i]));
           sign=true; 
            
    
    return sign;
}

const int *
conjunto_vetor(conjunto_t *conj) {
    return NULL;
}

void
conjunto_libera(conjunto_t *conj) {
    free(conj);
}
