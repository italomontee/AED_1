#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[20];
    int idade;
    int matricula;
}Aluno;

typedef struct aux
{
    Aluno alun;
    struct aux* proximo;
}Elemento;

typedef struct 
{
    Elemento* inicio;
}ListaInteira;


//Inicializar a estrutura
void Inicializar(ListaInteira* m){
    m->inicio = NULL;
}

//Retornar quantidade de elementos validos
int Tamanho(ListaInteira* m){
    int tam=0;
    Elemento* i = m->inicio;
    while (i != NULL){
        tam ++;
        i = i->proximo;
    }
    return tam;
}

//Exibir elementos da estrutura
void Exibir(ListaInteira* m){
    Elemento* i = m->inicio;
    while (i != NULL)
    {
        printf("Nome: %s", i->alun.nome);
        printf("Idade: %d", i->alun.idade);
        printf("Matricula: %d",i->alun.matricula);
        printf("\n");
        i = i->proximo;
    }
}

//Buscar elementos da estrutura Sequencial
Elemento* BuscarSequencial(ListaInteira*m, Aluno alun){
    Elemento* i= m->inicio;
    
    while (i != NULL)
    {
        if (m->inicio->alun.matricula == alun.matricula)
        {
            return i;
        }
        else {
            i = i->proximo;
        }
    }
    //caso a chave n seja encontrada
    return NULL;
    
}

Elemento* BuscaSequencialOrdenada (ListaInteira* m, Aluno alun){
    Elemento* pos = m->inicio;
    while (pos != NULL && pos->alun.matricula < alun.matricula){   
        pos = pos->proximo; 
    }

    if (pos->alun.matricula == alun.matricula){
        return pos;
    }
    else
    {
        return NULL;
    }
}

//Inserir elementos ordenados e sem repetição
void Inserir(ListaInteira*m, Aluno alun){
    Elemento* i = m->inicio;
    Elemento* pos_inserir = NULL;
    //exc: negação
    if (i == NULL){
        return;
    }

    while (i != NULL && m->inicio->alun.matricula<alun.matricula)
    {
        pos_inserir = i;
        i = i->proximo;            
    }

    //exc: igualdade
    if (i != NULL && i->alun.matricula == alun.matricula)
    {
        return;
    }

    i = malloc (sizeof(Elemento));

    i->alun = alun;
    i->proximo = NULL;
    if (pos_inserir == NULL)
    {
        i->proximo = m->inicio;
        m->inicio = i;
    }else{
        i->proximo = pos_inserir->proximo;
        pos_inserir->proximo = i;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
