#include "Inimigo.hpp"
#include "AcaoInvalidaException.hpp"
#include <iostream>
#include <cstdlib>

Inimigo::Inimigo(const std::string& nome, int hpMaximo, int multiplicadorDificuldade)
    : Entidade(nome, hpMaximo), multiplicadorDificuldade(multiplicadorDificuldade) {}

void Inimigo::atacar(Entidade* alvo) {
    if (!alvo || !alvo->isVivo()) {
        throw AcaoInvalidaException("Acao invalida: alvo inexistente ou ja derrotado.");
    }

    int danoBase = 8 * multiplicadorDificuldade;
    std::cout << nome << " ataca " << alvo->getNome()
               << " causando " << danoBase << " de dano.\n";
    alvo->receberDano(danoBase);
}

void Inimigo::receberDano(int dano) {
    if (dano < 0) dano = 0;
    setHpAtual(hpAtual - dano);
}

int Inimigo::getMultiplicadorDificuldade() const {
    return multiplicadorDificuldade;
}
