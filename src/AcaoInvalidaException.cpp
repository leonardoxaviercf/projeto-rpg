#include "AcaoInvalidaException.hpp"

AcaoInvalidaException::AcaoInvalidaException(const std::string& msg)
    : mensagem(msg) {}

const char* AcaoInvalidaException::lancarExeccao() const {
    return mensagem.c_str();
}

const char* AcaoInvalidaException::what() const noexcept {
    return mensagem.c_str();
}
