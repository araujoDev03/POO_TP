#include "Ecra.h"


Ecra::Ecra() : cursorLinha(0), cursorColuna(0){
    limpa();
}

void Ecra::limpa() {
    for (int i = 0; i < MAX_LINHAS; i++) {
        for (int j = 0; j < MAX_COLUNAS; j++) {
            buffer[i][j] = ' ';
        }
    }
}

void Ecra::posiciona(int linha, int coluna) {
    cursorLinha = linha;
    cursorColuna = coluna;
}

void Ecra::escreveCarater(char c) {
    if (cursorLinha >= 0 && cursorLinha < MAX_LINHAS && cursorColuna >= 0 && cursorColuna < MAX_COLUNAS) {
        buffer[cursorLinha][cursorColuna] = c;
        cursorColuna++;
        if (cursorColuna >= MAX_COLUNAS) {
            cursorColuna = 0;
            if (cursorLinha > MAX_LINHAS) {
            }else {
                cursorLinha++;
            }
        }
    }
}

void Ecra::escreveTexto(const char* texto) {
    int i = 0;
    while (texto[i] != '\0') {
        escreveCarater(texto[i]);
        i++;
    }
}


void Ecra::desenhaMoldura(int linha, int coluna, int altura, int largura) {
    for (int i = 0; i < altura; ++i) {
        for (int j = 0; j < largura; ++j) {
            int l = linha + i;
            int c = coluna + j;
            if (l >= 0 && l < MAX_LINHAS && c >= 0 && c < MAX_COLUNAS) {
                if (i == 0 || i == altura - 1) {
                    buffer[l][c] = '-'; // Topo e fundo
                } else if (j == 0 || j == largura - 1) {
                    buffer[l][c] = '|'; // Laterais
                } else {
                    buffer[l][c] = ' '; // Interior
                }
            }
        }
    }
}

void Ecra::mostra(int maxLinhas, int maxColunas){
    for (int i = 0; i < maxLinhas; ++i) {
        for (int j = 0; j < maxColunas; ++j) {
            std::cout << buffer[i][j];
        }
        std::cout << '\n';
    }
}


