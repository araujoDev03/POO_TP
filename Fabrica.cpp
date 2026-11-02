#include "Fabrica.h"
#include <cstdlib>
#include <ctime>

Fabrica::Fabrica(int l, int c) {
    linhas = (l < Settings::fabrica_max_linhas) ? l : Settings::fabrica_max_linhas;
    colunas = (c < Settings::fabrica_max_colunas) ? c : Settings::fabrica_max_colunas;
    creditos = Settings::fabrica_creditos_iniciais;
    instante = 0;

    // Inicializa tudo a solo (' ')
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            grelha[i][j] = ' ';
            quantidadeMaterial[i][j] = 0;
        }
    }

    inicializaAleatorio();
}

void Fabrica::inicializaAleatorio() {
    std::srand(std::time(nullptr));

    int craterasColocadas = 0;
    while (craterasColocadas < Settings::fabrica_num_crateras) {
        int l = std::rand() % linhas;
        int c = std::rand() % colunas;
        if (grelha[l][c] == ' ') {
            grelha[l][c] = '#';
            craterasColocadas++;
        }
    }

    int ferroColocados = 0;
    while (ferroColocados < Settings::fabrica_num_depositos_ferro) {
        int l = std::rand() % linhas;
        int c = std::rand() % colunas;
        if (grelha[l][c] == ' ') {
            grelha[l][c] = '%';
            quantidadeMaterial[l][c] = Settings::deposito_quantidade_min +
                (std::rand() % (Settings::deposito_quantidade_max - Settings::deposito_quantidade_min + 1));
            ferroColocados++;
        }
    }

    int silicioColocados = 0;
    while (silicioColocados < Settings::fabrica_num_depositos_silicio) {
        int l = std::rand() % linhas;
        int c = std::rand() % colunas;
        if (grelha[l][c] == ' ') {
            grelha[l][c] = '$';
            quantidadeMaterial[l][c] = Settings::deposito_quantidade_min +
                (std::rand() % (Settings::deposito_quantidade_max - Settings::deposito_quantidade_min + 1));
            silicioColocados++;
        }
    }

    int geloColocados = 0;
    while (geloColocados < Settings::fabrica_num_depositos_gelo) {
        int l = std::rand() % linhas;
        int c = std::rand() % colunas;
        if (grelha[l][c] == ' ') {
            grelha[l][c] = '~';
            quantidadeMaterial[l][c] = Settings::deposito_quantidade_min +
                (std::rand() % (Settings::deposito_quantidade_max - Settings::deposito_quantidade_min + 1));
            geloColocados++;
        }
    }
}

void Fabrica::desenha(Ecra& ecra) const {
    ecra.desenhaMoldura(0, 0, linhas + 3, colunas + 5);

    ecra.posiciona(1, 4);
    for (int j = 0; j < colunas; ++j) {
        char letraCol = 'A' + j;
        ecra.escreveCarater(letraCol);
    }

    for (int i = 0; i < linhas; ++i) {
        ecra.posiciona(2 + i, 1);
        char letraLinha = 'A' + i;
        ecra.escreveCarater(letraLinha);
        ecra.escreveCarater(' ');

        for (int j = 0; j < colunas; ++j) {
            ecra.escreveCarater(grelha[i][j]);
        }
    }
}

void Fabrica::lposicao(int l, int c) const {
    if (l < 0 || l >= linhas || c < 0 || c >= colunas) {
        std::cout << "\nPosicao fora dos limites da fabrica!\n";
        return;
    }

    std::cout << "\n--- Informacao da Posicao (" << static_cast<char>('A' + l) << static_cast<char>('A' + c) << ") ---\n";
    char tipo = grelha[l][c];
    if (tipo == ' ') {
        std::cout << "Terreno: Solo livre\n";
    } else if (tipo == '#') {
        std::cout << "Terreno: Cratera\n";
    } else if (tipo == '%') {
        std::cout << "Terreno: Deposito de Ferro\n";
        std::cout << "Quantidade disponivel: " << quantidadeMaterial[l][c] << " unidades\n";
    } else if (tipo == '$') {
        std::cout << "Terreno: Deposito de Silicio Bruto\n";
        std::cout << "Quantidade disponivel: " << quantidadeMaterial[l][c] << " unidades\n";
    } else if (tipo == '~') {
        std::cout << "Terreno: Deposito de Gelo\n";
        std::cout << "Quantidade disponivel: " << quantidadeMaterial[l][c] << " unidades\n";
    }
}