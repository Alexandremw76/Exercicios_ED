#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* proximo;
    struct No* ant;

}No;

typedef struct ListaEncadeada {
    No* inicio;
    No * fim;
    int tamanho;
}ListaEncadeada;

void imprimirLista( ListaEncadeada* lista);
void criar_no(int num,No ** no);
void inseri_fim(int num,ListaEncadeada * list);
void criarListaEncadeada(ListaEncadeada **lista);
void inseri_ini(int num,ListaEncadeada * list);
void inseri_intervalor(int num,ListaEncadeada * list,int inter); // zero sera posiçao valida nessa funçao o ultimo elemenmto sera tamanho -1
void remover_intervalor(ListaEncadeada * list,int inter); // zero sera posiçao valida nessa funçao o ultimo elemenmto sera tamanho -1

int main()
{
    ListaEncadeada *l1;
    criarListaEncadeada(&l1);
    inseri_intervalor(1430,l1,0);
    inseri_intervalor(1450,l1,1);
    inseri_intervalor(145,l1,2);
    inseri_intervalor(231,l1,3);
    remover_intervalor(l1,3);
    remover_intervalor(l1,0);
    remover_intervalor(l1,1);
    imprimirLista(l1);
    printf("\ntamanho da lista : %d",l1->tamanho);
}

void criarListaEncadeada(ListaEncadeada **lista) {
    (*lista)=(ListaEncadeada *) malloc(sizeof(ListaEncadeada));
    (*lista)->inicio = NULL;
    (*lista)->fim = NULL;
    (*lista)->tamanho = 0;
}
void criar_no(int num,No ** no){
    (*no) = (No*) malloc(sizeof(no));
    (*no)->ant = NULL;
    (*no)->proximo = NULL;
    (*no)->dado = num;

}

void inseri_fim(int num,ListaEncadeada * list)
{
    No * novo_no;
    criar_no(num,&novo_no);

    if(list->inicio==NULL){
        list->inicio = novo_no;
        list->fim = list->inicio;
    }

    else{
        No * aux = list->fim ;
        list->fim->proximo = novo_no;
        list->fim = novo_no;
        list->fim->ant = aux;

    }
    list->tamanho++;

}
void inseri_ini(int num,ListaEncadeada * list)
{
    No * novo_no;
    criar_no(num,&novo_no);

    if(list->inicio==NULL){
        list->inicio = novo_no;
        list->fim = list->inicio;
    }

    else{

        novo_no->proximo = list->inicio;
        list->inicio->ant = novo_no;
        list->inicio = novo_no;

    }
    list->tamanho++;
}
void imprimirLista( ListaEncadeada* lista) {
    No* atual = lista->inicio;
    for(;atual!=NULL;atual= atual->proximo){
        printf("%d|",atual->dado);
    }
}
void inseri_intervalor(int num,ListaEncadeada * list,int inter){
    if (inter < 0 || inter > list->tamanho) {
        printf("Erro: posicao invalida!\n");
        exit(1);
    }
    if(inter == 0){
        inseri_ini(num,list);
    }
    else if ( inter==list->tamanho)
    {
        inseri_fim(num,list);
    }
    else{
        No * aux = list->inicio;
        for(int i = 0;i<inter-1;i++){
            aux = aux->proximo;
        }
        No * no_num;
        No * aux2=aux->proximo;
        criar_no(num,&no_num);
        no_num->proximo = aux2; 
        no_num->ant = aux;
        aux->proximo = no_num;
        aux2->ant = no_num;
        list->tamanho++;
    }
}
void remover_intervalor(ListaEncadeada * list,int inter){
    if (inter < 0 || inter > list->tamanho || list->inicio == NULL) {
        printf("Erro: posicao invalida!\n");
        exit(1);
    }
    if(inter == 0){
        No * aux = list->inicio;
        list->inicio=list->inicio->proximo;
        list->inicio->ant = aux->ant;
        if(list->tamanho == 1){
            list->fim = list->inicio;
        }
        free(aux);
    }
    else if(inter == list->tamanho-1){
        No * aux = list->fim;
        list->fim=list->fim->ant;
        list->fim->proximo = aux->proximo;
        if(list->tamanho == 1){
            list->inicio = list->fim;
        }
        free(aux);
    }
    else{
        No * aux = list->inicio;
        for(int i = 0;i<inter;i++){
            aux = aux->proximo;
        }
        No * aux2=aux->proximo;
        No * aux3 = aux->ant;
        aux3->proximo = aux2;
        aux2->ant = aux3;
        free(aux);
    }
    list->tamanho--;
}
