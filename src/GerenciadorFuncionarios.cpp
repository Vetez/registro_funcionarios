#include "GerenciadorFuncionarios.h"

#include <iostream>
#include <cctype>

	const std::string AZUL = "\033[34m";
    const std::string RESET = "\033[0m";

void GerenciadorFuncionarios::cadastrarNovosFuncionarios( const int quantidadeFuncionarios )
{
    for( int i = 0; i < quantidadeFuncionarios; i++ )
    {
        Funcionario funcionario;
        while ( true )
        {
            cadastroFuncionario.lerDadosFuncionario(funcionario);

            bool dadosValidos = cadastroFuncionario.validarDadosFuncionario(funcionario);

            if( dadosValidos )
            {
                funcionariosCadastrados.push_back(funcionario);
                interfaceFuncionario.exibirMensagemSucesso( "Funcionário cadastrado com sucesso." );
                break;
            }
        }
    }
}

void GerenciadorFuncionarios::adicionarNovosFuncionariosAoCadastro()
{
    int quantidadeFuncionarios = entradaUsuario.lerQuantidadeDeFuncionarios();
    cadastrarNovosFuncionarios( quantidadeFuncionarios );
}

void GerenciadorFuncionarios::listarFuncionariosCadastrados()
{
    int totalFuncionariosAptos { 0 };
    int totalFuncionariosNaoAptos { 0 };
    if( funcionariosCadastrados.empty() )
    {
        interfaceFuncionario.exibirMensagemErro( "*- Nenhum funcionário válido foi cadastrado." );
        return;
    }

    interfaceFuncionario.exibirTitulo( "         FUNCIONÁRIOS CADASTRADOS         " );

    for( size_t i = 0; i < funcionariosCadastrados.size(); i++ )
    {
        bool aptoParaPromocao = cadastroFuncionario.funcionarioEstaAptoParaPromocao( funcionariosCadastrados[i] );

        std::cout << '\n';
        interfaceFuncionario.exibirTitulo( "              FUNCIONÁRIO " + std::to_string(i + 1));

        cadastroFuncionario.exibirFuncionarioComResultadoPromocao( funcionariosCadastrados[i], aptoParaPromocao );

        if( aptoParaPromocao )
        {
            totalFuncionariosAptos++;
        }
        else
        {
            totalFuncionariosNaoAptos++;
        }
    }

    std::cout << '\n';
    interfaceFuncionario.exibirTitulo( "          == R E S U M O ==              " );
    interfaceFuncionario.exibirCampo("Funcionários válidos cadastrados", std::to_string(funcionariosCadastrados.size()));
    interfaceFuncionario.exibirCampoSucesso("Funcionários aptos para promoção", std::to_string(totalFuncionariosAptos));
    interfaceFuncionario.exibirCampoErro("Funcionários não aptos para promoção", std::to_string(totalFuncionariosNaoAptos));
}

std::string GerenciadorFuncionarios::converterTextoParaMinusculo( std::string nome )
{
    for( size_t i = 0; i < nome.size(); i++ )
    {
        nome[i] = std::tolower( nome[i] );
    }
    return nome;
}

bool GerenciadorFuncionarios::cadastroEstaVazio()
{
    if( funcionariosCadastrados.empty() )
    {
        interfaceFuncionario.exibirMensagemErro( "|= Nenhum funcionário cadastrado!" );
        return true;
    }
    return false;
}

std::vector<int> GerenciadorFuncionarios::encontrarIndiceFuncionarioPorNomeDigitado( const std::string& nomeBuscado )
{
    std::string nomeBuscadoMinusculo = converterTextoParaMinusculo( nomeBuscado );

    std::vector<int> indicesEncontrados;

    for( size_t i = 0; i < funcionariosCadastrados.size(); i++ )
    {
        std::string nomeFuncionarioMinusculo = converterTextoParaMinusculo( funcionariosCadastrados[ i ].nome );
        if( nomeFuncionarioMinusculo.find(nomeBuscadoMinusculo) != std::string::npos )
        {
            indicesEncontrados.push_back(static_cast<int>(i));
        }
    }
    return indicesEncontrados;
}

