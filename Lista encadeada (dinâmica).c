// Aluno :  JOSE ALEXANDRE BEZERRA DE OLIVEIRA
// Matricula : 20190098030


#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* proximo;
}No;

typedef struct ListaEncadeada {
    struct No* inicio;
    int tamanho;
}ListaEncadeada;


ListaEncadeada* criarListaEncadeada();
int listaVazia(struct ListaEncadeada* lista);
int tamanhoLista(struct ListaEncadeada* lista);
int obterValor(struct ListaEncadeada* lista, int posicao);
void modificarValor(struct ListaEncadeada* lista, int posicao, int valor);
void inserirElemento(struct ListaEncadeada* lista, int posicao, int valor);
void removerElemento(struct ListaEncadeada* lista, int posicao);
void imprimirLista(struct ListaEncadeada* lista);




int main(){

    ListaEncadeada *l1;

    // cria lista vazia
    l1 = criarListaEncadeada();


    ////insere 4 elementos///// o intervalo de inserçao e remoçao começa em 1
    // 0 sera uma posiçao invalida
    inserirElemento(l1,1,0);
    inserirElemento(l1,2,1);
    inserirElemento(l1,3,2);
    inserirElemento(l1,4,3);
    //////////////////////////

    removerElemento(l1,3);// remove elemento da posiçao 3
    modificarValor(l1,1,0); // modifica da posiçao 1 elemento
    imprimirLista(l1);


    printf("\n%d",obterValor(l1,1));
    printf("\n%d",obterValor(l1,3));
    printf("\ntamanaho da lista : %d",tamanhoLista(l1));


}



ListaEncadeada* criarListaEncadeada() {
    struct ListaEncadeada* lista =(struct ListaEncadeada*)malloc(sizeof(struct ListaEncadeada));
    lista->inicio = NULL;
    lista->tamanho = 0;
    return lista;
}

int listaVazia(struct ListaEncadeada* lista) {
    return lista->tamanho == 0;
}

int tamanhoLista(struct ListaEncadeada* lista) {
    return lista->tamanho;
}

int obterValor(struct ListaEncadeada* lista, int posicao) {
    posicao --; // posiçao -1 em todas as funçoes para encaixar com o tamanho do array
    if (posicao < 0 || posicao >= lista->tamanho) {
        printf("Erro: posicao invalida!\n");
        exit(1);
    }

    struct No* atual = lista->inicio;
    for (int i = 0; i < posicao; i++) {
        atual = atual->proximo;
    }

    return atual->dado;
}

void modificarValor(struct ListaEncadeada* lista, int posicao, int valor) {
    posicao --;
    if (posicao < 0 || posicao >= lista->tamanho) {
        printf("Erro: posicao invalida!\n");
        exit(1);
    }

    struct No* atual = lista->inicio;
    for (int i = 0; i < posicao; i++) {
        atual = atual->proximo;
    }

    atual->dado = valor;
}

void inserirElemento(struct ListaEncadeada* lista, int posicao, int valor) {
    posicao --;
    if (posicao< 0 || posicao > lista->tamanho) {
        printf("Erro: posicao invalida!\n");
        exit(1);
    }

    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->dado = valor;

    if (posicao == 0) {
        novoNo->proximo = lista->inicio;
        lista->inicio = novoNo;
    } else {
        struct No* anterior = lista->inicio;
        for (int i = 0; i < posicao - 1; i++) {
            anterior = anterior->proximo;
        }
        novoNo->proximo = anterior->proximo;
        anterior->proximo = novoNo;
    }

    lista->tamanho++;
}

void removerElemento(struct ListaEncadeada* lista, int posicao) {
    posicao --;
    if (posicao < 0 || posicao >= lista->tamanho) {
        printf("Erro: posicao invalida!\n");
        exit(EXIT_FAILURE);
    }

    struct No* removido;
    if (posicao == 0) {
        removido = lista->inicio;
        lista->inicio = lista->inicio->proximo;
    } else {
        struct No* anterior = lista->inicio;
        for (int i = 0; i < posicao - 1; i++) {
            anterior = anterior->proximo;
        }
        removido = anterior->proximo;
        anterior->proximo = removido->proximo;
    }

    free(removido);
    lista->tamanho--;
}

void imprimirLista(struct ListaEncadeada* lista) {
    struct No* atual = lista->inicio;
    for(;atual!=NULL;atual= atual->proximo){
        printf("%d|",atual->dado);
    }
}