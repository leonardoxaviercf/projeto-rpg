#ifndef BONUS_ATRIBUTO_HPP
#define BONUS_ATRIBUTO_HPP

#include "Item.hpp"

/**
 * Item consumivel que aumenta permanentemente a chance de critico do
 * Personagem que o utiliza.
 */
class BonusAtributo : public Item {
private:
    int aumentoCritico;

public:
    BonusAtributo(const std::string& nome, const std::string& descricao, int aumentoCritico);

    void aplicarEfeito(Personagem* p) override;

    int getAumentoDano() const;
};

#endif // BONUS_ATRIBUTO_HPP
