#include "EstadoPartida.hpp"

std::string estadoPartidaParaString(EstadoPartida estado) {
    switch (estado) {
        case EstadoPartida::LOBBY:        return "LOBBY";
        case EstadoPartida::COMBATE:      return "COMBATE";
        case EstadoPartida::SAQUE_ANDAR:  return "SAQUE_ANDAR";
        case EstadoPartida::GAME_OVER:    return "GAME_OVER";
    }
    return "DESCONHECIDO";
}
