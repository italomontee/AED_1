#include <stdio.h>
#include <stdlib.h>
#include "AVLstr.h"

//incializar
void Inicializar(AVL * arvore){
    arvore->raiz = NULL;
}

//medidas
int Altura(NO* raiz){
    if(!raiz) return(-1);
    else return (raiz->h);
}

int Profundidade(NO* raiz, char* codigo ,int cont){
    if(raiz ==  NULL){
        cont = -1;
        printf("\n\nPalavra nao encontrada ou arvore sem elementos!");
        return cont;
    }
    printf("%s, %s", raiz->chave, codigo);


    if(strcmp(raiz->chave, codigo) == 0){
        return cont;
    }
    else{
        if(strncmp(raiz->chave, codigo, 1) < 0){
            cont++;
            Profundidade(raiz->esquerda, codigo, cont);
        }
        else{
            cont++;
            Profundidade(raiz->direita, codigo, cont);
        }
    }
}

int Nivel(NO* raiz, char codigo,int cont){
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

NO* Buscar(NO * no, char cod[]){
    if(strncmp (no->chave, cod, 1) == 0){
        return no;
    }
    Buscar(no->esquerda, cod);
    Buscar(no->direita, cod);
}



int Maximo (int v1, int v2){
    if (v1>v2)
        return v1;
    else
        return v2;
}

//rotações
NO* rot_direita(NO* NO_desb){

    NO* aux = NO_desb->esquerda;
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


// Função para atualizar a altura de um nó com base na altura das subárvores
void atualizaAltura(NO* no) {
    int alturaEsquerda = Altura(no->esquerda);
    int alturaDireita = Altura(no->direita);
    no->h = (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita) + 1;
}

int fatorBalanceamento(NO* no) {
    if (no == NULL)
        return 0;
    return Altura(no->esquerda) - Altura(no->direita);
}

//inserir
NO* inserir(NO* no, char dado[]) {
    // Realiza a inserção como em uma árvore binária de busca
    if (no == NULL) {
        NO* novoNo = (NO*)malloc(sizeof(NO));
        strcpy(novoNo->chave, dado);
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
        novoNo->h = 1;
        return novoNo;
    }

    int comp = strncmp(dado, no->chave, 1);

    if (comp < 0){
        no->esquerda = inserir(no->esquerda, dado);
    }

    else if (comp > 0){
        no->direita = inserir(no->direita, dado);
    }

    else{
        return no; // Duplicatas não são permitidas
    }


    // Atualiza a altura deste nó
    atualizaAltura(no);

    // Calcula o fator de balanceamento deste nó
    int balanceamento = fatorBalanceamento(no);

    // Verifica se o nó ficou desbalanceado
    // Rotação simples à direita
    if (balanceamento > 1 && dado[0] < no->esquerda->chave[0])
        return rot_direita(no);

    // Rotação simples à esquerda
    if (balanceamento < -1 && dado[0] > no->direita->chave[0])
        return rot_esquerda(no);

    // Rotação dupla à esquerda-direita
    if (balanceamento > 1 && dado[0] > no->esquerda->chave[0]) {
        no->esquerda = rot_esquerda(no->esquerda);
        return rot_direita(no);
    }

    // Rotação dupla à direita-esquerda
    if (balanceamento < -1 && dado[0] < no->direita->chave[0]) {
        no->direita = rot_direita(no->direita);
        return rot_esquerda(no);
    }

    return no;
}

//imprimir

void ImprimirInOrder(NO* raiz){
   // no da esquerda, raiz, no da esquerda
    if (raiz != NULL){
        ImprimirInOrder(raiz->esquerda);
        printf("%s ", raiz->chave);
        ImprimirInOrder(raiz->direita);
    }
}

void ImprimirPreOrder(NO* raiz){
    // raiz,  no da esquerda, no da direita
    if (raiz != NULL){
        printf("%s ", raiz->chave);
        ImprimirPreOrder(raiz->esquerda);
        ImprimirPreOrder(raiz->direita);

    }
}

void ImprimirPosOrder(NO* raiz){
    // no da esquerda, no da direita, raiz
    if (raiz != NULL){
        ImprimirPosOrder(raiz->esquerda);
        ImprimirPosOrder(raiz->direita);
        printf("%s ", raiz->chave);

    }
}

int PercorrerEmLargura(NO* raiz){
    if (raiz == NULL){
            return;
        }

        //valores iniciais
        NO * lista[1000];
        int inicio = 0;
        int fim = 0;

        //add raiz a lista
        lista[fim] = raiz;

        fim++;

        //looping

        while (inicio < fim){
            NO * atual = lista[inicio++];
            printf("%s ", atual->chave);
            if (atual->esquerda != NULL){
                lista[fim++] = atual->esquerda;
            }
            if (atual->direita != NULL){
                lista[fim++] = atual->direita;
            }
        }
}


//buscar


