#include "EstadoVida.hpp"

std::string estadoVidaParaString(EstadoVida estado) {
    switch (estado) {
        case EstadoVida::CHEIA: return "CHEIA";
        case EstadoVida::ALTA:  return "ALTA";
        case EstadoVida::MEDIA: return "MEDIA";
        case EstadoVida::BAIXA: return "BAIXA";
        case EstadoVida::MORTO: return "MORTO";
    }
    return "DESCONHECIDO";
}
