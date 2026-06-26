#ifndef ENTIDADE_HPP
#define ENTIDADE_HPP

#include <string>

/**
 * Classe abstrata base para qualquer ser que participa do combate
 * (Personagem e Inimigo herdam diretamente dela).
 */
class Entidade {
protected:
    std::string nome;
    int hpMaximo;
    int hpAtual;

public:
    Entidade(const std::string& nome, int hpMaximo);
    virtual ~Entidade() = default;

    // Métodos abstratos (puramente virtuais) — cada subclasse define seu próprio comportamento de combate
    virtual void atacar(Entidade* alvo) = 0;
    virtual void receberDano(int dano) = 0; // virtual para permitir especializações (ex.: Guerreiro com escudo)

    // Método concreto, comum a toda Entidade
    bool isVivo() const;

    // Getters utilitários (não aparecem explicitamente no diagrama, mas
    // são necessários para a lógica do jogo acessar o estado protegido)
    const std::string& getNome() const;
    int getHpMaximo() const;
    int getHpAtual() const;

    void setHpAtual(int hp);
};

#endif // ENTIDADE_HPP
