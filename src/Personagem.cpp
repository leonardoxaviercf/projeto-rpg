#include "Personagem.hpp"
#include "AcaoInvalidaException.hpp"
#include <iostream>
#include <cstdlib>

Personagem::Personagem(const std::string& nome, int hpMaximo, int chanceCriticoBase)
    : Entidade(nome, hpMaximo),
      estadoAtual(EstadoVida::CHEIA),
      chanceCriticoBase(chanceCriticoBase),
      andarAtual(1) {}

void Personagem::receberDano(int dano) {
    if (dano < 0) dano = 0;
    setHpAtual(getHpAtual() - dano);
    atualizarEstadoVida();
}

void Personagem::usarItem(int indiceItem) {
    // Lança AcaoInvalidaException se o índice for inválido (relação "Lança" no diagrama)
    if (indiceItem < 0 || static_cast<size_t>(indiceItem) >= inventario.size()) {
        throw AcaoInvalidaException(
            "Acao invalida: indice de item fora do inventario (" + std::to_string(indiceItem) + ")"
        );
    }

    Item* item = inventario[indiceItem].get();
    item->aplicarEfeito(this);
    std::cout << nome << " usou " << item->getNome() << "!\n";

    // Itens consumíveis somem do inventário após o uso
    inventario.erase(inventario.begin() + indiceItem);
    atualizarEstadoVida();
}

void Personagem::atualizarEstadoVida() {
    // "Máquina de Estados": classifica o HP atual em uma faixa de EstadoVida
    if (hpAtual <= 0) {
        estadoAtual = EstadoVida::MORTO;
    } else {
        double proporcao = static_cast<double>(hpAtual) / static_cast<double>(hpMaximo);
        if (proporcao >= 0.75) {
            estadoAtual = EstadoVida::CHEIA;
        } else if (proporcao >= 0.5) {
            estadoAtual = EstadoVida::ALTA;
        } else if (proporcao >= 0.25) {
            estadoAtual = EstadoVida::MEDIA;
        } else {
            estadoAtual = EstadoVida::BAIXA;
        }
    }
}

int Personagem::calcularCriticoTotal() const {
    // Critico base + bônus crescente conforme o andar avança (incentiva progressão)
    return chanceCriticoBase + (andarAtual - 1) * 2;
}

void Personagem::adicionarItem(std::unique_ptr<Item> item) {
    inventario.push_back(std::move(item));
}

size_t Personagem::tamanhoInventario() const {
    return inventario.size();
}

void Personagem::listarInventario() const {
    if (inventario.empty()) {
        std::cout << "Inventario vazio.\n";
        return;
    }
    for (size_t i = 0; i < inventario.size(); ++i) {
        std::cout << "  [" << i << "] " << inventario[i]->getNome()
                   << " - " << inventario[i]->getDescricao() << "\n";
    }
}

EstadoVida Personagem::getEstadoAtual() const {
    return estadoAtual;
}

int Personagem::getAndarAtual() const {
    return andarAtual;
}

void Personagem::setAndarAtual(int andar) {
    andarAtual = andar;
}

void Personagem::avancarAndar() {
    andarAtual++;
}

void Personagem::aumentarChanceCritico(int incremento) {
    chanceCriticoBase += incremento;
}

int Personagem::getChanceCriticoBase() const {
    return chanceCriticoBase;
}
