#include "FuncionariosDB.h"
#include </usr/include/postgresql/libpq-fe.h>

FuncionariosDB::FuncionariosDB( const std::string& connectingString ) :
connectingString(connectingString)
{}

bool FuncionariosDB::cadastrarFuncionario( const Funcionario& funcionario )
{

}

std::vector<Funcionario> FuncionariosDB::listarFuncionarios()
{

}

Funcionario FuncionariosDB::buscarFuncionarioPorId( int id )
{

}

std::vector<Funcionario> FuncionariosDB::buscarFuncionarioPorNome( const std::string& nome )
{

}

bool FuncionariosDB::atualizarFuncionarioPorId( int id, const Funcionario& funcionario )
{

}

bool FuncionariosDB::removerFuncionarioPorId( int id )
{

}

bool FuncionariosDB::verificarFuncionarioExiste( int id )
{
	PGconn* connection = PQconnectdb(connectingString.c_str());

	if( PQstatus(connection) != CONNECTION_OK )
	{
		PQfinish(connection);
		return false;
	}

	std::string idText = std::to_string(id);
	std::string stringSQL = "SELECT id from funcionarios_registrados where id = $1;";

	PGresult* resultado = PQexecParams(connection, idText.c_str(), 1, stringSQL.c_str());

	if(PQntuples(resultado) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}

	PQfinish(connection);
	return false;
}
