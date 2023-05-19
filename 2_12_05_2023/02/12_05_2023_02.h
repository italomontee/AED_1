#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int Parte_Real;
    int Parte_Imaginaria;
}NC;


NC* CreateNC();
void DestroyNC(NC *nc);
void SomaNC();
void SubtracaoNC();
void MultiplicacaoNC();
void DivisaoNC();

