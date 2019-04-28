#ifndef CONJUNTODEDIAS_HPP_INCLUDED
#define CONJUNTODEDIAS_HPP_INCLUDED

#include "listaEncadeada.hpp"
#include "compromisso.hpp"

struct ConjuntoDeDias
{

    int Ano;
    int CodigoDoMes;
    int NumDiasMes;
    ListaEncadeada<Compromisso> *compromissos;

    ConjuntoDeDias(int ano, int codigoDoMes, int numDiasMes);
    ~ConjuntoDeDias();
    void inserirCompromisso(Compromisso *compromisso);
    void construirEstruturas();
};

#endif // CONJUNTODEDIAS_HPP_INCLUDED
