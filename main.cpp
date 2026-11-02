#include <iostream>
#include "Ecra.h"
#include "Fabrica.h"

int main() {
    Ecra meuEcra;
    meuEcra.limpa();

    Fabrica minhaFabrica(12, 20);

    minhaFabrica.desenha(meuEcra);

    meuEcra.mostra();

    return 0;
}