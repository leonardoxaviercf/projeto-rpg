#ifndef GERENCIADOR_ESTATISTICAS_HPP
#define GERENCIADOR_ESTATISTICAS_HPP

#include <string>

class Personagem; // forward declaration

/**
 * Responsável por persistir e carregar estatísticas das partidas (runs)
 * em disco. Usado pela Partida ao final de cada run.
 */
class GerenciadorEstatisticas {
private:
    std::string caminhoArquivo;

public:
    explicit GerenciadorEstatisticas(const std::string& caminhoArquivo);

    void salvarRun(Personagem* p, int andares);
    void carregarEstatisticasGerais();
};

#endif // GERENCIADOR_ESTATISTICAS_HPP
