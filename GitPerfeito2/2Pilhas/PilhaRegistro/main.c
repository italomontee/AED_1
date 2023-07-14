#include <stdio.h>
#include <stdlib.h>
#include "PilhaRegistro.h"
int main() {
    PILHA hangar;
    Inicializar(&hangar);

    AdicionarAviao(&hangar, "Boeing 747", "Boeing", 2010);
    AdicionarAviao(&hangar, "Airbus A320", "Airbus", 2015);
    AdicionarAviao(&hangar, "Embraer E190", "Embraer", 2008);

    ListarAvioesHangar(&hangar);

    ListarPrimeiroAviao(&hangar);

    LancarAviao(&hangar, 2);

    printf("Apos lançar aviao:\n");
    ListarAvioesHangar(&hangar);

    return 0;
}
