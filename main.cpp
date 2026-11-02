#include <iostream>
#include "Ecra.h"

int main() {
    Ecra meuEcra;
    meuEcra.limpa();
    meuEcra.desenhaMoldura(2, 2, 12, 40);

    meuEcra.posiciona(4, 4);
    meuEcra.escreveTexto("Simulador de Fabrica em Marte");

    meuEcra.posiciona(8, 4);
    meuEcra.escreveTexto("Checkpoint 1 - Teste do Ecra");

    meuEcra.mostra();

    return 0;
}