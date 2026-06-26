#ifndef POCAO_CURA_HPP
#define POCAO_CURA_HPP

#include "Item.hpp"

/**
 * Item consumível que restaura HP do Personagem que o utiliza.
 */
class PocaoCura : public Item {
private:
    int valorCura;

public:
    PocaoCura(const std::string& nome, const std::string& descricao, int valorCura);

    void aplicarEfeito(Personagem* p) override;

    int getValorCura() const;
};

#endif // POCAO_CURA_HPP
