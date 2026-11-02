#include <iostream>
#include "Ecra.h"
#include "Fabrica.h"

void executarComandoFim() {
    std::cout << "\n[Comando fim executado] A terminar simulador com seguranca...\n";
}

int main() {
    Ecra meuEcra;
    meuEcra.limpa();
    Fabrica minhaFabrica(10, 15);
    minhaFabrica.desenha(meuEcra);
    meuEcra.mostra(minhaFabrica.getLinhas() + 3, minhaFabrica.getColunas() + 5);

    minhaFabrica.lposicao(2, 3);

    executarComandoFim();

    return 0;
}