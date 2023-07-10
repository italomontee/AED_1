
#include <stdio.h>
#include <stdlib.h>
#define  MAX 5

void InicializaDeque(DEQUE *d){
    d->cabeca = malloc(sizeof(ELEMENTO));
    d->cabeca->anterior = d->cabeca;
    d->cabeca->proximo = d->cabeca;

}

int TamanhoDeque(DEQUE *d){
    ELEMENTO* i = d->cabeca->proximo;
    int t = 0;
    while (i != d->cabeca ){
        t++;
        i = i->proximo:
    }

}

void MostrarDeque(DEQUE *d){
    ELEMENTO *i = d->cabeca->proximo;
    while (i!= d->cabeca){
        pritf("nome: %s\n", i->alun.nome);
        i= i->proximo;
    }
}

void MostrarDequeAPartir(DEQUE *d, int pos, char ordem){
    int count = 0;

    if (ordem == "d") {
        ELEMENTO i = d->cabeca->proximo;
        while(i != d->cabeca){
            if (pos <= count) {
                printf("%s", i->alun.nome);
            }
            count++;
            i = i->proximo;
        }
    }
    elif(ordem=="i"){
        ELEMENTO i = d->cabeca->anterior;
        while (i != d->cabeca){
            if(MAX - count <= pos){
                printf("%s", i->alun.nome);
            }
            count++;
            i = i->anterior;
        }
    }
    else {
        printf("Entrada invalida");
    }
}

void InserirInicio(DEQUE *d, ALuno aluno_inserir){
    ELEMENTO* i = malloc(sizeof(ELEMENTO));
    i.alun = aluno_inserir;
    i->proximo = d->cabeca->proximo;
    i->anterior = d->cabeca;
    d->cabeca->proximo->anterior = i;
    d->cabeca->proximo = i;
}

void InserirFim (DEQUE *d, ALuno aluno_inserir) {
    ELEMENTO * i = malloc(sizeof(ELEMENTO));
    i->alun = aluno_inserir;
    i->proximo = d->cabeca;
    i->anterior = d->cabeca->anterior;
    i->anterior->proximo = i;
    i->proximo->anterior = i;
}
