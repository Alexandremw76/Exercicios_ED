#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore
typedef struct no {
    int val;
    struct no* left;
    struct no* right;
} no;

typedef struct arvor {
    struct no* raiz;
} arvor;


// Função para criar um novo nó
void createno(int val,no ** new_no) {
    (*new_no) = (no*)malloc(sizeof(no));
    (*new_no)->val = val;
    (*new_no)->left = NULL;
    (*new_no)->right = NULL;
}
void creat_tree(int raiz,arvor** arvore){
    (*arvore) =  (arvor*)malloc(sizeof(arvor));
    createno(raiz,&(*arvore)->raiz);
}

// Função para inserir um valor na árvore
void insertno(arvor** arvore, int val) {
    if((*arvore)==NULL)
    {
        creat_tree(val,arvore);
    }
    else
    {
    no * lugar_final = (*arvore)->raiz; // sera null
    no* lugar_a_inserir; // sera um -1 do lugar portanto nao sera null
    while(lugar_final!=NULL){
        lugar_a_inserir = lugar_final;
        if (val < lugar_final->val) 
        {
            lugar_final = lugar_final->left;
        }
        else if (val > lugar_final->val) 
        {
            lugar_final = lugar_final->right;
        }
        else
        {
            printf("error nao e possivel colocar o mesmo numero duas vezes");
            exit(1);
        }

    }
    if(val<lugar_a_inserir->val)
        {
   
            no * no_a_inserir;
            createno(val,&no_a_inserir);
            lugar_a_inserir->left = no_a_inserir;
        }
    else if(val>lugar_a_inserir->val)
        {
            no * no_a_inserir;
            createno(val,&no_a_inserir);
            lugar_a_inserir->right = no_a_inserir;
        }
    }
}
//Função para achar no ou numero na árvore
void busca(arvor** arvore, int val){
    no * atual = (*arvore)->raiz;
    no * comparar = NULL;
    while (atual!=NULL)
    {
        comparar = atual;
       if(val > atual->val)
        {
            atual = atual->right;
        }
        else if(val < atual->val)
        {
            atual = atual->left;
        }
        else if(val == atual->val)
        {
            break;
        }
    }
    if(comparar->val == val)
    {
        printf("Numero %d encontrado na arvore!!",val);
    }
    else
    {
        printf("Numero %d nao encontrado!!!",val);
    }

}
// Função para imprimir os valores em ordem (in-order traversal)
void inorderTraversal(no* arvore) {
    if (arvore != NULL) {
        inorderTraversal(arvore->left);
        printf("%d ", arvore->val);
        inorderTraversal(arvore->right);
    }
}

int main() {
    arvor* arvore = NULL;
    insertno(&arvore, 11);
    insertno(&arvore, 13);
    insertno(&arvore, 19);
    insertno(&arvore, 7);
    insertno(&arvore, 23);
    insertno(&arvore, 1);
    busca(&arvore, 13);
    //inorderTraversal(arvore->raiz);

    return 0;
}