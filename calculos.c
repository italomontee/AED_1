
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculos.h"



// Inicializar a estrutura
void Inicializar(ListaInteira* m)
{
    m->inicio = NULL;
}

// Retornar quantidade de elementos válidos
int Tamanho(ListaInteira* m)
{
    int tam = 0;
    Elemento* i = m->inicio;
    while (i != NULL)
    {
        tam += i->ocorrencias;
        i = i->proximo;
    }
    return tam;
}

// Exibir elementos da estrutura
void Exibir(ListaInteira* m)
{
    Elemento* i = m->inicio;
    while (i != NULL)
    {
        for (int j = 0; j < i->ocorrencias; j++)
        {
            printf("%d ", i->numero);
        }
        i = i->proximo;
    }
    printf("\n");
}

// Buscar elementos da estrutura sequencial
int BuscarSequencial(ListaInteira* m, int num)
{
    Elemento* i = m->inicio;
    int indice = 0;
    while (i != NULL)
    {
        if (i->numero == num)
        {
            return indice;
        }
        else
        {
            indice += i->ocorrencias;
            i = i->proximo;
        }
    }
    // Caso o número não seja encontrado
    return -1;
}

int ContarFrequencia(ListaInteira *m, int valor)
{
    Elemento* pos = m->inicio;
    int frequencia = 0;

    while (pos != NULL)
    {
        if (pos->numero == valor)
        {
            frequencia++;
        }
        pos = pos->proximo;
    }

    return frequencia;
}
    


// Busca binária não funciona corretamente para listas com números repetidos

// Inserir elementos
void InserirElemento(ListaInteira* m, int num)
{
    Elemento* i = m->inicio;
    Elemento* pos_inserir = NULL;

    if (i == NULL)
    {
        i = malloc(sizeof(Elemento));
        i->numero = num;
        i->ocorrencias = 1;
        i->proximo = NULL;
        m->inicio = i;
        return;
    }

    while (i != NULL && i->numero < num)
    {
        pos_inserir = i;
        i = i->proximo;
    }

    if (i != NULL && i->numero == num)
    {
        i->ocorrencias++;
        return;
    }

    Elemento* novo = malloc(sizeof(Elemento));
    novo->numero = num;
    novo->ocorrencias = 1;

    if (pos_inserir == NULL)
    {
        novo->proximo = m->inicio;
        m->inicio = novo;
    }
    else
    {
        novo->proximo = pos_inserir->proximo;
        pos_inserir->proximo = novo;
    }
}

void Inserir(ListaInteira* m)
{
    int novo;
    printf("Insira um numero inteiro: ");
    scanf("%d", &novo);

    InserirElemento(m, novo);
}

void ExcluirElemento(ListaInteira* m, int num)
{
    Elemento* anterior = NULL;
    Elemento* atual = m->inicio;

    while (atual != NULL)
    {
        if (atual->numero == num)
        {
            if (anterior == NULL)
            {
                m->inicio = atual->proximo;
            }
            else
            {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}
