#include <iostream>
#include <ctype.h>

using namespace std;

 int  getNumeroDeDias(int mes, int ano)
{

	if( mes == 2)
	{
		if((ano%400==0) || (ano%4==0 && ano%100!=0))
			return 29;
		else
			return 28;
	}

	else if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8
        ||mes == 10 || mes==12)
		return 31;
	else
		return 30;

}

string getNomeDoMes(int mes) {

    string name = "";

    switch (mes)
    {
        case 1:
            name = "Janeiro";
            break;
        case 2:
            name = "Fevereiro";
            break;
        case 3:
            name = "Marco";
            break;
        case 4:
            name = "Abril";
            break;
        case 5:
            name = "Maio";
            break;
        case 6:
            name = "Junho";
            break;
        case 7:
            name = "Julho";
            break;
        case 8:
            name = "Agosto";
            break;
        case 9:
            name = "Setembro";
            break;
        case 10:
            name = "Outubro";
            break;
        case 11:
            name = "Novembro";
            break;
        case 12:
            name = "Dezembro";
            break;
    }

    return name;

}

bool validaMes (int mes){

    if (cin.fail()){

        cin.clear();
        cin.ignore(256,'\n');
        return false;

    }

    if ((1<=mes)&&(mes<=12)){

        return true;

    } else {

        return false;

    }
}

bool validaDia (int dia, int mes, int ano){

    if (cin.fail()){

        cin.clear();
        cin.ignore(256,'\n');
        return false;

    }

    if ((1<=dia)&&(dia<= getNumeroDeDias(mes, ano))){

        return true;

    } else {

        return false;

    }

}

bool validaHora (int hora){

    if (cin.fail()){

        cin.clear();
        cin.ignore(256,'\n');
        return false;

    }

    if ((1<=hora)&&(hora<=24)){

        return true;

    } else {

        return false;
    }

}

bool validaAno (int ano){

    if (cin.fail()){

        cin.clear();
        cin.ignore(256,'\n');
        return false;

    }

    if ((1000<= ano)&&(ano<=3000)){

        return true;

    } else {

        return false;
    }

}
