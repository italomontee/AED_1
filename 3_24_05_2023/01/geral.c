#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int tamanho;
    int* vetor;
}lista;

void *CriarNovaLista(int tamanho)
{
    
    lista *local =  malloc(sizeof(lista));
    local->vetor =  malloc(sizeof(int) * tamanho);
    local->tamanho = tamanho;
    return local;
}

void PreencherLista(lista *endereco)
{
    for (int i = 0; i < endereco->tamanho; i++)
    {
        printf("Elemento [%d]: ", i);
        scanf("%d", &endereco->vetor[i]);
    }
    
}

void ImprimirLista(lista *endereco)
{
    for (int i = 0; i < endereco->tamanho; i++)
    {
        printf("%d\n", endereco->vetor[i]);
    }
            
        
}

void BuscarNaLista(int n, lista *endereco)
{
    int count = 0;
    for (int i = 0; i < endereco->tamanho; i++)
    {
        if (n == (endereco->vetor[i]))
        {
    
            printf("O valor foi encontrado e estar na posicao %d\n", i);
            count++;
        }
        
    }
    if (count == 0)
    {
        printf("O elemento nao foi encontrado\n");
    }
    
    
}

void MaiorElementoIterativo(lista *endereco, int tamanho)
{
    int aux=0;
    for (int i = 0; i < tamanho; i++)
    {
        if (i==0){
            aux = endereco->vetor[i];
        }
        if (endereco->vetor[i]>aux)
        {
            aux = endereco->vetor[i];
        }
    }
    
    printf("O maior elemento interativo: %d\n", aux);
}

int MaiorElementoRecursivo(lista *endereco, int tamanho, int aux)
{
    if(tamanho == 0)
    {
        printf("O maior elemento (recursivo) e: %d\n", aux);
        return 0;
    }

    else
    {
        if (endereco->vetor[tamanho-1]>aux)
        {
            aux = endereco->vetor[tamanho-1];
            
        }
        return MaiorElementoRecursivo(endereco, tamanho-1, aux);
    }
}

void MenorElementoIterativo(lista *endereco, int tamanho)
{
    
int aux=0;
    for (int i = 0; i < tamanho; i++)
    {
        if (i==0){
            aux = endereco->vetor[i];
        }
        if (endereco->vetor[i]<aux)
        {
            aux = endereco->vetor[i];
        }
    }
    
    printf("O menor elemento interativo: %d\n", aux);
}

int MenorElementoRecursivo(lista *endereco, int tamanho, int aux)
{
    if(tamanho == 0)
    {
        printf("O menor elemento (recursivo) e: %d\n", aux);
        return 0;
    }

    else
    {
        if (endereco->vetor[tamanho-1]<aux)
        {
            aux = endereco->vetor[tamanho-1];
           
        }  
        return MenorElementoRecursivo(endereco, tamanho-1, aux);
}
}

void SomaIterativa(lista *endereco, int tamanho)
{
    int aux=0;
    for (int i = 0; i < tamanho; i++)
    {
        aux += endereco->vetor[i];
    }
    printf("Soma iterativa: %d\n", aux);
}

int SomaRecursiva(lista *endereco, int tamanho, int aux)
{
    if (tamanho == 0)
    {
        printf("A soma recursiva e: %d\n", aux);
        return aux;
    }

    else
    {
        aux += endereco->vetor[tamanho-1];
        return SomaRecursiva(endereco, tamanho - 1, aux);
    }
    
}

void ProdutoInterativo(lista *endereco,int tamanho)
{
    int aux=1;
    for (int i = 0; i < tamanho; i++)
    {
        aux *= endereco->vetor[i];
    }
    printf("Produto iterativo: %d\n", aux);
}

int ProdutoRecursivo(lista *endereco, int tamanho, int aux)
{
    if (tamanho == 0)
    {
        printf("O produto recursivo e: %d\n", aux);
        return aux;
    }

    else
    {
        aux = (endereco->vetor[tamanho-1])*aux;
        return ProdutoRecursivo(endereco, tamanho - 1, aux);
    }
    
}

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