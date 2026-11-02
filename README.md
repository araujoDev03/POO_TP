# Simulador de Fábrica em Marte (Mars Factory Simulator) - Checkpoint 1

Projeto desenvolvido no âmbito da unidade curricular de Programação Orientada a Objetos / Laboratório de Software.

> **Nota:** *Este README.md foi integralmente gerado com o auxílio de Inteligência Artificial (IA).*

## 🚀 Sobre o Projeto
O objetivo deste projeto é desenvolver um simulador em C++ que modela uma fábrica em Marte. Neste primeiro **Checkpoint 1**, o foco centrou-se na implementação da arquitetura base, gestão de ecrã virtual com buffer, geração estocástica de terreno e recursos, e encapsulamento modular das classes principais.

## 🛠️ Arquitetura e Componentes
O projeto encontra-se modularizado em ficheiros de cabeçalho (`.h`) e implementação (`.cpp`), respeitando os princípios de encapsulamento e separação de responsabilidades:
- **`Settings`**: Classe/Estrutura que concentra todas as constantes globais do simulador (dimensões máximas, número de crateras, depósitos de recursos, créditos iniciais, etc.).
- **`Ecra`**: Classe responsável pela gestão de um ecrã virtual baseado num buffer de carateres em memória. Permite desenhar molduras, réguas de coordenadas (letras para linhas e colunas) e controlar o output para a consola de forma limpa.
- **`Fabrica`**: Classe que gere a lógica do jogo, incluindo a grelha do terreno, a distribuição aleatória de crateras (`#`), depósitos de ferro (`%`), silício (`$`) e gelo (`~`), além de disponibilizar funcionalidades de consulta de posições (`lposicao`).

## ⚙️ Funcionalidades Implementadas (Checkpoint 1)
- [x] Sistema de renderização via buffer (`Ecra`) com moldura dinâmica e réguas alfabéticas.
- [x] Inicialização estocástica do terreno com crateras e depósitos de matérias-primas.
- [x] Lógica de consulta detalhada de posições (`lposicao`) com indicação do tipo de terreno e quantidades disponíveis.
- [x] Estrutura preparada para encerramento limpo do programa e gestão automática de memória em pilha (*stack*).

## 💻 Como Compilar e Executar
Certifica-te de que tens um compilador de C++ compatível (como GCC, Clang ou MSVC) e o ambiente configurado (por exemplo, CLion ou Visual Studio).

1. Compila os ficheiros fonte em conjunto (`main.cpp`, `Ecra.cpp`, `Fabrica.cpp`):
   ```bash
   g++ main.cpp Ecra.cpp Fabrica.cpp -o mars_simulator
