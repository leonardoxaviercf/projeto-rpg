#ifndef BONUS_ATRIBUTO_HPP
#define BONUS_ATRIBUTO_HPP

#include "Item.hpp"

/**
 * Item consumível que aumenta permanentemente o HP máximo do Personagem
 * que o utiliza (representa um "bônus de dano/atributo" via aumentoDano).
 */
class BonusAtributo : public Item {
private:
    int aumentoDano;

public:
    BonusAtributo(const std::string& nome, const std::string& descricao, int aumentoDano);

    void aplicarEfeito(Personagem* p) override;

    int getAumentoDano() const;
};

#endif // BONUS_ATRIBUTO_HPP
