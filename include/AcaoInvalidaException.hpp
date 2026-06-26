#ifndef ACAO_INVALIDA_EXCEPTION_HPP
#define ACAO_INVALIDA_EXCEPTION_HPP

#include <exception>
#include <string>

/**
 * Lançada por Personagem quando uma ação de jogo é inválida
 * (ex.: usar item inexistente, atacar alvo morto, mago sem mana).
 */
class AcaoInvalidaException : public std::exception {
private:
    std::string mensagem;

public:
    explicit AcaoInvalidaException(const std::string& msg);

    const char* lancarExeccao() const;
    const char* what() const noexcept override;
};

#endif // ACAO_INVALIDA_EXCEPTION_HPP