bool GerenciadorFuncionarios::confirmarAcao( const std::string& mensagem )
{
    while ( true )
    {
        std::string opcao;
        std::cout << mensagem;

        std::getline( std::cin, opcao );
        if( opcao.empty() )
        {
            interfaceFuncionario.exibirMensagemErro( "Opção não pode estar vazia." );
            continue;
        }

        if( opcao == "s" || opcao == "S")
        {
            return true;
        }
        if( opcao == "n" || opcao == "N")
        {
            return false;
        }

        interfaceFuncionario.exibirMensagemErro("Digite apenas s ou n.");
    }
}

std::vector<int> GerenciadorFuncionarios::buscarIndicePorNomeDigitado()
{
    std::string buscaNome = entradaUsuario.lerNomeNaoVazio( "Nome do funcionário para busca: " );

    std::vector<int> indicesFuncionarios = encontrarIndiceFuncionarioPorNomeDigitado( buscaNome );

    return indicesFuncionarios;
}

void GerenciadorFuncionarios::exibirFuncionariosEncontrados( const std::vector<int>& indicesFuncionarios )
{
    for(size_t i  = 0; i < indicesFuncionarios.size(); i++)
    {
        interfaceFuncionario.exibirNumeroComCor( static_cast<int>( i ) );
        std::cout << " - " << funcionariosCadastrados[indicesFuncionarios[i]].nome << '\n'; 
    }
}

int GerenciadorFuncionarios::selecionarFuncionarioListado( const std::vector<int>& indicesFuncionarios )
{
    exibirFuncionariosEncontrados( indicesFuncionarios );

    int numeroFuncionarioNaLista;
    std::cout << "Escolha o funcionário: ";
    std::cin >> numeroFuncionarioNaLista;

    entradaUsuario.limparBuffer();

    int posicaoLista = numeroFuncionarioNaLista - 1;

    if( posicaoLista >= 0 && posicaoLista < indicesFuncionarios.size() )
    {
        return indicesFuncionarios[posicaoLista];
    }
    else
    {
        return -1;
    }
}

void GerenciadorFuncionarios::exibirDadosEConfirmarAcao( const std::vector<int>& indicesFuncionarios )
{
    if( indicesFuncionarios.size() == 1 )
    {
        interfaceFuncionario.exibirTitulo( "          FUNCIONÁRIO ENCONTRADO          " );
        cadastroFuncionario.exibirDadosFuncionario( funcionariosCadastrados[ indicesFuncionarios[0] ] );

        if( confirmarAcao( "Deseja remover este funcionário? (s/n): " ) )
        {
            std::string nomeUsuarioRemovido = funcionariosCadastrados[indicesFuncionarios[0]].nome;

            funcionariosCadastrados.erase( funcionariosCadastrados.begin() + indicesFuncionarios[0] );
            interfaceFuncionario.exibirMensagemSucesso( nomeUsuarioRemovido + " foi removido com sucesso." );
        }
        else
        {
            std::string nomeUsuarioRemovido = funcionariosCadastrados[indicesFuncionarios[0]].nome;
            interfaceFuncionario.exibirMensagemSucesso( nomeUsuarioRemovido + " não foi removido por opção do usuário." );
        }
    }
}

