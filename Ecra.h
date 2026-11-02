#ifndef ECRA_H
#define ECRA_H
#include <iostream>
#include "Settings.h"

class Ecra {
private:
    static const int MAX_LINHAS = Settings::ecra_max_linhas;
    static const int MAX_COLUNAS = Settings::ecra_max_colunas;
    char buffer[MAX_LINHAS][MAX_COLUNAS];
    int cursorLinha;
    int cursorColuna;

public:
    Ecra();

    void limpa();
    void posiciona(int linha, int coluna);
    void escreveCarater(char c);
    void escreveTexto(const char* texto);
    void desenhaMoldura(int linha, int coluna, int altura, int largura);
    void mostra(int maxLinhas = 40, int maxColunas = 80);
};

#endif