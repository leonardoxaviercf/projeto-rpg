#include "Entidade.hpp"

Entidade::Entidade(string n, int hpMax) : nome(n), hpMaximo(hpMax), hpAtual(hpMax) {}

bool Entidade::isVivo() const {
    return hpAtual > 0;
}

string Entidade::getNome() const {
    return nome;
}