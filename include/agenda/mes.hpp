#ifndef MES_HPP_INCLUDED
#define MES_HPP_INCLUDED

#include <iostream>

#include "listaEncadeada.hpp"
#include "compromisso.hpp"
#include "conjuntodedias.hpp"

using namespace std;

struct Mes
{

    int Ano;
    string Nome;
    int CodigoMes;
    int NumDiasMes;

    ConjuntoDeDias *Dias;

    Mes(int ano, string nome, int codigoMes, int numDiasMes);
    ~Mes();

    void inserirCompromisso(Compromisso *compromisso);

};

#endif // MES_HPP_INCLUDED
