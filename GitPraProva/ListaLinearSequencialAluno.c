#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
char nome[50];
int codigo;
int idade;
int nfilhos;
}ALUNO;

typedef struct{
ALUNO lista[20];
int quantidade;
}LISTA;

//INICIALIZAR LISTA: //////////////////
void inicializar(LISTA* lista){
lista->quantidade = 0;
}

// INSERIR NOVO ELEMENTO: ///////////////
void inserir(LISTA* lista){
if(lista->quantidade == 20){
    return -1;
}
ALUNO novo;
char nome[50];
printf("Insira o nome do aluno: ");
scanf("%s", nome);
strcpy(novo.nome, nome);
printf("Insira o codigo do aluno: ");
scanf("%d", &novo.codigo);
printf("Insira a idade do aluno: ");
scanf("%d", &novo.idade);
printf("Insira o numero de filhos: ");
scanf("%d", &novo.nfilhos);
if(lista->quantidade == 0){
    lista->lista[0] = novo;

}
else{
    int i = lista->quantidade - 1;

    while(i>= 0 && novo.codigo < lista->lista[i].codigo){
        lista->lista[i+1] = lista->lista[i];
        i--;
    }
    lista->lista[i+1] = novo;

}
lista->quantidade++;
printf("\nAluno inserido com sucesso\n");
}

// IMPRIMIR LISTA: //////////////////////
void imprimir(LISTA *lista){
int i;
for(i = 0; i < lista->quantidade; i++){
    printf("Nome: %s\n", lista->lista[i].nome);
    printf("Codigo: %d\n", lista->lista[i].codigo);
    printf("Idade: %d\n", lista->lista[i].idade);
    printf("Numero de filhos: %d\n\n", lista->lista[i].nfilhos);
}}

// QUANTIDADE DE ELEMENTOS://////////////
void quantidade(LISTA* lista){
printf("\nAtualmente a lista possui: %d elementos\n", lista->quantidade);
}

// BUSCA SEQUENCIAL: /////////////////
void busca(LISTA* lista, int matricula){
int i;
for(i = 0; i < lista->quantidade; i++){
    if(lista->lista[i].codigo == matricula){
        printf("\nAluno encontrado na posicao %d\n", i);
        break;
    }
}}

// BUSCA BINARIA: ////////////////
void buscabin(LISTA* lista, int matricula){
int esquerda = 0;
int direita = lista->quantidade-1;
while(esquerda <= direita){
    int meio = (esquerda+direita)/2;
    if(lista->lista[meio].codigo == matricula){
        printf("\nAluno encontrado na posicao: %d\n", meio);
        break;
    }
    if(lista->lista[meio].codigo < matricula){
        esquerda = meio+1;
        }
    if(lista->lista[meio].codigo > matricula){
        direita = meio - 1;
    }
}}


// EXCLUIR ELEMENTO: ////////////////////
void excluir(LISTA* lista, int matricula){
int i, j;
int encontrado;
for(i = 0; i < lista->quantidade; i++){
    if(lista->lista[i].codigo == matricula){
        encontrado = i;
    }}
    
for(j = encontrado; j <lista->quantidade; j++){

    lista->lista[j] = lista->lista[j+1];
}
lista->quantidade--;
}

int main()
{

    LISTA lista;
    int opcao, matricula;
    inicializar(&lista);
    do{
    printf("\nTabela:\n");
    printf("[1] Inserir um elemento\n");
    printf("[2] Exibir lista\n");
    printf("[3] Excluir um elemento\n");
    printf("[4] Buscar um elemento sequencialmente\n");
    printf("[5] Buscar um elemento por busca binaria\n");
    printf("[6] Quantidade de elementos\n");
    printf("[7] Finalizar.\n");
    scanf("%d", &opcao);
    switch(opcao){
        case 1:
            inserir(&lista);
            break;

        case 2:
            imprimir(&lista);
            break;
        case 3:
            printf("\nDigite a matricula que deseja excluir: ");
            scanf("%d", &matricula);
            excluir(&lista, matricula);
            break;
        case 4:
            printf("\nDigite a matricula que deseja buscar: ");
            scanf("%d", &matricula);
            busca(&lista, matricula);
            break;
        case 5:
            printf("\nDigite a matricula que deseja buscar: ");
            scanf("%d", &matricula);
            buscabin(&lista, matricula);
            break;
        case 6:
            quantidade(&lista);
            break;
        case 7:
            printf("\nFinalizando...");
        default:
            printf("\nSelecione um valor valido da tabela.");
            }
    }while(opcao!=7);
    return 0;
}