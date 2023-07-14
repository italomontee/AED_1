#ifndef FILAINTEIRO_H_INCLUDED
#define FILAINTEIRO_H_INCLUDED

//Lista Dinâmica
//com politica de entrada e saida

typedef struct {
    int num;
} NUMERO;

typedef struct aux {
    NUMERO num;
    struct aux * proximo;
}ELEMENTO;

typedef struct {
    ELEMENTO * inicio;
    ELEMENTO * fim;
}FILA;

void Inicializar(FILA * f);
void EntrarNaFila(FILA * fila, NUMERO num);
int SairDaFila(FILA * fila);
int FurarFila(FILA * fila, NUMERO num, int pos);
int Mostrar(FILA * fila);


#endif // FILAINTEIRO_H_INCLUDED
