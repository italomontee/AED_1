#ifndef DEQUEREGISTRO_H_INCLUDED
#define DEQUEREGISTRO_H_INCLUDED
#define MAX 10
typedef struct {
    char * nome;

} ALUNO;

typedef struct aux {
    ALUNO alun;
    struct aux* proximo;
    struct aux* anterior;
} ELEMENTO;

typedef struct {
    ELEMENTO* cabeca;
} DEQUE;

void InicializaDeque(DEQUE *d);
int TamanhoDeque(DEQUE* d);
void MostrarDeque(DEQUE* d);
void InserirFim(DEQUE* d, ALUNO aluno);
void InserirInicio(DEQUE* d, ALUNO aluno);
void ExlucirInicio(DEQUE* d);
void ExlucirFim(DEQUE* d);
void ExlucirA(DEQUE* d, ALUNO aluno);
void reinicializar(DEQUE *d);


#endif // DEQUEREGISTRO_H_INCLUDED
