#include "BonusAtributo.hpp"
#include "Personagem.hpp"

BonusAtributo::BonusAtributo(const std::string& nome, const std::string& descricao, int aumentoDano)
    : Item(nome, descricao), aumentoDano(aumentoDano) {}

void BonusAtributo::aplicarEfeito(Personagem* p) {
    // O bônus de dano é traduzido em aumento permanente de chance de critico,
    // já que esse é o atributo de ataque exposto pelo diagrama em Personagem.
    p->aumentarChanceCritico(aumentoDano);
}

int BonusAtributo::getAumentoDano() const {
    return aumentoDano;
}
