#ifndef ECRA_H
#define ECRA_H
#include <iostream>

class Ecra {
private:
    static const int MAX_LINHAS = 40;
    static const int MAX_COLUNAS = 80;
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
    void mostra() const;
};

#endif