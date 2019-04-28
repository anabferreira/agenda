#include <iostream>
#include <string>

#include "agenda.hpp"
#include "utils.hpp"

using namespace std;

Agenda::Agenda() : AgendaEstaAberta(false){}

Agenda::~Agenda() {}

void Agenda::abrir(int ano) {

    criarEstruturas(ano);

    AgendaEstaAberta = true;

    Ano = ano;

}

void Agenda::criarEstruturas(int ano) {

    Meses = new ListaEncadeada<Mes>();

    for (int i = 0; i < 12; i++)
    {

        int numDiasMes = getNumeroDeDias((i+1),ano);

        string nome = getNomeDoMes((i+1));

        Mes *mes = new Mes(ano, nome, (i+1), numDiasMes);

        Meses->Inserir(i, *mes);

    }

}

bool Agenda::isAgendaEstaAberta() {
    return AgendaEstaAberta;
}

void Agenda::inserirCompromisso(Compromisso *compromisso) {

    Node<Mes> *nodeMes = Meses->Get((compromisso->CodigoMes - 1));
    Mes mes = nodeMes->Valor;
    mes.inserirCompromisso(compromisso);

}


void Agenda::removerCompromisso(int codigoDoMes, int dia, int hora){
        // recuperar o no do mes
        Node<Mes> *nodeMes = Meses->Get(codigoDoMes-1);
        // recuperar o conteudo do no
        Mes *mes = &nodeMes->Valor;
        // recuperar o tad que contem a tabela de lista de compromissos
        ConjuntoDeDias *conjunto = mes->Dias;
        // recuperar a lista da tabela dado o dia
        ListaEncadeada<Compromisso> listaCompromisso = conjunto->compromissos[dia-1];
        // recuperar o no de compromisso dado a hora
        Node<Compromisso> *nodeCompromisso = listaCompromisso.Get(hora-1);
        // recuperar o conteudo do no
        Compromisso *compromisso = &nodeCompromisso->Valor;
        // alterar o conteudo da descricao do no
        compromisso->Descricao = "";
}

void Agenda::listarCompromissos() {

    cout << "Ano - " << Ano << "\n";

    // listar meses
    for (int i = 0; i < 12; i++)
    {
        Node<Mes> *nodeMes = Meses->Get(i);
        Mes *mes = &nodeMes->Valor;

        ConjuntoDeDias *conjunto = mes->Dias;

        for (int j = 0; j < mes->NumDiasMes; j++)
        {

            ListaEncadeada<Compromisso> *listaCompromissosAgendados = new ListaEncadeada<Compromisso>();

            ListaEncadeada<Compromisso> listaCompromisso = conjunto->compromissos[j];

            for (int k = 0; k < listaCompromisso.GetContador(); k++)
            {
                Node<Compromisso> *nodeCompromisso = listaCompromisso.Get(k);
                Compromisso compromisso = nodeCompromisso->Valor;
                if (compromisso.Descricao.compare("") != 0)
                {
                    listaCompromissosAgendados->InserirCauda(compromisso);
                }
            }

            if (listaCompromissosAgendados->GetContador() > 0)
            {
                cout << "Mes - " << mes->Nome << "\n";

                for (int k = 0; k < listaCompromissosAgendados->GetContador(); k++)
                {
                    Node<Compromisso> *nodeCompromisso = listaCompromissosAgendados->Get(k);
                    Compromisso compromisso = nodeCompromisso->Valor;
                    if (compromisso.Descricao.compare("") != 0)
                    {
                        cout << "Dia -> " << compromisso.Dia << " Hora -> " << compromisso.Hora
                            << " Descricao -> " << compromisso.Descricao << "\n";
                    }
                }

            }

        }
    }
}

bool Agenda::verificarSeExisteCompromissoAgendado(int codigoDoMes, int dia, int hora ) {

    // recuperar o no do mes
    Node<Mes> *nodeMes = Meses->Get(codigoDoMes-1);
    // recuperar o conteudo do no
    Mes *mes = &nodeMes->Valor;
    // recuperar o tad que contem a tabela de lista de compromissos
    ConjuntoDeDias *conjunto = mes->Dias;
    // recuperar a lista da tabela dado o dia
    ListaEncadeada<Compromisso> listaCompromisso = conjunto->compromissos[dia-1];
    // recuperar o no de compromisso dado a hora
    Node<Compromisso> *nodeCompromisso = listaCompromisso.Get(hora-1);
    // recuperar o conteudo do no
    Compromisso *compromisso = &nodeCompromisso->Valor;
    // alterar o conteudo da descricao do no

    if (compromisso->Descricao.compare("") != 0){
        return true;
    }

    return false;
}

void Agenda::fechar() {

}
