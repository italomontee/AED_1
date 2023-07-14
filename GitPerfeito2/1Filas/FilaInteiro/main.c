#include <stdio.h>
#include <stdlib.h>
#include "FilaInteiro.h"
int main()
{
    FILA f;
    Inicializar(&f);
    NUMERO n;
    n.num = 5;
    EntrarNaFila(&f, n);

    n.num = 7;
    EntrarNaFila(&f, n);

    n.num = 8;
    FurarFila(&f,n, 1);
    Mostrar(&f);

    return 0;
}
