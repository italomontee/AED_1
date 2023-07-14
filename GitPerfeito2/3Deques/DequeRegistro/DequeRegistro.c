#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DequeRegistro.h"

void InicializaDeque(DEQUE* d) {
    d->cabeca = malloc(sizeof(ELEMENTO));
    d->cabeca->anterior = d->cabeca;
    d->cabeca->proximo = d->cabeca;
}

int TamanhoDeque(DEQUE* d) {
    ELEMENTO* i = d->cabeca->proximo;
    int t = 0;
    while (i != d->cabeca) {
        t++;
        i = i->proximo;
    }
    return t;
}

void MostrarDeque(DEQUE* d) {
    ELEMENTO* i = d->cabeca->proximo;
    while (i != d->cabeca) {
        printf("Nome: %s\n", i->alun.nome);
        i = i->proximo;
    }
}

void MostrarDequeAPartir(DEQUE* d, int pos, char ordem) {
    int count = 0;

    if (ordem == 'd') {
        ELEMENTO* i = d->cabeca->proximo;
        while (i != d->cabeca) {
            if (pos <= count) {
                printf("Nome: %s\n", i->alun.nome);
            }
            count++;
            i = i->proximo;
        }
    } else if (ordem == 'i') {
        ELEMENTO* i = d->cabeca->anterior;
        while (i != d->cabeca) {
            if (MAX - count <= pos) {
                printf("Nome: %s\n", i->alun.nome);
            }
            count++;
            i = i->anterior;
        }
    } else {
        printf("Ordem inválida.\n");
    }
}

void InserirInicio(DEQUE* d, ALUNO aluno_inserir) {
    ELEMENTO* i = malloc(sizeof(ELEMENTO));
    i->alun = aluno_inserir;
    i->proximo = d->cabeca->proximo;
    i->anterior = d->cabeca;
    d->cabeca->proximo->anterior = i;
    d->cabeca->proximo = i;
}

void InserirFim(DEQUE* d, ALUNO aluno_inserir) {
    ELEMENTO* i = malloc(sizeof(ELEMENTO));
    i->alun = aluno_inserir;
    i->proximo = d->cabeca;
    i->anterior = d->cabeca->anterior;
    d->cabeca->anterior->proximo = i;
    d->cabeca->anterior = i;
}

void ExcluirInicio(DEQUE* d) {
    if (d->cabeca->proximo == d->cabeca) {
        printf("O deque está vazio.\n");
        return;
    }

    ELEMENTO* elemento_removido = d->cabeca->proximo;
    d->cabeca->proximo = elemento_removido->proximo;
    elemento_removido->proximo->anterior = d->cabeca;
    free(elemento_removido);
}

void ExcluirFim(DEQUE* d) {
    if (d->cabeca->anterior == d->cabeca) {
        printf("O deque está vazio.\n");
        return;
    }

    ELEMENTO* elemento_removido = d->cabeca->anterior;
    d->cabeca->anterior = elemento_removido->anterior;
    elemento_removido->anterior->proximo = d->cabeca;
    free(elemento_removido);
}

void ExcluirA(DEQUE* d, ALUNO aluno_excluir) {
    ELEMENTO* i = d->cabeca->proximo;
    while (i != d->cabeca) {
        if (strcmp(i->alun.nome, aluno_excluir.nome) == 0) {
            i->anterior->proximo = i->proximo;
            i->proximo->anterior = i->anterior;
            free(i);
            return;
        }
        i = i->proximo;
    }
    printf("Aluno não encontrado no deque.\n");
}

void reinicializar(DEQUE* d) {
    ELEMENTO* i = d->cabeca->proximo;
    while (i != d->cabeca) {
        ELEMENTO* elemento_removido = i;
        i = i->proximo;
        free(elemento_removido);
    }
    d->cabeca->proximo = d->cabeca;
    d->cabeca->anterior = d->cabeca;
}
