#include "Item.hpp"

Item::Item(const std::string& nome, const std::string& descricao)
    : nome(nome), descricao(descricao) {}

const std::string& Item::getNome() const {
    return nome;
}

const std::string& Item::getDescricao() const {
    return descricao;
}
