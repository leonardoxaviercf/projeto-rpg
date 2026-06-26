#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

class Personagem; // forward declaration (evita dependência circular com Personagem.hpp)

/**
 * Classe abstrata base para qualquer item que um Personagem possa carregar
 * em seu inventário (PocaoCura e BonusAtributo herdam dela).
 */
class Item {
protected:
    std::string nome;
    std::string descricao;

public:
    Item(const std::string& nome, const std::string& descricao);
    virtual ~Item() = default;

    // Método abstrato: cada item define seu próprio efeito ao ser usado
    virtual void aplicarEfeito(Personagem* p) = 0;

    const std::string& getNome() const;
    const std::string& getDescricao() const;
};

#endif // ITEM_HPP
