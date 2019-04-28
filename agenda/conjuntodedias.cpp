#include <iostream>

#include "conjuntodedias.hpp"
#include "compromisso.hpp"

ConjuntoDeDias::ConjuntoDeDias(int ano, int codigoDoMes, int numDiasMes) :
    Ano(ano), CodigoDoMes(codigoDoMes), NumDiasMes(numDiasMes) {

    construirEstruturas();

}

ConjuntoDeDias::~ConjuntoDeDias() {

}

void ConjuntoDeDias::construirEstruturas()
{

    compromissos = new ListaEncadeada<Compromisso>[NumDiasMes];

    // construir a tabela de dias

    for (int i = 0; i < NumDiasMes; i++)
    {

        ListaEncadeada<Compromisso> *compromissoDia = new ListaEncadeada<Compromisso>();
        Compromisso *compromisso = nullptr;

        for (int j = 0; j < 24; j++)
        {
            compromisso = new Compromisso(CodigoDoMes, (i + 1), (j+1), "");
            compromissoDia->Inserir(j, *compromisso);
        }

        compromissos[i] = *compromissoDia;

    }

}

void ConjuntoDeDias::inserirCompromisso(Compromisso *compromisso)
{

    ListaEncadeada<Compromisso> compromissosDia = compromissos[(compromisso->Dia - 1)];
    Node<Compromisso> *nodeCompromissoHora = compromissosDia.Get((compromisso->Hora - 1));
    Compromisso *compromissoHora = &nodeCompromissoHora->Valor;
    if (!compromissoHora->Descricao.compare(""))
    {
        compromissoHora->Descricao = compromisso->Descricao;
    }
}
