#include <stdio.h>
#include <stdlib.h>
#include "PilhaInteiro.h"

int main() {
    PILHA pilha;
    Inicializar(&pilha);

    Empilhar(&pilha, 5);
    Empilhar(&pilha, 10);
    Empilhar(&pilha, 15);

    MostrarPilha(&pilha);

    int numero_desempilhado = Desempilhar(&pilha);
    printf("Número desempilhado: %d\n", numero_desempilhado);

    MostrarPilha(&pilha);

    return 0;
}