void GerenciadorFuncionarios::buscarFuncionarioPorNome()
{
    if( cadastroEstaVazio() )
    {
        return;
    }

    std::vector<int> indicesFuncionarios = buscarIndicePorNomeDigitado();

    if( indicesFuncionarios.empty() )
    {
        interfaceFuncionario.exibirMensagemErro( "Funcionário não encontrado!" );
    }
    else if( indicesFuncionarios.size() == 1 )
    {
        interfaceFuncionario.exibirTitulo( "          FUNCIONÁRIO ENCONTRADO          " );
        cadastroFuncionario.exibirDadosFuncionario( funcionariosCadastrados[ indicesFuncionarios[0] ] );
    }
    else if( indicesFuncionarios.size() > 1 )
    {
        interfaceFuncionario.exibirTitulo( "          FUNCIONÁRIO ENCONTRADO          " );
        int indiceFuncionarioEscolhido = selecionarFuncionarioListado( indicesFuncionarios );

        if( indiceFuncionarioEscolhido == -1)
        {
            interfaceFuncionario.exibirMensagemErro( "Opção inválida." );
        }
        else
        {
            cadastroFuncionario.exibirDadosFuncionario( funcionariosCadastrados[indiceFuncionarioEscolhido]);
        }
    }
}

void GerenciadorFuncionarios::removerFuncionarioPorNome()
{
    if( cadastroEstaVazio( ) )
    {
        return;
    }

    std::vector<int> indicesFuncionarios = buscarIndicePorNomeDigitado();

    if( indicesFuncionarios.empty() )
    {
        interfaceFuncionario.exibirMensagemErro( "Funcionário não encontrado!" );
    }

    exibirDadosEConfirmarAcao( indicesFuncionarios );

    if( indicesFuncionarios.size() > 1 )
    {
        interfaceFuncionario.exibirTitulo( "          FUNCIONÁRIO ENCONTRADO          " );
        int indiceFuncionarioEscolhido = selecionarFuncionarioListado( indicesFuncionarios );

        if( indiceFuncionarioEscolhido == -1)
        {
            interfaceFuncionario.exibirMensagemErro( "Opção inválida." );
        }
        else
        {
            cadastroFuncionario.exibirDadosFuncionario( funcionariosCadastrados[indiceFuncionarioEscolhido] );

            if( confirmarAcao( "Deseja remover este funcionário? (s/n): " ) )
            {
                std::string nomeUsuarioRemovido = funcionariosCadastrados[indiceFuncionarioEscolhido].nome;

                funcionariosCadastrados.erase( funcionariosCadastrados.begin() + indiceFuncionarioEscolhido );

                interfaceFuncionario.exibirMensagemSucesso( nomeUsuarioRemovido + " foi removido com sucesso." );
            }
            else
            {
                std::string nomeUsuarioRemovido = funcionariosCadastrados[indiceFuncionarioEscolhido].nome;
                interfaceFuncionario.exibirMensagemSucesso( nomeUsuarioRemovido + " não foi removido por opção do usuário." );
            }
        }
    }
}

void GerenciadorFuncionarios::editarFuncionarioPorNome()
{
    if( cadastroEstaVazio() )
    {
        return;
    }

    std::vector<int> indiceFuncionario = buscarIndicePorNomeDigitado();

    if( indiceFuncionario.empty() )
    {
        interfaceFuncionario.exibirMensagemErro( "Nenhum funcionário encontrado." );
    }
    else
    {
        interfaceFuncionario.exibirTitulo( "          FUNCIONÁRIO ENCONTRADO          " );

        Funcionario funcionarioTemporario = funcionariosCadastrados[indiceFuncionario[0]];
        cadastroFuncionario.exibirDadosFuncionario( funcionarioTemporario );

        if( confirmarAcao( "Deseja editar este funcionário? (s/n): " ) )
        {
            cadastroFuncionario.lerDadosFuncionario( funcionarioTemporario );

            if( cadastroFuncionario.validarDadosFuncionario( funcionarioTemporario ) )
            {
                funcionariosCadastrados[indiceFuncionario[0]] = funcionarioTemporario;
                interfaceFuncionario.exibirMensagemSucesso( funcionariosCadastrados[indiceFuncionario[0]].nome + " editado com sucesso." );
            }
            else
            {
                interfaceFuncionario.exibirMensagemErro( "Edição cancelada." );
            }
        }
        else
        {
            interfaceFuncionario.exibirMensagemSucesso( "Edição cancelada por opção do usuário." );
        }
    }
}