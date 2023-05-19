#include <stdlib.h>
#include <stdio.h>


#include "12_05_2023_01.h"
   

int main(){
    Cubo *cubo = (Cubo *) malloc(sizeof(cubo));
    PreencherDadosCubo(cubo);
    ValoresCubo(cubo);
}
