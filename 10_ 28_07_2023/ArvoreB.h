#ifndef ARVOREB_H_INCLUDED
#define ARVOREB_H_INCLUDED

typedef struct aux {
    char crc;
    struct aux * direita;
    struct aux * esquerda;
} Elemento;

typedef struct {
    Elemento * raiz;
}ArvoreB;

void Inicializar(ArvoreB * arv);
int Inserirr(Elemento ** raiz, char crct);
void imprimirArvorePre(Elemento *raiz);
void imprimirArvoreIn(Elemento *raiz);
void imprimirArvorePos(Elemento *raiz);




#endif // ARVOREB_H_INCLUDED
