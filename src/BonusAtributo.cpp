#include "BonusAtributo.hpp"
#include "Personagem.hpp"

BonusAtributo::BonusAtributo(const std::string& nome, const std::string& descricao, int aumentoCritico)
    : Item(nome, descricao), aumentoCritico(aumentoCritico) {}

void BonusAtributo::aplicarEfeito(Personagem* p) {
    p->aumentarChanceCritico(aumentoCritico);
}

int BonusAtributo::getAumentoDano() const {
    return aumentoCritico;
}
