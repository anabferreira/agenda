#ifndef COMPROMISSO_HPP_INCLUDED
#define COMPROMISSO_HPP_INCLUDED

#include <iostream>

using namespace std;

struct Compromisso
{
    int CodigoMes;
    int Dia;
    int Hora;
    string Descricao;

    Compromisso(int codigoMes, int dia, int hora, string descricao);
    ~Compromisso();
};

#endif // COMPROMISSO_HPP_INCLUDED
