#include <iostream>
#include "joc.h"

using namespace std;

int main()
{
    Joc partida;
    partida.inicialitzar();//Demana llavor, jugadors i nombre de baralles
    partida.generarIRepartirCartes();
    char continuar = 'S';
    while(continuar!='N')
    {
        partida.ronda();
        cout<<"VOLS FER UNA NOVA RONDA?"<<endl;
        cin>>continuar;
        if(continuar!='N')
        {
           cout<<"CLASSIFICACIO ACTUAL:"<<endl;
            partida.mostrarClassificacio();
            partida.inicialitzarRonda();
            partida.generarIRepartirCartes();
            partida.intercanviarCartes();
        }
    }
    cout<<"CLASSIFICACIO FINAL:"<<endl;
    partida.mostrarClassificacio();
    cout<<"*** FINAL DEL JOC ***" <<endl;
    return 0;
}
