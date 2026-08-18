# Nome do compilador
CXX = g++

# Flags de compilação
CXXFLAGS = -Wall -Wextra -g -std=c++17 -Iinclude $(shell pkg-config --cflags libpq)

# Bibliotecas
LDLIBS = -lm -lncurses $(shell pkg-config --libs libpq)

# Diretórios
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

# Nome do executável
TARGET = $(BIN_DIR)/registro_funcionarios

# Arquivos-fonte
SRC = $(wildcard $(SRC_DIR)/*.cpp)

# Arquivos-objeto gerados
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

# Regra principal
all: $(TARGET)
	@echo "Build completo!"
	@echo "Executável gerado em: $(TARGET)"

# Gerar executável
$(TARGET): $(OBJ)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDLIBS)
	chmod +x $@
	@echo "Executável criado com sucesso"

# Compilar .cpp para .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "Limpeza concluída."

# Debug
debug: CXXFLAGS += -DDEBUG -Og
debug: clean all
	@echo "Compilação para Debug concluída."

# Executar
run: all
	@echo "Executando o programa..."
	./$(TARGET)

# Executar no GDB
gdb: debug
	@echo "Iniciando debug com GDB..."
	gdb --args $(TARGET)

# Verificar estrutura
check:
	@echo "Verificando estrutura de arquivos..."
	@tree -L 2

# Verificar dependências
deps:
	@echo "Verificando dependências..."
	@ldd $(TARGET) 2>/dev/null || echo "Executável não encontrado. Compile primeiro."

.PHONY: all clean debug run gdb check deps