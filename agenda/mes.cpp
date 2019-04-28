#include <iostream>
#include "mes.hpp"

using namespace std;

Mes::Mes(int ano, string nome, int codigoMes, int numDiasMes) : Ano(ano), Nome(nome), CodigoMes(codigoMes), NumDiasMes(numDiasMes) {

    Dias = new ConjuntoDeDias(ano, codigoMes, numDiasMes);

}

Mes::~Mes() {

}

void Mes::inserirCompromisso(Compromisso *compromisso)
{

    Dias->inserirCompromisso(compromisso);

}
