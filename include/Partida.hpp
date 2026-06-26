#ifndef PARTIDA_HPP
#define PARTIDA_HPP

#include "EstadoPartida.hpp"
#include "Personagem.hpp"
#include "Inimigo.hpp"
#include "GerenciadorEstatisticas.hpp"
#include <memory>

/**
 * Classe central do jogo: controla o Personagem (1) e o Inimigo (1) atuais,
 * instancia inimigos, controla o fluxo via EstadoPartida e usa o
 * GerenciadorEstatisticas para persistir o resultado de cada run.
 */
class Partida {
private:
    EstadoPartida estadoAtual;
    std::unique_ptr<Personagem> jogador;
    std::unique_ptr<Inimigo> inimigoAtual;
    GerenciadorEstatisticas gerenciadorSalves;

    // Auxiliares privados de fluxo de jogo (lógica interna do loop)
    void processarSaqueAndar();
    void instanciarProximoInimigo();
    void exibirStatus() const;

public:
    Partida(const std::string& caminhoArquivoEstatisticas);

    void iniciarLoop();
    void processarLobby();
    void processarCombate();
    void mudarEstado(EstadoPartida novoEstado);
};

#endif // PARTIDA_HPP
