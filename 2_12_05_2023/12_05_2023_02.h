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

void SomaNC()
{
    NC *nc1 = CreateNC();
    NC *nc2 = CreateNC();
    NC *nc3 = malloc(sizeof(NC));

    nc3->Parte_Real = (nc2->Parte_Real) + (nc1->Parte_Real);
    nc3->Parte_Imaginaria = (nc2->Parte_Imaginaria) + (nc1->Parte_Imaginaria);
    
    printf("PR: %d", nc3->Parte_Real);
    printf("PI: %d", nc3->Parte_Imaginaria);
}

void SubtracaoNC()
{
    NC *nc1 = CreateNC();
    NC *nc2 = CreateNC();
    NC *nc3 = malloc(sizeof(NC));

    nc3->Parte_Real = (nc2->Parte_Real) - (nc1->Parte_Real);
    nc3->Parte_Imaginaria = (nc2->Parte_Imaginaria) - (nc1->Parte_Imaginaria);
    
    printf("PR: %d", nc3->Parte_Real);
    printf("PI: %d", nc3->Parte_Imaginaria);
}

void MultiplicacaoNC()
{
    NC *nc1 = CreateNC();
    NC *nc2 = CreateNC();
    NC *nc3 = malloc(sizeof(NC));

    nc3->Parte_Real = (nc2->Parte_Real) * (nc1->Parte_Real);
    nc3->Parte_Imaginaria = (nc2->Parte_Imaginaria) * (nc1->Parte_Imaginaria);
    
    printf("PR: %d", nc3->Parte_Real);
    printf("PI: %d", nc3->Parte_Imaginaria);
}

void DivisaoNC()
{
    NC *nc1 = CreateNC();
    NC *nc2 = CreateNC();
    NC *nc3 = malloc(sizeof(NC));

    nc3->Parte_Real = (nc2->Parte_Real) + (nc1->Parte_Real);
    nc3->Parte_Imaginaria = (nc2->Parte_Imaginaria) + (nc1->Parte_Imaginaria);
    
    printf("PR: %d", nc3->Parte_Real);
    printf("PI: %d", nc3->Parte_Imaginaria);
}