#ifndef ENTRADA_USUARIO_H
#define ENTRADA_USUARIO_H
#include "InterfaceFuncionario.h"

#include <string>

class EntradaUsuario
{
private:
	InterfaceFuncionario interfaceFincionario;
public:
	int lerQuantidadeDeFuncionarios();
	bool validarQuantidadeDeFuncionarios( const int quantidadeFuncionarios );

	std::string lerNomeNaoVazio( const std::string& mensagem );
	int lerInteiro( const std::string& mensagem );
	double lerDouble( const std::string& mensagem );

	void aguardarEnter();

	void limparTela();
	void limparBuffer();
	void limparEntrada();
};

#endif