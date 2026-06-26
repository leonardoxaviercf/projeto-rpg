#include "PocaoCura.hpp"
#include "Personagem.hpp"

PocaoCura::PocaoCura(const std::string& nome, const std::string& descricao, int valorCura)
    : Item(nome, descricao), valorCura(valorCura) {}

void PocaoCura::aplicarEfeito(Personagem* p) {
    p->setHpAtual(p->getHpAtual() + valorCura);
}

int PocaoCura::getValorCura() const {
    return valorCura;
}
