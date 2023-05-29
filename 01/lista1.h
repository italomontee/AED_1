#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int tamanho;
    int* vetor;
}lista;

void *CriarNovaLista(int tamanho);
void PreencherLista(lista *endereco);
void ImprimirLista(lista *endereco);
void BuscarNaLista(int n, lista *endereco);
void MaiorElementoIterativo(lista *endereco, int tamanho);
int MaiorElementoRecursivo(lista *endereco, int tamanho, int aux);
void MenorElementoIterativo(lista *endereco, int tamanho);
int MenorElementoRecursivo(lista *endereco, int tamanho, int aux);
void SomaIterativa(lista *endereco, int tamanho);
void ProdutoInterativo(lista *endereco,int tamanho);
int ProdutoRecursivo(lista *endereco, int tamanho, int aux);
