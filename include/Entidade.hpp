#ifndef ENTIDADE_HPP
#define ENTIDADE_HPP
#include <string>
using namespace std;

class Entidade {
protected:
    string nome;
    int hpMaximo;
    int hpAtual;

public:
    Entidade(string n, int hpMax);
    virtual ~Entidade() = default;

    virtual void atacar(Entidade* alvo) = 0;
    virtual void receberDano(int dano) = 0;

    bool isVivo() const;
    string getNome() const;
};

#endif