# RPG Terminal em C++

Um jogo de RPG em terminal desenvolvido em **C++**, utilizando os princípios da **Programação Orientada a Objetos (POO)**. O projeto foi implementando com conceitos como herança, polimorfismo, encapsulamento, tratamento de exceções e máquina de estados para gerenciamento da partida.

---

## 📖 Sobre o Projeto

O objetivo deste projeto é simular um RPG de combate em turnos executado diretamente no terminal.

O jogador escolhe uma classe de personagem, enfrenta inimigos cada vez mais fortes, utiliza itens durante a aventura e avança por diversos andares até ser derrotado.

A arquitetura foi projetada para facilitar a manutenção e futuras expansões, separando responsabilidades em classes bem definidas.

---

## 🎯 Objetivos

* Aplicar conceitos de Programação Orientada a Objetos.
* Utilizar abstração, herança e polimorfismo.
* Implementar um sistema baseado em estados.
* Utilizar tratamento de exceções personalizadas.
* Praticar organização de projetos em C++.

---

## ✨ Funcionalidades

* Escolha entre duas classes:

  * 🛡️ Guerreiro
  * 🔮 Mago
* Sistema de combate em turnos.
* Sistema de dano crítico.
* Sistema de inventário.
* Itens consumíveis.
* Progressão por andares.
* Dificuldade crescente dos inimigos.
* Gerenciamento de estados da partida.
* Salvamento de estatísticas da execução.

---

## 📁 Estrutura do Projeto

```text
RPG-TERMINAL/
│
├── include/
│   ├── Entidade.hpp
│   ├── Personagem.hpp
│   ├── Guerreiro.hpp
│   ├── Mago.hpp
│   ├── Inimigo.hpp
│   ├── Item.hpp
│   ├── PocaoCura.hpp
│   ├── BonusAtributo.hpp
│   ├── Partida.hpp
│   ├── EstadoPartida.hpp
│   ├── EstadoVida.hpp
│   ├── GerenciadorEstatisticas.hpp
│   ├── AcaoInvalidaException.hpp
│   └── TransicaoEstadoException.hpp
│
├── src/
│   ├── AcaoInvalidaException.cpp
│   ├── BonusAtributo.cpp
│   ├── Entidade.cpp
│   ├── EstadoPartida.cpp
│   ├── EstadoVida.cpp
│   ├── GerenciadorEstatisticas.cpp
│   ├── Guerreiro.cpp
│   ├── Inimigo.cpp
│   ├── Item.cpp
│   ├── Mago.cpp
│   ├── main.cpp
│   ├── Partida.cpp
│   ├── Personagem.cpp
│   ├── PocaoCura.cpp
│   └── TransicaoEstadoException.cpp
│
├── estatisticas.txt
├── Makefile
├── README.md
├── DiagramaUML.png
└── DiagramaUML.txt
```

---

## 🏗️ Arquitetura

O projeto é organizado em quatro componentes principais:

### Entidades

Classe abstrata que representa qualquer personagem do jogo.

* `Entidade`

  * `Personagem`

    * `Guerreiro`
    * `Mago`
  * `Inimigo`

---

### Itens

Todos os itens herdam da classe abstrata `Item`.

* `PocaoCura`
* `BonusAtributo`

---

### Controle da Partida

A classe `Partida` é responsável por:

* Criar o jogador;
* Controlar o fluxo do jogo;
* Gerenciar combates;
* Controlar os estados;
* Gerenciar a progressão entre andares;
* Salvar estatísticas.

---

## 🔄 Fluxo do Jogo

```text
LOBBY
   │
   ▼
COMBATE
   │
   ▼
SAQUE_ANDAR
   │
   ├────► COMBATE
   │
   └────► GAME_OVER
```

Estados disponíveis:

* LOBBY
* COMBATE
* SAQUE_ANDAR
* GAME_OVER

---

## ❤️ Estados de Vida

O personagem pode assumir os seguintes estados:

* CHEIA
* ALTA
* MÉDIA
* BAIXA
* MORTO

---

## 📜 Regras do Jogo

* Combate baseado em turnos.
* Ataques críticos aumentam conforme o avanço dos andares.
* Existe limite máximo para chance crítica.
* O jogador pode utilizar itens antes de avançar de andar.
* Consultar o inventário não consome turno.
* Ações inválidas são tratadas por exceções personalizadas.

---

## ⚠️ Exceções

O projeto utiliza exceções específicas para tornar a aplicação mais robusta.

* `AcaoInvalidaException`
* `TransicaoEstadoException`

---

## 📊 Estatísticas

Ao final de cada execução, informações da partida são armazenadas em:

```text
estatisticas.txt
```

---

## 🚀 Compilação

Compile utilizando o Makefile:

```bash
make
```

Execute:

```bash
.\build\rpg_game.exe 
```

---

## 💻 Conceitos de C++ Utilizados

* Programação Orientada a Objetos
* Classes Abstratas
* Herança
* Polimorfismo
* Encapsulamento
* Sobrescrita de métodos (`override`)
* Enumerações (`enum`)
* Tratamento de Exceções
* Composição
* Agregação
* Organização em arquivos `.hpp` e `.cpp`

---

## 🔮 Melhorias Futuras

* Sistema de experiência (XP)
* Níveis para o jogador
* Novas classes
* Novos inimigos
* Chefes (Bosses)
* Equipamentos


---

## Diagrama UML

Toda a implementação foi desenvolvida seguindo o diagrama UML disponibilizado no projeto, respeitando os relacionamentos de herança, composição, agregação e dependência entre as classes.

---

## 👨‍💻 Autores

**Diogo Roger de Medeiros Silva**

**Leonardo Xavier Cruz Filho**

Projeto desenvolvido para o componente curricular Linguagem de Programação I (IMD/UFRN).
