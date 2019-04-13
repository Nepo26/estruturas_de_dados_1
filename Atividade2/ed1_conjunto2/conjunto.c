#include "conjunto.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct conjunto {
    /* elementos da estrutura */
    int *elemento;
    int ocpd;
    size_t max ; //Espaco ja alocado
};

conjunto_t *
conjunto_novo(void) {
    printf("asdf");
    /* aloca uma nova estrutura do tipo conjunto_t e inicializa os campos */
    conjunto_t *conj = (conjunto_t *) malloc(sizeof(conjunto_t));


    if(conj != NULL){
        conj->elemento = NULL;
        conj->ocpd = 0;
        conj->max = 50*sizeof(int);
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

//Encontra o elemento e retorna se o encontrou
bool
conjunto_encontra(conjunto_t *conj, int elemento){
    int i=0;
    for(i=0;i<(conj->max-1);i++)
        if(conj->elemento[i]==elemento)
            return true;

    return false;
}


bool
conjunto_contem(conjunto_t *conj, int elemento) {
    /* Percorre o vetor verificando se o elemento já foi incluso */
    int i=0;

    //Max Ou Ocpd ???
    for(i=0;i<(conj->ocpd);i++)
        if(conj->elemento[i]==elemento)
            return true;

    return false;
}

// Para diminuir a complexidade da função "conjunto_adiciona" foi criada
// uma função auxiliar encarregada de garantir que a quantidade de memó-
// ria alocada é suficiente.

bool
suficiente_memoria(conjunto_t *conj){

    if( conj->ocpd * sizeof(int)  == conj->max || conj->elemento==NULL){
        //conjunto_t *conj3 = conjunto_novo();
        // conjunto_t *conj3 = realloc(conj, sizeof(conjunto_t) + conj->max + 50*sizeof(int) );
        // Acreditava que caso nao alocado o conjunto todo, nao suportaria o realloc de "elementos"


        //Caso a funcao seja nula ele alocara
        int *elementos = realloc(conj->elemento, conj->max + 50*sizeof(int) ); //So...no casting of realloc ?

        //Para garantir que nao se perca dados no caso de erro na realocacao
        if(elementos != NULL){

            //    conj = conj3;

            conj->elemento = elementos ;
            conj->max = conj->max + 50 * sizeof(int);

            //Reajustando a alocacao do geral
            //free(elementos); //Uai? Vc tá liberando a memória que acabou de alocar!

            // conjunto_libera(conj3);
            return true;
        } else {
            return false;
        }
    }

    return true;
}



bool
conjunto_adiciona(conjunto_t *conj, int elemento) {
    int i=0;
    // Antes de tudo a função deve verificar se o elemento já foi adicionado.
    // Para isso é possível utilizar a função conjunto_contem()
    if(conjunto_contem(conj,elemento)){
        return true;
    }

    //Verifica se a quantidade de elementos restantes do vetor e' suficiente
    //se nao for , aloca mais memoria e retorna "true", caso nao haja mais
    //memoria suficiente para ser alocado retorna "false"
    if(suficiente_memoria(conj)){

        // Por fim, a função deve adicionar o elemento ao vetor
        conj->elemento[conj->ocpd]=elemento;
        conj->ocpd++;
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



//Encontra o elemento e retorna sua posicao
int
conjunto_encontra_posicao(conjunto_t *conj, int elemento){
    int i=0;
    for(i=0;i<(conj->ocpd);i++)
        if(conj->elemento[i]==elemento)
            return i;

    return -1;
}

bool
conjunto_remove(conjunto_t *conj, int elemento) {
    int loc=0;
    int i=0;

    loc = conjunto_encontra_posicao(conj,elemento);

    if (loc == -1)
        return false;


//    conj->elemento[conj->max] = conj->elemento[loc];

    for(i=loc;i<(conj->ocpd);i++){
        conj->elemento[i]=conj->elemento[i+1];
    }

    return true;
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

    for(i=0;i<(a->ocpd);i++)
        if(conjunto_contem(b,a->elemento[i]));
    sign=true;


    return sign;
}

const int *
conjunto_vetor(conjunto_t *conj) {
    int *vetor;

    vetor = conj->elemento;

    if(vetor != NULL)
        return vetor;

    return NULL;
}

void
conjunto_libera(conjunto_t *conj) {
    free(conj);
}
