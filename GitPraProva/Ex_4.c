#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct
{
    int matricula;
    int idade;
    char nome[20];
    int nfilhos;
} Aluno ;

typedef struct 
{
    Aluno alun;
    int proximo;
} Elemento;

typedef struct 
{
    Elemento ListadeAlun[MAX];
    int disponivel;
    int inicio;
} ListaInteira;



void InicializarEstrutura(ListaInteira *m, int n){
    for (int i = 0; i < n; i++) {
        m->ListadeAlun[i].proximo = i + 1;
    }

    m->ListadeAlun[n - 1].proximo = -1;
    m->disponivel = 0;
    m->inicio = 0;
}

int BuscarElemento (ListaInteira *m, int chave) {
    int atual = m->inicio;
    while (atual != -1 && m->ListadeAlun[atual].alun.matricula < chave)
    {
        atual = m->ListadeAlun[atual].proximo;
    }
    if (atual != -1 && m->ListadeAlun[atual].alun.matricula == chave){
        return atual;
    }
    else
    {
        return -1;
    }  
}

void ExcluirElemento(ListaInteira *m, int cod) {
    int pos = BuscarElemento(m, cod);
    int i = m->inicio;
    int pos_exc = -1;
    while (i != -1 && m->ListadeAlun[i].alun.matricula != cod) {
        pos_exc = i;
        i = m->ListadeAlun[i].proximo;
    }

    if (pos_exc == -1) {
        m->inicio = m->ListadeAlun[pos].proximo;
    } else {
        m->ListadeAlun[pos_exc].proximo = m->ListadeAlun[pos].proximo;
    }
    m->ListadeAlun[pos].proximo = m->disponivel;
    m->disponivel = pos;
}


int RetornarMaiorIdade(ListaInteira* m){
    int maior = 0;
    int pos_maior = -1;
    int i = m->inicio;
    int t = 0;
    
    while (i != -1){
        if (t == 0 || m->ListadeAlun[i].alun.idade > maior) {
            maior = m->ListadeAlun[i].alun.idade;
            pos_maior = i;
        }
        i = m->ListadeAlun[i].proximo;
        t++;
    }

    if (pos_maior != -1) {
        ExcluirElemento(m, m->ListadeAlun[pos_maior].alun.matricula);
    }

    return maior;
}



void ExibirLista (ListaInteira *m){
    int i = m->inicio;
    while (i != -1)
    {
        printf("Nome: %s\n", m->ListadeAlun[i].alun.nome);
        printf("Idade: %d\n", m->ListadeAlun[i].alun.idade);
        printf("Matricula: %d\n", m->ListadeAlun[i].alun.matricula);
        i = m->ListadeAlun[i].proximo;
    }
    
}
int main(){
    ListaInteira Aluno;
    InicializarEstrutura(&Aluno, 5);

    strcpy(Aluno.ListadeAlun[0].alun.nome, "Daniel");
    strcpy(Aluno.ListadeAlun[1].alun.nome, "Suza");
    strcpy(Aluno.ListadeAlun[2].alun.nome,"Danilo");
    strcpy(Aluno.ListadeAlun[3].alun.nome, "Camila");
    strcpy(Aluno.ListadeAlun[4].alun.nome, "Carlos");

    Aluno.ListadeAlun[0].alun.idade = 21;
    Aluno.ListadeAlun[1].alun.idade = 19;
    Aluno.ListadeAlun[2].alun.idade = 24;
    Aluno.ListadeAlun[3].alun.idade = 18;
    Aluno.ListadeAlun[4].alun.idade = 22;

    Aluno.ListadeAlun[0].alun.matricula = 001;
    Aluno.ListadeAlun[1].alun.matricula = 002;
    Aluno.ListadeAlun[2].alun.matricula = 003;
    Aluno.ListadeAlun[3].alun.matricula = 004;
    Aluno.ListadeAlun[4].alun.matricula = 005;

    Aluno.ListadeAlun[0].alun.nfilhos = 0;
    Aluno.ListadeAlun[1].alun.nfilhos = 0;
    Aluno.ListadeAlun[2].alun.nfilhos = 1;
    Aluno.ListadeAlun[3].alun.nfilhos = 0;
    Aluno.ListadeAlun[4].alun.nfilhos = 1;
    int m = RetornarMaiorIdade(&Aluno);
    printf("O maior elemento e: %d\n", m);
    printf("A nova lista e: \n");
    ExibirLista(&Aluno);
    

    return 0;
}