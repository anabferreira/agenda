#ifndef AGENDA_HPP_INCLUDED
#define AGENDA_HPP_INCLUDED

#include "mes.hpp"
#include "compromisso.hpp"
#include "listaEncadeada.hpp"

struct Agenda
{
    int Ano;
    ListaEncadeada<Mes> *Meses;

    bool AgendaEstaAberta;
    Agenda();
    ~Agenda();
    void abrir(int ano);
    void criarEstruturas(int ano);
    bool isAgendaEstaAberta();
    void inserirCompromisso(Compromisso *compromisso);
    void removerCompromisso(int codigoDoMes, int dia, int hora);
    void listarCompromissos();
    bool verificarSeExisteCompromissoAgendado(int codigoDoMes, int dia, int hora);
    void fechar();
    void salvarArquivoAgenda();
};

#endif // AGENDA_HPP_INCLUDED
