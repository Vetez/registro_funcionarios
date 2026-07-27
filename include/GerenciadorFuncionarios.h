#ifndef GERENCIADOR_FUNCIONARIOS_H
#define GERENCIADOR_FUNCIONARIOS_H

#include <string>
#include <vector>
#include "Funcionario.h"
#include "EntradaUsuario.h"
#include "CadastroFuncionario.h"
#include "InterfaceFuncionario.h"

class GerenciadorFuncionarios
{
private:
	EntradaUsuario entradaUsuario;
	CadastroFuncionario cadastroFuncionario;
	InterfaceFuncionario interfaceFuncionario;
	std::vector<Funcionario> funcionariosCadastrados;

	std::string converterTextoParaMinusculo(std::string nome);
	bool cadastroEstaVazio();
	std::vector<int> encontrarIndiceFuncionarioPorNomeDigitado( const std::string& nomeBuscado );
	std::vector<int> buscarIndicePorNomeDigitado();

	int selecionarFuncionarioListado( const std::vector<int>& indicesFuncionarios );

	void exibirFuncionariosEncontrados( const std::vector<int>& indicesFuncionarios );

	void removerFuncionarioPeloIndice( const std::vector<int>& indicesFuncionarios );
	void editarFuncionarioPeloIndice( const std::vector<int>& indicesFuncinarios );

public:
	void cadastrarNovosFuncionarios( const int quantidadeFuncionarios );
	void adicionarNovosFuncionariosAoCadastro();

	void listarFuncionariosCadastrados();

	bool confirmarAcao( const std::string& mensagem );

	void buscarFuncionarioPorNome();
	void removerFuncionarioPorNome();
	void editarFuncionarioPorNome();

};

#endif