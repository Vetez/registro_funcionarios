#include "InterfaceFuncionario.h"

#include <iostream>
#include <sstream>
#include <iomanip>

	const std::string VERDE = "\033[32m";
	const std::string VERMELHO = "\033[31m";
	const std::string AMARELO = "\033[33m";
	const std::string AZUL = "\033[34m";
	const std::string CIANO = "\033[36m";
	const std::string NEGRITO = "\033[1m";
	const std::string RESET = "\033[0m";

void InterfaceFuncionario::exibirLinha()
{
	std::cout << AMARELO << "==========================================" <<  RESET << '\n';
}

std::string InterfaceFuncionario::formatarMoeda( double valor )
{
	std::ostringstream textoFormatado;

	textoFormatado << VERDE << NEGRITO << "R$ " << RESET << std::fixed << std::setprecision(2) << CIANO << valor << RESET;

	return textoFormatado.str();
}

void InterfaceFuncionario::exibirNumeroComCor( int i )
{
	std::cout << AZUL << "[" << i + 1 << "]" << RESET;
}

std::string InterfaceFuncionario::formatarAnos( double anos )
{
	std::ostringstream textoFormatado;

	textoFormatado << std::fixed << std::setprecision(1) << anos;

	return textoFormatado.str();
}

void InterfaceFuncionario::exibirCampo( const std::string& campo , const std::string& funcionarioCampo )
{
	std::cout << campo << ": " << CIANO << funcionarioCampo << RESET << '\n';
}

void InterfaceFuncionario::exibirTitulo( const std::string& titulo )
{
    exibirLinha();
    std::cout << NEGRITO << VERDE << titulo << RESET << '\n';
    exibirLinha();
}

void InterfaceFuncionario::exibirMotivo( const std::string& motivo )
{
	std::cout << AZUL << "[MOTIVO] " << RESET << motivo << '\n';
}

void InterfaceFuncionario::exibirMensagemSucesso( const std::string& mensagem )
{
	std::cout << VERDE << "[SUCESSO] " << mensagem << RESET << '\n';
}

void InterfaceFuncionario::exibirMensagemErro( const std::string& mensagem )
{
	std::cout << VERMELHO <<  "[ERRO] " << mensagem << RESET << '\n';
}

void InterfaceFuncionario::exibirCampoAviso( const std::string& campo, const std::string& valor )
{
	std::cout  << AMARELO << campo << ": " << valor << RESET << '\n';
}

void InterfaceFuncionario::exibirCampoErro( const std::string& campo, const std::string& valor )
{
	std::cout << VERMELHO << campo << ": " << valor << RESET << '\n';
}

void InterfaceFuncionario::exibirCampoSucesso( const std::string& campo, const std::string& valor )
{
	std::cout << VERDE << campo << ": " << valor << RESET << '\n';
}