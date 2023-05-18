#include <stdio.h>
#include <stdlib.h>

typedef struct NC
{
    int Parte_Real;
    int Parte_Imaginaria;
}NC;


NC* CreateNC()
{
    NC *nc;
    nc = malloc(sizeof(NC));

    printf("Parte Real: ");
    scanf("%d", &(nc->Parte_Real));
    printf("Parte Imaginaria: ");
    scanf("%d", &(nc->Parte_Imaginaria));

    return nc;
}

void DestroyNC(NC *nc)
{
    free(nc);
}

void SomaNC(NC *nc1, NC *nc2)
{

}