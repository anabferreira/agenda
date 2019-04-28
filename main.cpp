#include <iostream>

#include "agenda.hpp"
#include "compromisso.hpp"
#include "utils.hpp"

using namespace std;

int main()
{

    int opcao = 0;
    int ano = 0;
    bool executarMenu = true;

    Agenda *agenda = new Agenda();

    do {

        cout << "\nMinha Agenda \n";
        cout << "-------------------------------------------\n";
        cout << "1 - Abrir a Agenda\n";
        cout << "2 - Insere compromisso\n";
        cout << "3 - Remove compromisso\n";
        cout << "4 - Lista compromissos\n";
        cout << "5 - Verifica se existe compromisso agendado\n";
        cout << "6 - Fecha Agenda\n";
        cout << "Escolha a sua opcao e pressione <ENTER>: ";
        cin >> opcao;
        cout << "-------------------------------------------\n\n";

        switch (opcao)
        {
            case 1:
                {
                    if (agenda->isAgendaEstaAberta()) {

                        cout << " A agenda ja esta aberta...\n";
                        cout << "\n";

                    } else {

                        do {

                            cout << "Entre com o ano da agenda:\n";
                            cin >> ano;

                            if (validaAno(ano) == false){

                                cout << "\nO valor informado nao e valido\n\n";

                            }

                        } while ((validaAno(ano)== false));

                        cout << "\nAguarde a abertura da agenda...\n";

                        agenda->abrir(ano);

                        cout << "A agenda esta aberta.\n";

                        cout << "\n";

                    }
                }
                break;

            case 2:
                {

                    if (agenda->isAgendaEstaAberta()) {

                        int codigoMes = 0;
                        int dia = 0;
                        int hora = 0;
                        string descricao = "";

                        cout << "Entre com os dados do Compromisso:\n";
                        cout << "----------------------------------\n\n";

                        do {

                            cout << "Entre com o mes do compromisso:\n";
                            cin >> codigoMes;

                            if (validaMes(codigoMes) == false){

                               cout << "\nO valor informado nao e valido\n\n";

                            }

                            } while (validaMes(codigoMes) == false);

                        do{

                            cout << "Entre com o dia do compromisso:\n";
                            cin >> dia;

                            if (validaDia(dia, codigoMes, ano) == false){

                               cout << "\nO valor informado nao e valido\n\n";

                            }
                        } while (validaDia(dia, codigoMes, ano) == false);


                         do {

                            cout << "Entre com a hora do compromisso:\n";
                            cin >> hora;

                            if (validaHora(hora) == false){

                                cout << "\nO valor informado nao e valido\n\n";

                            }

                            } while (validaHora(hora) == false);

                        cout << "Descricao:\n";
                        cin.ignore();
                        getline(cin, descricao);
                        cout << "\n";

                        Compromisso *compromisso = new Compromisso(codigoMes, dia, hora, descricao);

                        agenda->inserirCompromisso(compromisso);

                        cout << "O compromisso foi inserido.\n";

                        cout << "\n";
                    }
                    else
                    {
                        cout << "A agenda nao esta aberta.\n";
                        cout << "\n";
                    }
                }
                break;

            case 3:
                {

                    if (agenda->isAgendaEstaAberta()) {

                        int codigoMes = 0;
                        int dia = 0;
                        int hora = 0;
                        string descricao = "";

                        cout << "Entre com os dados do compromisso para ser removido:\n";
                        cout << "----------------------------------------------------\n\n";

                        do {

                            cout << "Entre com o mes do compromisso:\n";
                            cin >> codigoMes;

                            if (validaMes(codigoMes) == false){

                               cout << "\nO valor informado nao e valido\n\n";

                            }

                            } while (validaMes(codigoMes) == false);

                        do{

                            cout << "Entre com o dia do compromisso:\n";
                            cin >> dia;

                            if (validaDia(dia, codigoMes, ano) == false){

                               cout << "\nO valor informado nao e valido\n\n";

                            }
                        } while (validaDia(dia, codigoMes, ano) == false);


                        do {

                            cout << "Entre com a hora do compromisso:\n";
                            cin >> hora;

                            if (validaHora(hora) == false){

                                cout << "\nO valor informado nao e valido\n\n";

                            }

                            } while (validaHora(hora) == false);

                        agenda->removerCompromisso(codigoMes, dia, hora);

                        cout << "O compromisso foi removido.\n";

                        cout << "\n";
                    }
                    else
                    {
                        cout << "A agenda nao esta aberta.\n";
                        cout << "\n";
                    }
                }
                break;


            case 4:
               {

                    if (agenda->isAgendaEstaAberta()) {

                        cout << "Listagem dos compromissos:\n";
                        cout << "--------------------------\n\n";

                        agenda->listarCompromissos();

                        cout << "\n";
                    }
                    else
                    {
                        cout << "A agenda nao esta aberta.\n";
                        cout << "\n";
                    }
                }
                break;

            case 5:
               {

                    if (agenda->isAgendaEstaAberta()) {

                        int codigoMes = 0;
                        int dia = 0;
                        int hora = 0;
                        string descricao = "";

                        cout << "Entre com o mes, dia e hora para verificar:\n";
                        cout << "-------------------------------------------\n\n";

                        do {

                            cout << "Entre com o mes:\n";
                            cin >> codigoMes;

                            if (validaMes(codigoMes) == false){

                               cout << "\nO numero informado nao e valido\n\n";

                            }

                            } while (validaMes(codigoMes) == false);

                        do{

                            cout << "Entre com o dia:\n";
                            cin >> dia;

                            if (validaDia(dia, codigoMes, ano) == false){

                               cout << "\nO numero informado nao e valido\n\n";

                            }
                        } while (validaDia(dia, codigoMes, ano) == false);


                        do {

                            cout << "Entre com a hora:\n";
                            cin >> hora;

                            if (validaHora(hora) == false){

                                cout << "\nO numero informado nao e valido\n\n";

                            }

                            } while (validaHora(hora) == false);

                        if(agenda->verificarSeExisteCompromissoAgendado(codigoMes, dia, hora)==true){

                            cout << "\nExiste compromisso nessa data \n\n";

                        } else {

                             cout << "\nNao existe compromisso nessa data \n\n";
                        }

                    }
                    else
                    {
                        cout << "A agenda nao esta aberta.\n";
                        cout << "\n";
                    }
                }
                break;

            case 6:
                {
                    cout << "Aguarde o fechamento da agenda...\n";

                    delete agenda;

                    executarMenu = false;
                }
                break;

            default:
                {
                    cout << "Opcao invalida\n";
                    cout << "Escolha uma opcao valida (1,2,3,4,5,6)\n";
                    cin >> opcao;
                }
                break;
        }

    } while (executarMenu == true);

    return 0;
}
