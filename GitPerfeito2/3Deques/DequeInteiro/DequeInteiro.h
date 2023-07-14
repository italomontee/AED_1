#ifndef DEQUEINTEIRO_H_INCLUDED
#define DEQUEINTEIRO_H_INCLUDED

typedef struct aux {
    int numero;
    struct aux* proximo;
    struct aux* anterior;
} ELEMENTO;

typedef struct {
    ELEMENTO* cabeca;
} DEQUE;

void InicializaDeque(DEQUE* d);
int TamanhoDeque(DEQUE* d);
void MostrarDeque(DEQUE* d);
void InserirInicio(DEQUE* d, int numero);
void InserirFim(DEQUE* d, int numero);
void ExcluirInicio(DEQUE* d);
void ExcluirFim(DEQUE* d);
void ExcluirElemento(DEQUE* d, int numero);
void Reinicializar(DEQUE* d);

#endif // DEQUEINTEIRO_H_INCLUDED
