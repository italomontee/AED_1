#include <stdio.h>
#include <stdlib.h>
#include "AVLint.h"

//incializar
void Inicializar(AVL * arvore){
    arvore->raiz = NULL;
}

//medidas
int Altura(NO* raiz){
    if(!raiz) return(-1);
    else return (raiz->h);
}

int Profundidade(NO* raiz, int codigo,int cont){
    if(raiz ==  NULL){
            cont = 0;
            printf("\n\nPaciente nao encontrado ou arvore sem elementos!");
            return cont;
    }
    if(raiz->chave == codigo){
        return cont;
    }
    else{
        if(codigo < raiz->chave){
            cont++;
            Profundidade(raiz->esquerda, codigo, cont);
        }
        else{
            cont++;
            Profundidade(raiz->direita, codigo, cont);
        }
    }
}

int Nivel(NO* raiz, int codigo,int cont){
    if(raiz ==  NULL){
            cont = 0;
            printf("\n\nPaciente nao encontrado ou arvore sem elementos!");
            return cont;
    }
    if(raiz->chave == codigo){
        return cont;
    }
    else{
        if(codigo < raiz->chave){
            cont++;
            Profundidade(raiz->esquerda, codigo, cont);
        }
        else{
            cont++;
            Profundidade(raiz->direita, codigo, cont);
        }
    }
}

int Contar(NO * no, int * count){
    if (no != NULL){
        Contar(no->esquerda, count);
        Contar(no->direita, count);
        (*count)++;
    }
    return (*count);
}

int Maximo (int v1, int v2){
    if (v1>v2)
        return v1;
    else
        return v2;
}

//rotações
NO* rot_direita(NO* NO_desb){
    NO* aux;
    aux=NO_desb->esquerda;
    NO_desb->esquerda = aux->direita;
    aux->direita = NO_desb;

    NO_desb->h = Maximo(Altura(NO_desb->direita), Altura(NO_desb->esquerda))+1;

    aux->h =Maximo(Altura(aux->esquerda), Altura(NO_desb))+1;

    return (aux);
}

NO* rot_esquerda(NO* NO_desb){

    NO* aux;
    aux=NO_desb->direita;
    NO_desb->direita = aux->esquerda;
    aux->esquerda = NO_desb;

    NO_desb->h = Maximo(Altura(NO_desb->direita), Altura(NO_desb->esquerda))+1;

    aux->h =Maximo(Altura(aux->esquerda), Altura(NO_desb))+1;

    return (aux);
}
NO* rot_dir_esquerda(NO* NO_desb){
    NO_desb->direita = rot_direita(NO_desb->direita);
    return (rot_esquerda(NO_desb));
}

NO* rot_esq_direita(NO* NO_desb){
    NO_desb->esquerda = rot_esquerda(NO_desb->esquerda);
    return (rot_direita(NO_desb));
}

//inserir
NO * AlocarNo(int numero){
    //alocar memoria para receber o numero
    NO * novoNo = malloc(sizeof(NO));
    novoNo->chave = numero;
    novoNo->direita = NULL;
    novoNo->esquerda = NULL;

    return novoNo;
}

NO * InserirAVL(NO * raiz, int cod){
    NO* no = AlocarNo(cod);
    if (raiz == NULL) return (no);
    if (raiz->chave > no->chave){
        raiz->esquerda = InserirAVL(raiz->esquerda, cod);
        if ((Altura(raiz->direita) - Altura(raiz->esquerda)) == 2){
            if (no->chave < raiz->esquerda->chave)
                raiz = rot_direita(raiz);
            else
                raiz = rot_esq_direita(raiz);

        }
    }
    else if (raiz->chave < no->chave){
        raiz->direita = InserirAVL(raiz->direita, cod);
        if ((Altura(raiz->direita) - Altura(raiz->esquerda)) == 2){
            if (no->chave > raiz->direita->chave)
                raiz = rot_direita(raiz);
            else
                raiz = rot_dir_esquerda(raiz);
        }
    }
    raiz->h = Maximo(Altura(raiz->esquerda), Altura(raiz->direita)) +1;
    return (raiz);
}

//imprimir

void ImprimirInOrder(NO* raiz){
   // no da esquerda, raiz, no da esquerda
    if (raiz != NULL){
        ImprimirInOrder(raiz->esquerda);
        printf("%d ", raiz->chave);
        ImprimirInOrder(raiz->direita);
    }
}

void ImprimirPreOrder(NO* raiz){
    // raiz,  no da esquerda, no da direita
    if (raiz != NULL){
        printf("%d ", raiz->chave);
        ImprimirPreOrder(raiz->esquerda);
        ImprimirPreOrder(raiz->direita);

    }
}

void ImprimirPosOrder(NO* raiz){
    // no da esquerda, no da direita, raiz
    if (raiz != NULL){
        ImprimirPosOrder(raiz->esquerda);
        ImprimirPosOrder(raiz->direita);
        printf("%d ", raiz->chave);

    }
}

int PercorrerEmLargura(NO* raiz){
}

//buscar
void Buscar(NO * no, int cod){
    if(no->chave == cod){
        printf("\nA chave %d esta na arvore");
    }
    Buscar(no->esquerda, cod);
    Buscar(no->direita, cod);
}



