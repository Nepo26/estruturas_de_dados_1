typedef struct lista_no lista_no_t;
struct lista_no {
  int item;
  lista_no_t *proximo;
};

typedef struct {
  lista_no_t *cabeca;
  size_t tamanho;
} lista_t;

#define lista_tamanho(l) ((l)->tamanho)
#define lista_vazia(l) ((l)->tamanho == 0)
#define lista_no_inicio(l) ((l)->cabeca)

void
lista_adiciona(lista_t *lista, int item){
    lista_no_t *no = lista->cabeca;
    lista_no_t *add = malloc(sizeof(lista_no_t));

    if(no==NULL){
        no = add; 

        no->item=item;
        no->proximo = NULL;

        lista->tamanho = 1; // Caso colocasse ++ tinha risco de ja ter algo ? ? Nao sei, cansado...
    }
    else {
        no->item = item;
        no->proximo = 
        lista->tamanho++;
    
    }


}

int
lista_obtem(lista_t *lista, int posicao) {
  assert(posicao < lista_tamanho(lista));

  lista_no_t *no = lista->cabeca;
  while (posicao-- > 0)
    no = no->proximo;

  return no->item;
}

int
lista_remove_inicio(lista_t *lista) {
  assert(lista->cabeca != NULL);

  lista_no_t *temp = lista->cabeca;
  lista->cabeca = temp->proximo;
  int result = temp->item;
  free(temp);
  return result;
}

int
lista_remove(lista_t *lista, size_t posicao) {
  if (posicao == 0)
    return lista_remove_inicio(lista);

  No *anterior = lista->cabeca;
  while (--posicao > 0)
    anterior = anterior->proximo;

  lista_no_t *temp = anterior->proximo;
  anterior->proximo = temp->proximo;
  int result = temp->item;
  free(temp);

  return result;
}

