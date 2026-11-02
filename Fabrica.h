#ifndef FABRICA_H
#define FABRICA_H

#include "Settings.h"
#include "Ecra.h"

class Fabrica {
private:
    int linhas;
    int colunas;
    int creditos;
    int instante;
    
    char grelha[Settings::fabrica_max_linhas][Settings::fabrica_max_colunas];
    int quantidadeMaterial[Settings::fabrica_max_linhas][Settings::fabrica_max_colunas];

public:
    Fabrica(int l, int c);
    
    void inicializaAleatorio();
    void desenha(Ecra& ecra) const;
    
    int getLinhas() const { return linhas; }
    int getColunas() const { return colunas; }
};

#endif