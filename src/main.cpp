#include "Partida.hpp"

int main() {
    Partida partida("estatisticas.txt");
    partida.iniciarLoop();
    return 0;
}

// g++ -std=c++17 -Wall -Wextra -Iinclude src/*.cpp -o jogo
// .\jogo.exe