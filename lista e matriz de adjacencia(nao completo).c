
#include <stdio.h>
#include <stdlib.h>
typedef struct matriz_adjacecia
{
    int** matriz;
    int vertices;
}matriz_adjacecia;

typedef struct No {
    int dado;
    struct No* proximo;
}No;

typedef struct Lista_grafo {
    struct No** lista;
    int n_vertices;
}Lista_grafo;
/// funçoes de lista de adjacencia////
void criar_grafo_lista(Lista_grafo**l1,int num_vert);
void criar_no(int num,No ** no);
void add_aresta_lista_ad(Lista_grafo**l1,int origem,int dest);
void print_grafo_lista(Lista_grafo**l1);
////////////////////////////////////////
/// funçoes de matriz_adjacecia////
void criar_matriz_ad(matriz_adjacecia**matriz_ad,int vertices);
void add_aresta_matriz_ad(matriz_adjacecia**matriz_ad,int linha,int coluna);
void print_matriz_ad(matriz_adjacecia**matriz_ad);
////////////////////////////////////////////////
int main(){
    ////teste das funçoes de lista//////
    Lista_grafo *l1;
    criar_grafo_lista(&l1,4);
    add_aresta_lista_ad(&l1,0,1);
    add_aresta_lista_ad(&l1,0,2);
    print_grafo_lista(&l1);
    ////teste das funçoes de matriz//////
    matriz_adjacecia *m1;
    criar_matriz_ad(&m1,4);
    add_aresta_matriz_ad(&m1,0,1);
    add_aresta_matriz_ad(&m1,0,2);
    print_matriz_ad(&m1);
}
void criar_matriz_ad(matriz_adjacecia**matriz_ad,int vertices){
    (*matriz_ad) = malloc(sizeof(matriz_adjacecia));
    (*matriz_ad)->vertices = vertices;
    (*matriz_ad)->matriz = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        (*matriz_ad)->matriz[i] = (int*) malloc(vertices * sizeof(int));
    } 
    for(int i=0;i<vertices;i++){ // escrever zero em todas as posiçoes da matriz
        for(int j=0;j<vertices;j++){
                (*matriz_ad)->matriz[i][j]=0;
            }
        } 
} 
void add_aresta_matriz_ad(matriz_adjacecia**matriz_ad,int linha,int coluna){
      if(matriz_ad == NULL){
            printf("matriz nao alocada ou nao criada!!");
            exit(1);
    }   
    (*matriz_ad)->matriz[linha][coluna] = 1;

}
void print_matriz_ad(matriz_adjacecia**matriz_ad){
    if(matriz_ad == NULL){
        printf("matriz vazia !!");
        exit(1);
    }
    int n = (*matriz_ad)->vertices;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",(*matriz_ad)->matriz[i][j]);
            if(j+1 == n){
                printf("\n");
            }
        } 
    } 
}
void criar_grafo_lista(Lista_grafo**l1,int num_vert){
    (*l1) = (Lista_grafo*)malloc(sizeof(Lista_grafo));
    (*l1)->n_vertices = num_vert;
    (*l1)->lista = (No**)malloc(num_vert * sizeof(No*));
    for (int i = 0; i < num_vert; i++) {
        (*l1)->lista[i] = (No*) malloc(num_vert * sizeof(No));
    } 
    for (int i = 0; i < num_vert; i++) {
        (*l1)->lista[i] = NULL;
    } 
}
void criar_no(int num,No ** no){
    (*no) = (No*) malloc(sizeof(no));
    (*no)->proximo = NULL;
    (*no)->dado = num;

}
void add_aresta_lista_ad(Lista_grafo**l1,int origem,int dest){
    No * no; 
    criar_no(dest,&no);
    no->proximo = (*l1)->lista[origem];
    (*l1)->lista[origem] = no;
}
void print_grafo_lista(Lista_grafo**l1){
    for(int i =0;i<(*l1)->n_vertices;i++){
        No * no_agora = (*l1)->lista[i];
        printf("lista de adjacencia do vertice %d: ", i);
        while (no_agora!=NULL)
        {
           printf("%d ",no_agora->dado);
           no_agora = no_agora->proximo;
        }
        printf("\n");
    }
}