#ifndef ESTADO_PARTIDA_HPP
#define ESTADO_PARTIDA_HPP

#include <string>

/**
 * Estados possíveis do fluxo geral da Partida (controla o loop principal).
 */
enum class EstadoPartida {
    LOBBY,
    COMBATE,
    SAQUE_ANDAR,
    GAME_OVER
};

std::string estadoPartidaParaString(EstadoPartida estado);

#endif // ESTADO_PARTIDA_HPP
