#ifndef INIMIGO_HPP
#define INIMIGO_HPP

#include "Entidade.hpp"

/**
 * Representa um adversário controlado pela Partida.
 * Herda diretamente de Entidade (não de Personagem).
 */
class Inimigo : public Entidade {
private:
    int multiplicadorDificuldade;

public:
    Inimigo(const std::string& nome, int hpMaximo, int multiplicadorDificuldade);

    void atacar(Entidade* alvo) override;
    void receberDano(int dano) override;

    int getMultiplicadorDificuldade() const;
};

#endif // INIMIGO_HPP
