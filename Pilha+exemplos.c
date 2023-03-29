#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    struct no * prox;
    float dado;
}no;

typedef struct pilha{
    struct no * primeiro;
    int tam;
}pilha;

void criar_pilha(pilha ** p);
int pilha_vazia(pilha** p,int flag);
void push_pilha(pilha ** p,float dado);
float pop_pilha(pilha ** p);
void mostra_topo(pilha ** p);
void tam_pilha(pilha ** p);

int main(){
    pilha *p;
    criar_pilha(&p);
    printf("\n");

    float vec_test[5]={1,2,3,4,5};
    for(int i = 0;i<5;i++){ // print nos valor do vetor
        printf("|%.2f|",vec_test[i]);
    }

    for(int i = 0;i<5;i++){ // empilhar os valor do vetor na pilha
        push_pilha(&p,vec_test[i]);
    }

    //float dado = pop_pilha(&p); // testando funçao pop da pilha para retonar topo da fila

    tam_pilha(&p); /// funçao pra mostrar tam da lita

    float dado;
    for(int i = 0;i<5;i++){ // desempilhar e mostar pilha
        mostra_topo(&p);
        pop_pilha(&p);
    }
  // caso tentar mostrar pilha vazia
    tam_pilha(&p);
    mostra_topo(&p);
    printf("dwdwdwdwdwd%.2f",dado);
}
void criar_pilha(pilha ** p){
    (*p) = (pilha *) malloc(sizeof(pilha));
    (*p)->primeiro = NULL;
    (*p)->tam=0;
    printf("pilha criada");
}

int pilha_vazia(pilha** p,int flag){
    if((*p)->primeiro == NULL){
        if(flag==1)
            printf("\npilha esta vazia");
        return 1;
    }
    else{
        return 0;
    }
}
void push_pilha(pilha ** p,float dado){
    no * pilha_aux = (no*) malloc(sizeof(no));
    pilha_aux->dado = dado;
    if (pilha_vazia(p,0))
    { 
        pilha_aux->prox = NULL;          //// caso pilha esteja vazia
        (*p)->primeiro = pilha_aux;
    }
    else
    {             ////// caso pilha nao esteja vazia
      pilha_aux->prox = (*p)->primeiro;
      (*p)->primeiro = pilha_aux;
    }
    (*p)->tam++; 
}
float pop_pilha(pilha ** p){
    if (pilha_vazia(p,1))
    { 
       exit(1);
    }
    no * pilha_aux;
    pilha_aux = (*p)->primeiro;
    (*p)->primeiro = pilha_aux->prox;
    float dado = pilha_aux->dado;
    free(pilha_aux);
    (*p)->tam--;
    return dado;

}
void mostra_topo(pilha ** p){
    if (pilha_vazia(p,1))
    { 
       exit(1);
    }
    float v;
    v = (*p)->primeiro->dado;
    printf("\nO topo da pilha eh o seguinte : %.2f",v);
}
void tam_pilha(pilha ** p){
    printf("\nTamanho atual da pilha : %d",(*p)->tam);
}
