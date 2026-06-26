#include "TransicaoEstadoException.hpp"

TransicaoEstadoException::TransicaoEstadoException(const std::string& msg)
    : mensagem(msg) {}

const char* TransicaoEstadoException::lancarExeccao() const {
    return mensagem.c_str();
}

const char* TransicaoEstadoException::what() const noexcept {
    return mensagem.c_str();
}
