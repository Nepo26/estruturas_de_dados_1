int
maximo(ListaNo *Cabeca){
    ListaNo geral=Cabeca;
    
    No *nos  =  geral->cabeca; 
    No *temp = NULL;



    if(nos->proximo != NULL){
        if( (nos->item) >= (nos->proximo->item)){
            temp = nos->proximo;
            nos->proximo = temp->proximo;
        }
        else{
            geral->cabeca = nos->proximo;
        }
        maximo(geral);
    }

    return geral->cabeca->item;
}


