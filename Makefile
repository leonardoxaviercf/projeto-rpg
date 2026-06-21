# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -std=c++11 -Iinclude

# Pastas do projeto
SRC_DIR = src
OBJ_DIR = build
INC_DIR = include

# Mapeamento de arquivos
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))
EXECUTABLE = $(OBJ_DIR)/rpg_game.exe

# Regra principal de compilação
all: $(EXECUTABLE)

# Gera o executável
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compila os arquivos .cpp em .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpa os arquivos compilados
clean:
	@if exist $(OBJ_DIR) rmdir /S /Q $(OBJ_DIR)