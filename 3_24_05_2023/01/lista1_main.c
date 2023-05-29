#include <stdio.h>
#include <stdlib.h>
#include "lista1.h"


int main()
{   

    int tamanho;
    int valor;


    //Criando lista
    printf("Qual tamanho da sua lista: ");
    scanf("%d", &tamanho);

    lista *local = CriarNovaLista(tamanho);
    PreencherLista(local);

    
    printf("\nIMPRIMIR LISTA\n");

    ImprimirLista(local);
    
    //Valores teste
    printf("\nValores de Teste\n");
    BuscarNaLista(99, local);
    BuscarNaLista(3, local);

    //Buscando na lista
    printf("\n\nBUSCA NA LISTA\n");
    
    printf("Quer procurar qual valor na lista: ");
    scanf("%d", &valor);
    
    BuscarNaLista(valor, local);

    //Maior e menor
    printf("\nMAIOR E MENOR\n");
    MaiorElementoIterativo(local, tamanho);
    MaiorElementoRecursivo(local, tamanho, local->vetor[tamanho-1]);
    MenorElementoIterativo(local, tamanho);
    MenorElementoRecursivo(local, tamanho, local->vetor[tamanho-1]);

    printf("\nSOMA E PRODUTO\n");
    SomaIterativa(local, tamanho);
    SomaRecursiva(local, tamanho, 0);
    ProdutoInterativo(local, tamanho);
    ProdutoRecursivo(local, tamanho, 1);

    free(local->vetor);
    free(local);

    }