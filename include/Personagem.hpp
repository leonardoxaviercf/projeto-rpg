#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP

#include "Entidade.hpp"
#include "EstadoVida.hpp"
#include "Item.hpp"
#include <vector>
#include <memory>
#include <string>

/**
 * Classe abstrata que representa o jogador.
 * Herda de Entidade e é a base para Guerreiro e Mago.
 */
class Personagem : public Entidade {
protected:
    EstadoVida estadoAtual;
    int chanceCriticoBase;
    int andarAtual;
    std::vector<std::unique_ptr<Item>> inventario; // Item[] inventario

public:
    Personagem(const std::string& nome, int hpMaximo, int chanceCriticoBase);
    virtual ~Personagem() override = default;

    //cada subclasse (Guerreiro/Mago) ataca de forma diferente
    virtual void atacar(Entidade* alvo) override = 0;

    // Métodos concretos, comuns a qualquer Personagem
    virtual void receberDano(int dano) override;
    void usarItem(int indiceItem);
    void atualizarEstadoVida();
    int calcularCriticoTotal() const;

    // Gerenciamento do inventário
    void adicionarItem(std::unique_ptr<Item> item);
    size_t tamanhoInventario() const;
    void listarInventario() const;

    // Getters/setters de apoio ao jogo
    EstadoVida getEstadoAtual() const;
    int getAndarAtual() const;
    void setAndarAtual(int andar);
    void avancarAndar();

    // Permite que itens aumentem atributos do personagem
    void aumentarChanceCritico(int incremento);
    int getChanceCriticoBase() const;
};

#endif // PERSONAGEM_HPP
