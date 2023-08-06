#ifndef ARVOREB_H_INCLUDED
#define ARVOREB_H_INCLUDED

typedef struct aux {
    int num;
    struct aux * direita;
    struct aux * esquerda;
} Elemento;

typedef struct {
    Elemento * raiz;
}ArvoreB;

void Inicializar(ArvoreB * arv);
int Inserir(ArvoreB * arv, int num);
void imprimirArvorePre(Elemento *raiz);
void imprimirArvoreIn(Elemento *raiz);
void imprimirArvorePos(Elemento *raiz);
int Contador(Elemento *raiz);
int Busca(Elemento *raiz, int num);



#endif // ARVOREB_H_INCLUDED
