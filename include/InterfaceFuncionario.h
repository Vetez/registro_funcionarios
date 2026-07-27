#ifndef INTERFACE_FUNCIONARIO_H
#define INTERFACE_FUNCIONARIO_H

#include <string>

class InterfaceFuncionario
{
public:

	void exibirLinha();
	void exibirTitulo( const std::string& titulo );
	void exibirMensagemSucesso( const std::string& mensagem );
	void exibirMensagemErro( const std::string& mensagem );
	std::string formatarMoeda( double valor );
	std::string formatarAnos( double anos );
	void exibirCampo( const std::string& campo , const std::string& funcionarioCampo );
	void exibirMotivo( const std::string& motivo );

	void exibirCampoSucesso(const std::string& campo, const std::string& valor);
	void exibirCampoErro(const std::string& campo, const std::string& valor);
	void exibirCampoAviso(const std::string& campo, const std::string& valor);

	void exibirNumeroComCor( int i );
};

#endif