#include <iostream>
#include <limits>
#include "EntradaUsuario.h"

	const std::string VERMELHO = "\033[31m";
	const std::string NEGRITO = "\033[1m";
	const std::string RESET = "\033[0m";

void EntradaUsuario::limparTela()
{
    std::cout << "\033[2J\033[H";
}

void EntradaUsuario::limparBuffer()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void EntradaUsuario::limparEntrada()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void EntradaUsuario::aguardarEnter()
{
    std::cout << '\n';
    std::cout << "Pressione " << VERMELHO << NEGRITO << "ENTER " << RESET << "para continuar...";
    std::cin.get();
}

int EntradaUsuario::lerQuantidadeDeFuncionarios()
{
    int quantidadeFuncionarios;
    while (true)
    {
        quantidadeFuncionarios = lerInteiro("Quantos funcionários deseja cadastrar? ");

        if(!validarQuantidadeDeFuncionarios(quantidadeFuncionarios))
        {
            continue;
        }
        return quantidadeFuncionarios;
    }
}

bool EntradaUsuario::validarQuantidadeDeFuncionarios( const int quantidadeFuncionarios )
{
    if( quantidadeFuncionarios <= 0)
    {
        interfaceFincionario.exibirMensagemErro( "Quantidade de funcionários não pode ser zero ou número negativo." );
        return false;
    }
    return true;
}

std::string EntradaUsuario::lerNomeNaoVazio( const std::string& mensagem )
{
    std::string buscaNome;

    while ( true )
    {
        std::cout << mensagem;
        std::getline( std::cin, buscaNome );
        if( buscaNome.empty() )
        {
            interfaceFincionario.exibirMensagemErro( "Nome do funcionário não pode estar vazio." );
            continue;
        }

        return buscaNome;
    }
}

int EntradaUsuario::lerInteiro( const std::string& mensagem )
{
    int numDigitado;
    while (true)
    {
        std::cout << mensagem;
        if( !( std::cin >> numDigitado ) )
        {
            interfaceFincionario.exibirMensagemErro( "Apenas números são permitidos." );
            limparEntrada();
            continue;
        }

        limparBuffer();
        return numDigitado;
    }
}

double EntradaUsuario::lerDouble( const std::string& mensagem )
{
    double numDigitado;
    while ( true )
    {
        std::cout << mensagem;
        if( !( std::cin >> numDigitado ) )
        {
            interfaceFincionario.exibirMensagemErro( "Apenas números são permitidos." );
            limparEntrada();
            continue;
        }

        limparBuffer();
        return numDigitado;
    }
}