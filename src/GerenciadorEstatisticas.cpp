#include "GerenciadorEstatisticas.hpp"
#include "Personagem.hpp"
#include <fstream>
#include <iostream>
#include <ctime>

GerenciadorEstatisticas::GerenciadorEstatisticas(const std::string& caminhoArquivo)
    : caminhoArquivo(caminhoArquivo) {}

void GerenciadorEstatisticas::salvarRun(Personagem* p, int andares) {
    std::ofstream arquivo(caminhoArquivo, std::ios::app);
    if (!arquivo.is_open()) {
        std::cerr << "Aviso: nao foi possivel abrir " << caminhoArquivo
                   << " para salvar estatisticas.\n";
        return;
    }

    std::time_t agora = std::time(nullptr);
    char bufferData[32];
    std::strftime(bufferData, sizeof(bufferData), "%d/%m/%Y %H:%M:%S", std::localtime(&agora));

    arquivo << "[" << bufferData << "] Personagem=" << p->getNome()
            << " | AndaresAlcancados=" << andares
            << " | HpFinal=" << p->getHpAtual() << "/" << p->getHpMaximo()
            << " | EstadoVida=" << estadoVidaParaString(p->getEstadoAtual())
            << "\n";

    arquivo.close();
    std::cout << "Estatisticas da run salvas em \"" << caminhoArquivo << "\".\n";
}

void GerenciadorEstatisticas::carregarEstatisticasGerais() {
    std::ifstream arquivo(caminhoArquivo);
    if (!arquivo.is_open()) {
        std::cout << "Nenhuma estatistica encontrada ainda em \"" << caminhoArquivo << "\".\n";
        return;
    }

    std::cout << "--- Historico de runs (" << caminhoArquivo << ") ---\n";
    std::string linha;
    while (std::getline(arquivo, linha)) {
        std::cout << linha << "\n";
    }
    arquivo.close();
}
