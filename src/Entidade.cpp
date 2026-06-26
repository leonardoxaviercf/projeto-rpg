#include "Entidade.hpp"
#include <algorithm>

Entidade::Entidade(const std::string& nome, int hpMaximo)
    : nome(nome), hpMaximo(hpMaximo), hpAtual(hpMaximo) {}

bool Entidade::isVivo() const {
    return hpAtual > 0;
}

const std::string& Entidade::getNome() const {
    return nome;
}

int Entidade::getHpMaximo() const {
    return hpMaximo;
}

int Entidade::getHpAtual() const {
    return hpAtual;
}

void Entidade::setHpAtual(int hp) {
    hpAtual = std::max(0, std::min(hp, hpMaximo));
}
