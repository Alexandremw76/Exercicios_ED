// Aluno :  JOSE ALEXANDRE BEZERRA DE OLIVEIRA
// Matricula : 20190098030
#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 10

typedef struct lista {
    int elementos[TAM_MAX];
    int tamanho;
} Lista;

void criaLista(Lista *l);
int listaVazia(Lista l);
int listaCheia(Lista l);
int tamanhoLista(Lista l);
int obtemElemento(Lista l, int posicao);
void modificaElemento(Lista *l, int posicao, int valor);
int insereElemento(Lista *l, int posicao, int valor);
int removeElemento(Lista *l, int posicao);

int main() {
    Lista minhaLista;
    criaLista(&minhaLista);
    
    printf("Lista vazia: %d\n", listaVazia(minhaLista));
    printf("Lista cheia: %d\n", listaCheia(minhaLista));
    printf("Tamanho da lista: %d\n", tamanhoLista(minhaLista));
    
    insereElemento(&minhaLista, 0, 10);
    insereElemento(&minhaLista, 1, 20);
    insereElemento(&minhaLista, 2, 30);
    
    printf("Elemento na posição 1: %d\n", obtemElemento(minhaLista, 1));
    
    modificaElemento(&minhaLista, 1, 50);
    
    printf("Elemento na posição 1 após modificação: %d\n", obtemElemento(minhaLista, 1));
    
    removeElemento(&minhaLista, 1);
    
    printf("Elemento na posição 1 após remoção: %d\n", obtemElemento(minhaLista, 1));
    
    return 0;
}

void criaLista(Lista *l) {
    l->tamanho = 0;
}

int listaVazia(Lista l) {
    return (l.tamanho == 0);
}

int listaCheia(Lista l) {
    return (l.tamanho == TAM_MAX);
}

int tamanhoLista(Lista l) {
    return l.tamanho;
}

int obtemElemento(Lista l, int posicao) {
    return l.elementos[posicao];
}

void modificaElemento(Lista *l, int posicao, int valor) {
    l->elementos[posicao] = valor;
}

int insereElemento(Lista *l, int posicao, int valor) {
    if (listaCheia(*l) || posicao < 0 || posicao > l->tamanho) {
        return 0;
    }
    
    for (int i = l->tamanho - 1; i >= posicao; i--) {
        l->elementos[i+1] = l->elementos[i];
    }
    
    l->elementos[posicao] = valor;
    l->tamanho++;
    
    return 1;
}

int removeElemento(Lista *l, int posicao) {
    if (listaVazia(*l) || posicao < 0 || posicao >= l->tamanho) {
        return 0;
    }
    
    for (int i = posicao; i < l->tamanho - 1; i++) {
        l->elementos[i] = l->elementos[i+1];
    }
    
    l->tamanho--;
    
    return 1;
}
