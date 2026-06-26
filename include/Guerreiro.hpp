#ifndef GUERREIRO_HPP
#define GUERREIRO_HPP

#include "Personagem.hpp"

/**
 * Especialização de Personagem focada em defesa.
 * Possui um escudo que absorve parte do dano recebido.
 */
class Guerreiro : public Personagem {
private:
    int escudoAtual;

public:
    Guerreiro(const std::string& nome, int hpMaximo, int chanceCriticoBase, int escudoInicial);

    void atacar(Entidade* alvo) override;
    void receberDano(int dano) override; // absorve parte do dano com o escudo
    void bloquearAtaque();

    int getEscudoAtual() const;
};

#endif // GUERREIRO_HPP
