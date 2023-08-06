#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "calculos.h"

int main()
{
    time_t now;

    time(&now);

    printf("Data e hora de entrega %s\n", ctime(&now));
    printf("Italo Guilherme Monte\n");
    printf("Numero do exercicio: 027\n");

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
        printf("[5] Quantidade de elementos\n");
        printf("[6] Quantidade de vezes\n");
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
                if (pos != -1)
                {
                    printf("Numero encontrado na posicao %d.\n", pos);
                }
                else
                {
                    printf("Numero nao encontrado.\n");
                }
                break;
            case 5:
                printf("Quantidade de elementos: %d\n", Tamanho(&lista));
                break;
            case 6:
                printf("Qual numero deseja: \n");
                scanf("%d", &num);
                int qtd = ContarFrequencia(&lista, num);
                printf("Numero encontrado %d vezes", qtd);
                break;
            case 7:
                printf("\nFinalizando...\n");
                break;
            default:
                printf("\nSelecione um valor válido da tabela.\n");
        }
    } while (opcao != 7);

    return 0;






}
