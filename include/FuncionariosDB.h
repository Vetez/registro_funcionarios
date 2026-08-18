#ifndef FUNCIONARIOS_DB_H
#define FUNCIONARIOS_DB_H

#include <string>
#include <vector>
#include "Funcionario.h"

class FuncionariosDB
{
public:
	FuncionariosDB( const std::string& connectingString );

    bool cadastrarFuncionario( const Funcionario& funcionario );
    std::vector<Funcionario> listarFuncionarios();
    Funcionario buscarFuncionarioPorId( int id );
    std::vector<Funcionario> buscarFuncionarioPorNome( const std::string& nome );
    bool atualizarFuncionarioPorId( int id, const Funcionario& funcionario );
    bool removerFuncionarioPorId( int id );
    bool verificarFuncionarioExiste( int id );

private:
	std::string connectingString = 
	"host=localhost "
	"port=5432 "
	"dbname=gerenciador_de_funcionarios "
	"user=postgres "
	"password=33531414 ";

};

#endif