#include "MenuFuncionario.h"
#include "EntradaUsuario.h"

#include <iostream>

const std::string AZUL = "\033[34m";
	const std::string NEGRITO = "\033[1m";
const std::string RESET = "\033[0m";

void MenuFuncionario::exibirMenu()
{
    interfaceFuncionario.exibirLinha();
    interfaceFuncionario.exibirTitulo("              MENU FUNCIONÁRIO            ");
    interfaceFuncionario.exibirLinha();
    std::cout << '\n';

    std::cout << AZUL << NEGRITO << " [1] " << RESET << "Cadastrar funcionários." << '\n';
    std::cout << AZUL << NEGRITO << " [2] " << RESET << "Listar funcionários." << '\n';
    std::cout << AZUL << NEGRITO << " [3] " << RESET << "Buscar funcionário pelo nome." << '\n';
    std::cout << AZUL << NEGRITO << " [4] " << RESET << "Remover funcionário por nome." << '\n';
    std::cout << AZUL << NEGRITO << " [5] " << RESET << "Editar funcionário por nome." << '\n';
    std::cout << AZUL << NEGRITO << " [6] " << RESET << "Sair do programa." << '\n';

    std::cout << '\n';
    interfaceFuncionario.exibirLinha();

    std::cout << "Escolha uma " << AZUL << NEGRITO << "opção" << RESET << ": ";
}

bool MenuFuncionario::executarOpcaoSelecionada( const int opcao )
{
    switch ( opcao )
    {
    case 1:
        gerenciarFuncionarios.adicionarNovosFuncionariosAoCadastro();
        entradaUsuario.aguardarEnter();
        return true;

    case 2:
        gerenciarFuncionarios.listarFuncionariosCadastrados();
        entradaUsuario.aguardarEnter();
        return true;

    case 3:
        gerenciarFuncionarios.buscarFuncionarioPorNome();
        entradaUsuario.aguardarEnter();
        return true;

    case 4:
        gerenciarFuncionarios.removerFuncionarioPorNome();
        entradaUsuario.aguardarEnter();
        return true;

    case 5:
        gerenciarFuncionarios.editarFuncionarioPorNome();
        entradaUsuario.aguardarEnter();
        return true;

    case 6:
        return false;

    default:
        interfaceFuncionario.exibirMensagemErro( "Opção inválida." );
        entradaUsuario.aguardarEnter();
        return true;
    }
}

bool MenuFuncionario::lerOpcaoMenu( int& opcao )
{
    if(!(std::cin >> opcao))
    {
        interfaceFuncionario.exibirMensagemErro( "Opção inválida." );
        entradaUsuario.limparEntrada();
        return false;
    }
    entradaUsuario.limparBuffer();
    return true;
}

void MenuFuncionario::executarSistema()
{
    int opcao;

    while ( true )
    {
        entradaUsuario.limparTela();
        exibirMenu();
        if( !lerOpcaoMenu( opcao ) )
        {
            continue;
        }

        if(!executarOpcaoSelecionada( opcao ))
        {
            break;
        }
    }
}
