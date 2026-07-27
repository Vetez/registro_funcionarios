#ifndef MENU_FUNCIONARIO_H
#define MENU_FUNCIONARIO_H

#include "Funcionario.h"
#include "GerenciadorFuncionarios.h"
#include "EntradaUsuario.h"
#include "InterfaceFuncionario.h"
#include <vector>

class MenuFuncionario
{
private:
	GerenciadorFuncionarios gerenciarFuncionarios;
	EntradaUsuario entradaUsuario;
	InterfaceFuncionario interfaceFuncionario;

public:
	void exibirMenu();

	bool executarOpcaoSelecionada( const int opcao );

	bool lerOpcaoMenu( int& opcao );

	void executarSistema();
};

#endif