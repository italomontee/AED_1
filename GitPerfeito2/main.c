#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dequee.h"

int main()
{
    time_t now;

    time(&now);

    printf("Data e hora de entrega %s\n", ctime(&now));
    printf("Italo Guilherme Monte\n");
    printf("Numero do exercicio: 005\n\n");


    DEQUE deque1;
    DEQUE deque2;

    InicializaDeque(&deque1);
    InicializaDeque(&deque2);

    InserirInicio(&deque1, 1);
    InserirFim(&deque1, 3);
    InserirFim(&deque1, 5);
    InserirFim(&deque1, 7);


    InserirInicio(&deque2, 2);
    InserirFim(&deque2, 4);
    InserirFim(&deque2, 6);
    InserirFim(&deque2, 8);

    printf("DEQUE 1: \n");
    MostrarDeque(&deque1);

    //printf("Tamanho deque1: %d\n", TamanhoDeque(&deque1));

    printf("\nDEQUE 2: \n");
    MostrarDeque(&deque2);

    DEQUE deque3;
    InicializaDeque(&deque3);

    InserirIntercalado(&deque3, &deque1, &deque2);

    printf("\nDEQUE 3: \n");
    MostrarDeque(&deque3);

    return 0;
}
