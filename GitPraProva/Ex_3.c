#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct
{
    int valor;
    int proximo;
} Elemento;

typedef struct
{
    Elemento lista[MAX];
    int disponivel;
    int inicio;
} ListaLigada;

void InicializarEstrutura(ListaLigada *m, int n)
{
    for (int i = 0; i < n; i++)
    {
        m->lista[i].proximo = i + 1;
        m->lista[i].valor = 0;
    }

    m->lista[n - 1].proximo = -1;
    m->disponivel = 0;
    m->inicio = 0;
}

void ExcluirElemento(ListaLigada *m, int valor)
{
    int pos = m->inicio;
    int pos_anterior = -1;

    while (pos != -1 && m->lista[pos].valor != valor)
    {
        pos_anterior = pos;
        pos = m->lista[pos].proximo;
    }

    if (pos != -1)
    {
        if (pos_anterior == -1)
        {
            m->inicio = m->lista[pos].proximo;
        }
        else
        {
            m->lista[pos_anterior].proximo = m->lista[pos].proximo;
        }
        m->lista[pos].proximo = m->disponivel;
        m->disponivel = pos;
    }
}


int RetornarMaior(ListaLigada* m){
    int maior;
    int i = m->inicio;
    int t = 0;
    while (i != -1){
        if (t == 0){
            maior = m->lista[i].valor;
        } else {
            if (m->lista[i].valor > maior) {
                maior = m->lista[i].valor;
            }
            
        }
        i = m->lista[i].proximo;
        t++;
    }
    
    ExcluirElemento(m, maior);

    return maior;

}

void ExibirLista(ListaLigada *m)
{
    int i = m->inicio;
    while (i != -1)
    {
        printf("%d ", m->lista[i].valor);
        i = m->lista[i].proximo;
    }
    printf("\n");
}

int main(){
    ListaLigada Aluno;
    InicializarEstrutura(&Aluno, 5);
    Aluno.lista[0].valor = 15;
    Aluno.lista[1].valor = 28;
    Aluno.lista[2].valor = 9;
    Aluno.lista[3].valor = 31;
    Aluno.lista[4].valor = 2;
    int m = RetornarMaior(&Aluno);
    printf("O maior elemento e: %d\n", m);
    printf("A nova lista e: \n", m);
    ExibirLista(&Aluno);
    

    return 0;
}
