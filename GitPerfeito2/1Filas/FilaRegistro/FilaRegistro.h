#ifndef FILAREGISTRO_H_INCLUDED
#define FILAREGISTRO_H_INCLUDED

#define MAX 5

typedef struct {
    char nome[50];
    int idade;
    char cpf[15];
    int chave;
} PESSOA;

typedef struct aux {
    PESSOA pessoa;
    struct aux* proximo;
} ELEMENTO;

typedef struct {
    ELEMENTO* inicio;
    ELEMENTO* fim;
} FILA;

void Inicializar(FILA* f);
void EntrarNaFila(FILA* fila, PESSOA pessoa);
int SairDaFila(FILA* fila);
int FurarFila(FILA* fila, PESSOA pessoa, int pos);
int Mostrar(FILA* fila);

#endif // FILAREGISTRO_H_INCLUDED
