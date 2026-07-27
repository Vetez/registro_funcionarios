# Nome do compilador
CXX = g++

# Flags de compilação
CXXFLAGS = -Wall -Wextra -g -Iinclude
LDFLAGS = -lm -lncurses# Adicione outras bibliotecas necessárias aqui

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

# Regra principal (default): compilar o executável
all: $(TARGET)
	@echo "Build completo!"
	@echo "Executável gerado em: $(TARGET)"

# Compilar o executável
$(TARGET): $(OBJ)
	@mkdir -p $(@D)  # Cria o diretório se não existir
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)
	chmod +x $@  # Garante permissão de execução
	@echo "Executável criado com sucesso"

# Compilar os arquivos .cpp para .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar arquivos compilados
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "Limpeza concluída."

# Regra de depuração (com símbolos de debug)
debug: CXXFLAGS += -DDEBUG -Og
debug: clean all
	@echo "Compilação para Debug concluída."

# Executar o programa
run: all
	@echo "Executando o programa..."
	./$(TARGET)

# Executar no GDB
gdb: debug
	@echo "Iniciando debug com GDB..."
	gdb --args $(TARGET)

# Verificar estrutura de arquivos
check:
	@echo "Verificando estrutura de arquivos..."
	@tree -L 2

# Verificar dependências
deps:
	@echo "Verificando dependências..."
	@ldd $(TARGET) 2>/dev/null || echo "Executável não encontrado. Compile primeiro."

.PHONY: all clean debug run gdb check deps
