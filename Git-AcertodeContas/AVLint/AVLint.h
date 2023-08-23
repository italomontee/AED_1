#ifndef AVLINT_H_INCLUDED
#define AVLINT_H_INCLUDED

typedef struct aux {
    int chave;
    int h;
    struct aux * esquerda;
    struct aux * direita;
} NO;

typedef struct {
    NO * raiz;
} AVL;

//inicializar
void Inicializar(AVL * arvore);

//medidas
int Altura(NO* raiz);
int Profundidade(NO* raiz, int codigo, int cont);
int Nivel(NO* raiz, int codigo, int cont);
int Contar(NO* raiz, int * count);
int maximo (int v1, int v2);

//rotações
NO* rot_direita(NO* NO_desb);
NO* rot_esquerda(NO* NO_desb);
NO* rot_dir_esquerda(NO* NO_desb);
NO* rot_esq_direita(NO* NO_desb);

//inserir
NO * AlocarNo(int numero);
NO * InserirAVL(NO * raiz, int cod);

//imprimir
void ImprimirInOrder(NO* raiz);
void ImprimirPreOrder(NO* raiz);
void ImprimirPosOrder(NO* raiz);
int PercorrerEmLargura(NO* raiz);

//buscar
void Buscar(NO * no, int cod);

#endif // AVLINT_H_INCLUDED
