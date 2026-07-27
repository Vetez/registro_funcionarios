#ifndef CADASTRO_FUNCIONARIO_H
#define CADASTRO_FUNCIONARIO_H

#include "Funcionario.h"
#include "EntradaUsuario.h"
#include "InterfaceFuncionario.h"

class CadastroFuncionario
{
private:
	EntradaUsuario entradaUsuario;
	InterfaceFuncionario interfaceFuncionario;

public:
	void lerDadosFuncionario( Funcionario& funcionario );
	bool validarDadosFuncionario( const Funcionario& funcionario );
	bool funcionarioEstaAptoParaPromocao( const Funcionario& funcionario );
	void exibirDadosFuncionario( const Funcionario& funcionario );
	void exibirResultadoPromocao( const Funcionario& funcionario, bool aptoParaPromocao );
	void exibirFuncionarioComResultadoPromocao( const Funcionario& funcionario, bool aptoParaPromocao );
};

#endif