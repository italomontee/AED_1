#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char * nome;
    int cod;
} AVIAO;

typedef struct aux{
    AVIAO avi;
    struct aux * proximo;
} ELEMENTO;

typedef struct {
    ELEMENTO * topo;
} HANGAR;

void inicializar(HANGAR *h){
    h->topo = NULL;
}

int TirarAviao (HANGAR *h) {
    if (h->topo == NULL){
        return -1;
    } else {
        ELEMENTO *i = h->topo;
        h->topo = h->topo->proximo;
        free(i);
        return 0;
    }

}

void AvioesEsperando(HANGAR * h){

    ELEMENTO * i;
    i = h->topo;
    while (i != NULL){
        printf("nome: %s\n", i->avi.nome);
        printf("codigo: %d\n", i->avi.cod);
        i = i->proximo;
    }
}

void AdicionarAviao (HANGAR *h, AVIAO aviao) {
    ELEMENTO *i = malloc(sizeof(ELEMENTO));
    i->avi = aviao;
    i->proximo = h->topo;
    h->topo = i;
}

void ListarAvioes (HANGAR * h) {
    ELEMENTO* i = h->topo;
    while(i != NULL){
        printf("nome: %s", i->avi.nome);
        printf("cod: %d", i->avi.cod);
        i = i->proximo;
    }
}

void CaracteristicaPrimeiro (HANGAR *h) {
    ELEMENTO * i = h->topo;

    printf("Caracterisiticas do primeiro: \n");
    printf("nome: %s\n", i->avi.nome);
    printf("cod: %d\n", i->avi.cod);
}

int RetirarPelaPosicao (int posicao, HANGAR  *h) {
    if (h->topo == NULL) {
        return -1;}

    else if (posicao == 0){
        TirarAviao(h);
    }
    else {
        int count=0;
        ELEMENTO* i = h->topo;
        ELEMENTO* anterior = NULL;
        while (i != NULL) {
            if (count == posicao){
                anterior->proximo = i->proximo;
                free(i);
                return 0;}
            anterior = i;
            i = i->proximo;
            count++;
            }
        }

    return 0;
}

int main()
{
    HANGAR hangar01;
    AVIAO av;

    inicializar(&hangar01);

    av.cod = 001;
    av.nome = "av1";

    AdicionarAviao(&hangar01, av);

    av.cod = 002;
    av.nome = "av2";

    AdicionarAviao(&hangar01, av);

    av.cod = 003;
    av.nome = "av3";

    AdicionarAviao(&hangar01, av);

    AvioesEsperando(&hangar01);

    CaracteristicaPrimeiro(&hangar01);

    printf("retirando o do meio\n");
    RetirarPelaPosicao(1, &hangar01);
    AvioesEsperando(&hangar01);
    return 0;
}
