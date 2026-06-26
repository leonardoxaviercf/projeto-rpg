#include "Partida.hpp"
#include "Guerreiro.hpp"
#include "Mago.hpp"
#include "PocaoCura.hpp"
#include "BonusAtributo.hpp"
#include "TransicaoEstadoException.hpp"
#include "AcaoInvalidaException.hpp"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>

Partida::Partida(const std::string& caminhoArquivoEstatisticas)
    : estadoAtual(EstadoPartida::LOBBY),
      jogador(nullptr),
      inimigoAtual(nullptr),
      gerenciadorSalves(caminhoArquivoEstatisticas) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void Partida::mudarEstado(EstadoPartida novoEstado) {
    // Valida transições permitidas na máquina de estados da Partida.
    // Lança TransicaoEstadoException para qualquer salto inválido.
    bool valido = false;

    switch (estadoAtual) {
        case EstadoPartida::LOBBY:
            valido = (novoEstado == EstadoPartida::COMBATE);
            break;
        case EstadoPartida::COMBATE:
            valido = (novoEstado == EstadoPartida::SAQUE_ANDAR ||
                      novoEstado == EstadoPartida::GAME_OVER);
            break;
        case EstadoPartida::SAQUE_ANDAR:
            valido = (novoEstado == EstadoPartida::COMBATE);
            break;
        case EstadoPartida::GAME_OVER:
            valido = false; // estado terminal
            break;
    }

    if (!valido) {
        throw TransicaoEstadoException(
            "Transicao de estado invalida: " + estadoPartidaParaString(estadoAtual) +
            " -> " + estadoPartidaParaString(novoEstado)
        );
    }

    std::cout << "\n[Estado: " << estadoPartidaParaString(estadoAtual)
               << " -> " << estadoPartidaParaString(novoEstado) << "]\n";
    estadoAtual = novoEstado;
}

void Partida::processarLobby() {
    std::cout << "========================================\n";
    std::cout << "   BEM-VINDO AO RPG TERMINAL\n";
    std::cout << "         By: DrLx Studios\n";
    std::cout << "========================================\n";

    std::cout << "Escolha sua classe:\n";
    std::cout << "  1 - Guerreiro (mais HP e escudo)\n";
    std::cout << "  2 - Mago (ataques magicos mais fortes)\n";
    std::cout << "Opcao: ";

    int escolha = 0;
    std::cin >> escolha;

    std::cout << "Digite o nome do seu personagem: ";
    std::string nomePersonagem;
    std::cin >> nomePersonagem;

    if (escolha == 2) {
        jogador = std::make_unique<Mago>(nomePersonagem, 80, 10, 50);
        std::cout << "Voce escolheu Mago. Boa sorte, " << nomePersonagem << "!\n";
    } else {
        jogador = std::make_unique<Guerreiro>(nomePersonagem, 100, 10, 15);
        std::cout << "Voce escolheu Guerreiro. Boa sorte, " << nomePersonagem << "!\n";
    }

    mudarEstado(EstadoPartida::COMBATE);
    instanciarProximoInimigo();
}

void Partida::instanciarProximoInimigo() {
    int andar = jogador->getAndarAtual();
    int hpInimigo = 30 + andar * 10;
    int multiplicador = 1 + andar / 3;

    inimigoAtual = std::make_unique<Inimigo>(
        "Monstro do Andar " + std::to_string(andar), hpInimigo, multiplicador
    );

    std::cout << "\nUm " << inimigoAtual->getNome() << " aparece! (HP: "
               << inimigoAtual->getHpAtual() << ")\n";
}

void Partida::exibirStatus() const {
    std::cout << "\n--- STATUS ---\n";
    std::cout << jogador->getNome() << " | HP: " << jogador->getHpAtual()
               << "/" << jogador->getHpMaximo()
               << " | Estado: " << estadoVidaParaString(jogador->getEstadoAtual())
               << " | Andar: " << jogador->getAndarAtual() << "\n";
    if (inimigoAtual && inimigoAtual->isVivo()) {
        std::cout << inimigoAtual->getNome() << " | HP: " << inimigoAtual->getHpAtual()
                   << "/" << inimigoAtual->getHpMaximo() << "\n";
    }
    std::cout << "--------------\n";
}

void Partida::processarCombate() {
    exibirStatus();

    std::cout << "\nEscolha sua acao:\n";
    std::cout << "  1 - Atacar\n";
    std::cout << "  2 - Usar item\n";
    std::cout << "  3 - Ver inventario\n";
    std::cout << "Opcao: ";

    int acao = 0;
    std::cin >> acao;

    try {
        switch (acao) {
            case 2: {
                jogador->listarInventario();
                if (jogador->tamanhoInventario() > 0) {
                    std::cout << "Qual item usar (indice)? ";
                    int indice;
                    std::cin >> indice;
                    jogador->usarItem(indice);
                }
                break;
            }
            case 3:
                jogador->listarInventario();
                return; // não consome o turno
            default:
                jogador->atacar(inimigoAtual.get());
                break;
        }
    } catch (const AcaoInvalidaException& e) {
        std::cout << "Erro: " << e.what() << "\n";
        return; // ação inválida não consome o turno
    }

    // Inimigo contra-ataca se ainda estiver vivo
    if (inimigoAtual->isVivo()) {
        inimigoAtual->atacar(jogador.get());
    }

    if (!inimigoAtual->isVivo()) {
        std::cout << "\n" << inimigoAtual->getNome() << " foi derrotado!\n";
        mudarEstado(EstadoPartida::SAQUE_ANDAR);
        processarSaqueAndar();
        return;
    }

    if (!jogador->isVivo()) {
        std::cout << "\n" << jogador->getNome() << " foi derrotado...\n";
        mudarEstado(EstadoPartida::GAME_OVER);
    }
}

void Partida::processarSaqueAndar() {
    std::cout << "\nVoce encontra um bau de recompensas!\n";

    int sorteio = std::rand() % 2;
    if (sorteio == 0) {
        int cura = 15 + jogador->getAndarAtual() * 2;
        jogador->adicionarItem(std::make_unique<PocaoCura>(
            "Pocao de Cura", "Restaura HP do personagem", cura
        ));
        std::cout << "Voce encontrou uma Pocao de Cura (+" << cura << " HP)!\n";
    } else {
        int bonus = 3;
        jogador->adicionarItem(std::make_unique<BonusAtributo>(
            "Amuleto de Precisao", "Aumenta a chance de critico", bonus
        ));
        std::cout << "Voce encontrou um Amuleto de Precisao (+" << bonus << "% critico)!\n";
    }

    jogador->avancarAndar();
    std::cout << "Voce avanca para o andar " << jogador->getAndarAtual() << "!\n";

    mudarEstado(EstadoPartida::COMBATE);
    instanciarProximoInimigo();
}

void Partida::iniciarLoop() {
    try {
        processarLobby();

        while (estadoAtual != EstadoPartida::GAME_OVER) {
            processarCombate();
        }

        std::cout << "\n========================================\n";
        std::cout << "                GAME OVER\n";
        std::cout << "========================================\n";
        std::cout << jogador->getNome() << " alcancou o andar "
                   << jogador->getAndarAtual() << " antes de cair.\n";

        gerenciadorSalves.salvarRun(jogador.get(), jogador->getAndarAtual());
        gerenciadorSalves.carregarEstatisticasGerais();

    } catch (const TransicaoEstadoException& e) {
        std::cerr << "Erro fatal de fluxo de jogo: " << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Erro inesperado: " << e.what() << "\n";
    }
}
