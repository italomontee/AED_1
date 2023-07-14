#ifndef DEQUEE_H_INCLUDED
#define DEQUEE_H_INCLUDED


#ifndef DEQUE_H_INCLUDED
#define DEQUE_H_INCLUDED


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
void inseririntercalado(DEQUE *final, DEQUE*deque1, DEQUE*deque2);
void ExcluirInicio(DEQUE* d);
void ExcluirFim(DEQUE* d);
void ExcluirElemento(DEQUE* d, int numero);
void Reinicializar(DEQUE* d);


#endif // DEQUE_H_INCLUDED


#endif // DEQUEE_H_INCLUDED
