#ifndef ESTADO_VIDA_HPP
#define ESTADO_VIDA_HPP

#include <string>

/**
 * Representa a "máquina de estados" de vida de um Personagem,
 * usada por atualizarEstadoVida() para classificar o HP atual.
 */
enum class EstadoVida {
    CHEIA,
    ALTA,
    MEDIA,
    BAIXA,
    MORTO
};

// Função utilitária para exibir o estado de forma legível no console
std::string estadoVidaParaString(EstadoVida estado);

#endif // ESTADO_VIDA_HPP
