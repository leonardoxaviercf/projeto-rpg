#ifndef MAGO_HPP
#define MAGO_HPP

#include "Personagem.hpp"

/**
 * Especialização de Personagem focada em ataques mágicos.
 * Consome mana para atacar; sem mana, ataca com dano reduzido.
 */
class Mago : public Personagem {
private:
    int manaAtual;
    int manaMaxima;

public:
    Mago(const std::string& nome, int hpMaximo, int chanceCriticoBase, int manaMaxima);

    void atacar(Entidade* alvo) override;
    void consumirMana();

    int getManaAtual() const;
};

#endif // MAGO_HPP
