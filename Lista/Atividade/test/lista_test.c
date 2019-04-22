#include "lista.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

static void
init_vetor_aleatorio(int *itens, size_t qtd) {
    for (int i = 0; i < qtd; i++)
        itens[i] = rand() % qtd;
}


static void
print_lista(Lista *lista) {
    const int *vetor = lista_vetor(lista);
    size_t n = lista_qtd_itens(lista);

    for (int i = 0; i < n; i++)
        printf("%d ", vetor[i]);
    puts("");
}

static void
test_lista_novo(void) {
    Lista *lista = lista_novo();
    assert(lista != NULL);
    assert(0 == lista_qtd_itens(lista));

    lista_libera(lista);


    int vetor_inicial[] = {2, 5, 2, 3, 4, 3};
    lista = lista_novo_lendo_vetor(vetor_inicial, 6);
    assert(4 == lista_qtd_itens(lista));

    lista_libera(lista);
}

static void
test_lista_contem(void) {
    Lista *lista = lista_novo();

    int itens[1024];
    init_vetor_aleatorio(itens, 1024);

    for (int i = 0; i < 1024; i++) {
        lista_adiciona(lista, itens[i]);
        assert(lista_contem(lista, itens[i]));
    }

    for (int i = 0; i < 1024; i++) {
        assert(lista_contem(lista, itens[i]));
    }

    for (int i = 0; i < 1024; i++) {
        lista_remove(lista, itens[i]);
        assert(!lista_contem(lista, itens[i]));
    }

    lista_libera(lista);
}


static void
test_lista_adiciona_remove(void) {
    Lista *lista = lista_novo();

    lista_adiciona(lista, 10);
    assert(lista_contem(lista, 10));

    lista_adiciona(lista, 20);
    assert(lista_contem(lista, 20));

    assert(!lista_contem(lista, 15));
    assert(2 == lista_qtd_itens(lista));

    assert(!lista_remove(lista, 15));
    assert(2 == lista_qtd_itens(lista));

    assert(lista_remove(lista, 10));
    assert(1 == lista_qtd_itens(lista));

    assert(!lista_remove(lista, 10));
    assert(1 == lista_qtd_itens(lista));

    assert(lista_remove(lista, 20));
    assert(0 == lista_qtd_itens(lista));

    lista_libera(lista);
}

static void
test_lista_iguais(void) {
    int itens[1024];
    init_vetor_aleatorio(itens, 1024);

    Lista *a = lista_novo_lendo_vetor(itens, 1024);
    Lista *b = lista_novo();
    for (int i = 1024 - 1; i >= 0; i--)
        lista_adiciona(b, itens[i]);

    assert(lista_iguais(a, b));

    lista_libera(a);
    lista_libera(b);

    a = lista_novo();
    lista_adiciona(a, 10);
    lista_adiciona(a, 10);
    lista_adiciona(a, 20);
    lista_adiciona(a, 30);

    b = lista_novo();
    lista_adiciona(b, 20);
    lista_adiciona(b, 30);
    lista_adiciona(b, 20);
    lista_adiciona(b, 10);

    assert(lista_iguais(a, b));

    lista_libera(a);
    lista_libera(b);


    a = lista_novo();
    lista_adiciona(a, 10);
    lista_adiciona(a, 20);

    b = lista_novo();
    lista_adiciona(b, 10);
    lista_adiciona(b, 20);
    lista_adiciona(b, 30);

    assert(!lista_iguais(a, b));

    lista_libera(a);
    lista_libera(b);

    a = lista_novo();
    lista_adiciona(a, 10);
    lista_adiciona(a, 20);
    lista_adiciona(a, 30);

    b = lista_novo();
    lista_adiciona(b, 10);
    lista_adiciona(b, 20);

    assert(!lista_iguais(a, b));

    lista_libera(a);
    lista_libera(b);

}

static void
test_lista_interseccao(void) {
    int itens_a[] = {10, 20, 30, 40, 50};
    Lista *a = lista_novo_lendo_vetor(itens_a, 5);

    int itens_b[] = {10, 30, 50, 60, 70};
    Lista *b = lista_novo_lendo_vetor(itens_b, 5);

    Lista *c = lista_intersecao(a, b);
    assert(3 == lista_qtd_itens(c));
    assert(lista_contem(c, 10));
    assert(lista_contem(c, 30));
    assert(lista_contem(c, 50));

    lista_libera(a);
    lista_libera(b);
    lista_libera(c);
}

static void
test_lista_uniao(void) {
    int itens_a[] = {10, 20, 30, 40, 50};
    Lista *a = lista_novo_lendo_vetor(itens_a, 5);

    int itens_b[] = {10, 30, 50, 60, 70};
    Lista *b = lista_novo_lendo_vetor(itens_b, 5);

    Lista *c = lista_uniao(a, b);
    assert(7 == lista_qtd_itens(c));
    assert(lista_contem(c, 10));
    assert(lista_contem(c, 20));
    assert(lista_contem(c, 30));
    assert(lista_contem(c, 40));
    assert(lista_contem(c, 50));
    assert(lista_contem(c, 60));
    assert(lista_contem(c, 70));

    lista_libera(a);
    lista_libera(b);
    lista_libera(c);
}


int
main(void) {
    test_lista_novo();
    test_lista_contem();
    test_lista_adiciona_remove();
    test_lista_iguais();
    test_lista_interseccao();
    test_lista_uniao();

    return 0;
}
