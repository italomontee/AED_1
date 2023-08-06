#ifndef CALCULOS_H_INCLUDE
#define CALCULOS_H_INCLUDE

typedef struct aux
{
    int numero;
    int ocorrencias;
    struct aux* proximo;
} Elemento;

typedef struct 
{
    Elemento* inicio;
} ListaInteira;

void Inicializar(ListaInteira* m);
int Tamanho(ListaInteira* m);
void Exibir(ListaInteira* m);
int BuscarSequencial(ListaInteira* m, int num);
int ContarFrequencia(ListaInteira *m, int valor);
void InserirElemento(ListaInteira* m, int num);
void Inserir(ListaInteira* m);
void ExcluirElemento(ListaInteira* m, int num);


#endif
 