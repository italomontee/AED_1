#include <string.h>
#include <stdio.h>

//TDA String em C

int main(){
    char string[100];
    char caractere;
    int tamanho;
    int count=0;
//Input da string

    printf("Digite uma string: ");
    fgets(string, 100, stdin);


    printf("A string: %s\n", string);

//Input do caractere
    printf("Digite um caractere: ");
    scanf("%c", &caractere);

    printf("O caractere: %c\n", caractere);


//identificar o caractere na frase
    tamanho = strlen(string);
    for (int i = 0; i < tamanho; i++)
    {
        if (string[i]==caractere)
        {
            count++;
        }
        
    }
    printf("count: %d", count);
    


    return 0;
}

