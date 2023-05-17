#include <stdlib.h>
#include <stdio.h>

typedef struct Cubo
{
    int aresta1;
    int aresta2;
    int aresta3;
}Cubo;

void PreencherDadosCubo(Cubo *cubo){
    printf("ARESTA 1: ");
    scanf("%d", &(cubo->aresta1));
    printf("ARESTA 2: ");
    scanf("%d", &(cubo->aresta2));
    printf("ARESTA 3: ");
    scanf("%d", &(cubo->aresta3));
}

void ValoresCubo(Cubo *cubo){
    printf("Volume: %d\n", ((cubo->aresta1)*(cubo->aresta2)*(cubo->aresta3)));
    printf("Area Total: %d\n", (2*((cubo->aresta1)*(cubo->aresta2))+2*((cubo->aresta1)*(cubo->aresta3))+2*((cubo->aresta2)*(cubo->aresta3))));

}   

int main(){
    Cubo *cubo = (Cubo *) malloc(sizeof(cubo));
    PreencherDadosCubo(cubo);
    ValoresCubo(cubo);
}