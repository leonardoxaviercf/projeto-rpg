#include "Guerreiro.hpp"
#include "AcaoInvalidaException.hpp"
#include <iostream>
#include <cstdlib>
#include <algorithm>

Guerreiro::Guerreiro(const std::string& nome, int hpMaximo, int chanceCriticoBase, int escudoInicial)
    : Personagem(nome, hpMaximo, chanceCriticoBase), escudoAtual(escudoInicial) {}

void Guerreiro::atacar(Entidade* alvo) {
    if (!alvo || !alvo->isVivo()) {
        throw AcaoInvalidaException("Acao invalida: alvo inexistente ou ja derrotado.");
    }

    int danoBase = 12;
    bool critico = (std::rand() % 100) < calcularCriticoTotal();
    int danoFinal = critico ? danoBase * 2 : danoBase;

    std::cout << nome << " ataca " << alvo->getNome() << " com a espada";
    if (critico) std::cout << " (CRITICO!)";
    std::cout << " causando " << danoFinal << " de dano.\n";

    alvo->receberDano(danoFinal);
}

void Guerreiro::bloquearAtaque() {
    // Reforça o escudo temporariamente, reduzindo o próximo dano recebido
    escudoAtual += 5;
    std::cout << nome << " ergue o escudo, reforcando a defesa (+5).\n";
}

void Guerreiro::receberDano(int dano) {
    // O escudo absorve parte do dano antes de chegar ao HP
    int danoAbsorvido = std::min(dano, escudoAtual);
    escudoAtual -= danoAbsorvido;
    int danoRestante = dano - danoAbsorvido;

    if (danoAbsorvido > 0) {
        std::cout << "O escudo de " << nome << " absorve " << danoAbsorvido << " de dano.\n";
    }

    Personagem::receberDano(danoRestante);
}

int Guerreiro::getEscudoAtual() const {
    return escudoAtual;
}
