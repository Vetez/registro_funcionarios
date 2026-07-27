#include "CadastroFuncionario.h"
#include "EntradaUsuario.h"

#include <iostream>
#include <iomanip>

	const std::string CIANO = "\033[36m";
	const std::string RESET = "\033[0m";

void CadastroFuncionario::lerDadosFuncionario( Funcionario& funcionario )
{
    std::cout << CIANO << "==========>|<=======>|<=======>|<=========" << RESET << '\n';
    funcionario.nome = entradaUsuario.lerNomeNaoVazio( "Nome do funcionário: " );

    funcionario.idade = entradaUsuario.lerInteiro( "Idade: " );

    funcionario.salario = entradaUsuario.lerDouble( "Salário: " );

    funcionario.tempoEmpresa = entradaUsuario.lerDouble ( "Tempo de empresa: " );

    std::cout << CIANO << "==========>|<=======>|<=======>|<=========" << RESET << '\n';
}

bool CadastroFuncionario::validarDadosFuncionario( const Funcionario& funcionario )
{
    bool dadosValidos { true };

    if( funcionario.idade < 16 )
    {
        interfaceFuncionario.exibirMensagemErro( "Idade inválida." );
        dadosValidos = false;
    }
    if( funcionario.salario <= 0 )
    {
        interfaceFuncionario.exibirMensagemErro( "Salário inválido." );
        dadosValidos = false;
    }
    if( funcionario.tempoEmpresa < 0 )
    {
        interfaceFuncionario.exibirMensagemErro( "Tempo de empresa inválido." );
        dadosValidos = false;
    }

    if( !dadosValidos )
    {
        interfaceFuncionario.exibirMensagemErro( "Dados inválidos. Cadastre esse funcionário novamente." );
    }

    return dadosValidos;
}

bool CadastroFuncionario::funcionarioEstaAptoParaPromocao( const Funcionario& funcionario )
{
    return funcionario.tempoEmpresa >= 2 && funcionario.idade >= 18 && funcionario.salario < 5000;
}

void CadastroFuncionario::exibirDadosFuncionario( const Funcionario& funcionario )
{
    interfaceFuncionario.exibirCampo("Nome", funcionario.nome);
    interfaceFuncionario.exibirCampo("Idade", std::to_string(funcionario.idade));
    interfaceFuncionario.exibirCampo("Salário", interfaceFuncionario.formatarMoeda(funcionario.salario));
    interfaceFuncionario.exibirCampo("Tempo de empresa", interfaceFuncionario.formatarAnos(funcionario.tempoEmpresa) + " anos");
}

void CadastroFuncionario::exibirResultadoPromocao( const Funcionario& funcionario, bool aptoParaPromocao )
{
    if( aptoParaPromocao )
    {
        interfaceFuncionario.exibirMensagemSucesso( "Status: Apto para promoção" );
    }
    else
    {
        interfaceFuncionario.exibirMensagemErro( "Status: Não está apto para promoção" );
        if( funcionario.idade < 18)
        {
            interfaceFuncionario.exibirMotivo( "Idade menor que 18." );
        }
        if( funcionario.tempoEmpresa < 2)
        {
            interfaceFuncionario.exibirMotivo( "Tempo de empresa menor que 2 anos." );
        }
        if( funcionario.salario >= 5000)
        {
            interfaceFuncionario.exibirMotivo( "Recebe igual ou acima de R$ 5000,00." );
        }
    }
}

void CadastroFuncionario::exibirFuncionarioComResultadoPromocao(const Funcionario& funcionario, bool aptoParaPromocao)
{
    exibirDadosFuncionario(funcionario);
    exibirResultadoPromocao(funcionario, aptoParaPromocao);
}
