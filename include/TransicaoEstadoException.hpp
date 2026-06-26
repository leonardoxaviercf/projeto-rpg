#ifndef TRANSICAO_ESTADO_EXCEPTION_HPP
#define TRANSICAO_ESTADO_EXCEPTION_HPP

#include <exception>
#include <string>

/**
 * Lançada pela Partida quando uma mudança de EstadoPartida é inválida
 * (ex.: tentar ir de LOBBY direto para SAQUE_ANDAR).
 */
class TransicaoEstadoException : public std::exception {
private:
    std::string mensagem;

public:
    explicit TransicaoEstadoException(const std::string& msg);

    // Equivalente ao "lançarExeccao()" do diagrama: retorna a mensagem do erro
    const char* lancarExeccao() const;

    // Sobrescreve o que() padrão de std::exception para integrar com try/catch genérico
    const char* what() const noexcept override;
};

#endif // TRANSICAO_ESTADO_EXCEPTION_HPP
