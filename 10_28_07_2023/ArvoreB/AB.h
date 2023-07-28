#ifndef AB_H_INCLUDED
#define AB_H_INCLUDED

//Arvore Binaria
typedef struct auxA {
    char caracter;
    struct auxA * direita;
    struct auxA * esquerda;
} ElementoA;

typedef struct {
    ElementoA *raiz;
} ArvoreB;


//Fila
typedef struct auxF{
    char expressao;
    struct auxF * proximo;
} ElementoF;

typedef struct {
    ElementoF * inicio;
    ElementoF * fim;
}Fila;



void InicializarArvore(ArvoreB * arvore);
void InserirArvore(ElementoA** raiz, ElementoA novo_elemento);
void ImprimirArvoreIn (ElementoA * raiz);
void InicializarFila(Fila * fila);
void InserirFila(Fila * fila, char caracter);
void ImprimirFila(Fila * fila);



#endif // AB_H_INCLUDED
