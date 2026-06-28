#include "Mago.hpp"
#include "AcaoInvalidaException.hpp"
#include <algorithm>
#include <iostream>
#include <cstdlib>

namespace {
    constexpr int CUSTO_MANA_ATAQUE = 10;
}

Mago::Mago(const std::string& nome, int hpMaximo, int chanceCriticoBase, int manaMaxima)
    : Personagem(nome, hpMaximo, chanceCriticoBase),
      manaAtual(manaMaxima),
      manaMaxima(manaMaxima) {}

void Mago::atacar(Entidade* alvo) {
    if (!alvo || !alvo->isVivo()) {
        throw AcaoInvalidaException("Acao invalida: alvo inexistente ou ja derrotado.");
    }

    int danoBase;

    if (manaAtual >= CUSTO_MANA_ATAQUE) {
        consumirMana();
        danoBase = 18; // bola de fogo: mais dano, custa mana
        std::cout << nome << " conjura uma bola de fogo em " << alvo->getNome();
    } else {
        danoBase = 6; // sem mana, ataque físico fraco com o cajado
        std::cout << nome << " (sem mana) golpeia " << alvo->getNome() << " com o cajado";
    }

    bool critico = (std::rand() % 100) < calcularCriticoTotal();
    int danoFinal = critico ? danoBase * 2 : danoBase;

    if (critico) std::cout << " (CRITICO!)";
    std::cout << " causando " << danoFinal << " de dano.\n";

    alvo->receberDano(danoFinal);
}

void Mago::consumirMana() {
    if (manaAtual < CUSTO_MANA_ATAQUE) {
        throw AcaoInvalidaException("Acao invalida: mana insuficiente para conjurar.");
    }
    manaAtual -= CUSTO_MANA_ATAQUE;
}

void Mago::restaurarMana(int quantidade) {
    if (quantidade < 0) {
        quantidade = 0;
    }

    manaAtual = std::min(manaAtual + quantidade, manaMaxima);
}

int Mago::getManaAtual() const {
    return manaAtual;
}

int Mago::getManaMaxima() const {
    return manaMaxima;
}
