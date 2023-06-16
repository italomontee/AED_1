#include <stdio.h>
#include <stdlib.h>

typedef struct aux
{
    int numero;
    struct aux* proximo;
} Elemento;

typedef struct 
{
    Elemento* inicio;
} ListaInteira;


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
        tam++;
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
        printf("%d ", i->numero);
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
            i = i->proximo;
        }
        indice++;
    }
    // Caso o número não seja encontrado
    return -1;
}

BuscaBinaria(ListaInteira* m, int num){
   Elemento* inicio = m->inicio;
    int esquerda = 0;
    int direita = Tamanho(m) - 1;
    int meio;

    while (esquerda <= direita)
    {
        meio = (esquerda + direita) / 2;

        Elemento* atual = inicio;
        for (int i = 0; i < meio; i++)
        {
            atual = atual->proximo;
        }

        if (atual->numero == num)
        {
            return meio;
        }
        else if (atual->numero < num)
        {
            esquerda = meio + 1;
        }
        else
        {
            direita = meio - 1;
        }
    }

    // Caso o número não seja encontrado
    return -1;
 
}

// Inserir elementos
void InserirElemento(ListaInteira* m, int num)
{
    Elemento* i = m->inicio;
    Elemento* pos_inserir = NULL;

    if (i == NULL)
    {
        i = malloc(sizeof(Elemento));
        i->numero = num;
        i->proximo = NULL;
        m->inicio = i;
        return;
    }

    while (i != NULL && m->inicio->numero < num)
    {
        if (i->numero == num){
            return;
        }
        pos_inserir = i;
        i = i->proximo;
    }

    

    i = malloc(sizeof(Elemento));
    i->numero = num;
    i->proximo = NULL;

    if (pos_inserir == NULL)
    {
        i->proximo = m->inicio;
        m->inicio = i;
    }
    else
    {
        i->proximo = pos_inserir->proximo;
        pos_inserir->proximo = i;
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

int main()
{
    ListaInteira lista;
    int opcao, num;

    Inicializar(&lista);

    do
    {
        printf("\nTabela:\n");
        printf("[1] Inserir um numero\n");
        printf("[2] Exibir lista\n");
        printf("[3] Excluir um numero\n");
        printf("[4] Buscar um numero sequencialmente\n");
        printf("[5] Buscar um numero binariamente\n");
        printf("[6] Quantidade de elementos\n");
        printf("[7] Finalizar.\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                Inserir(&lista);
                break;
            case 2:
                Exibir(&lista);
                break;
            case 3:
                printf("\nDigite o numero que deseja excluir: ");
                scanf("%d", &num);
                ExcluirElemento(&lista, num);
                break;
            case 4:
                printf("\nDigite o numero que deseja buscar: ");
                scanf("%d", &num);
                int pos = BuscarSequencial(&lista, num);
                if (pos != -1){
                    printf("Numero encontrado na posicao %d.\n", pos);
                }
                else{
                    printf("Numero nao encontrado.\n");
                }
                break;
            case 5:
                printf("\nDigite o numero que deseja buscar: ");
                scanf("%d", &num);
                pos = BuscaBinaria(&lista, num);
                if (pos != -1){
                    printf("Numero encontrado na posicao %d.\n", pos);
                }
                else{
                    printf("Numero nao encontrado.\n");
                }
                break;
            case 6:
                printf("Quantidade de elementos: %d\n", Tamanho(&lista));
                break;
                
            case 7:
                printf("\nFinalizando...\n");
                break;
            default:
                printf("\nSelecione um valor válido da tabela.\n");
        }
    } while (opcao != 6);

    return 0;
}
