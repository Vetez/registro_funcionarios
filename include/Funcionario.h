#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>

struct Funcionario
{
    int id_funcionario;
    std::string nome;
    int idade;
    double salario;
    double tempoEmpresa;
};

#endif