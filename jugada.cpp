#include "jugada.h"

Jugada::Jugada()
{
    a_quantitat=0;
    a_numero=0;
}

//CONSULTORS-------------------------------------------------------
bool Jugada::esDos() const
{
    return a_numero==2;
}

bool Jugada::jugadorUsaPila() const
{
    return (a_quantitat==-1 && a_numero==-1);
}

bool Jugada::passa() const
{
    return (a_quantitat==0 && a_numero==0);
}

bool Jugada::mesGran(Jugada ultima) const
{
    bool correcte=false;
    if(ultima.a_quantitat==-2 && ultima.a_numero==-2) correcte=true;
    else if(a_quantitat==ultima.a_quantitat){
        if(ultima.numeroAmbValor()<numeroAmbValor()) correcte=true;
        }
    return correcte;
}

int Jugada::rebreQuant() const
{
    return a_quantitat;
}

int Jugada::rebreNum() const
{
    return a_numero;
}
int Jugada::numeroAmbValor() const
{
    if(a_numero==1 || a_numero==2) return (a_numero+10);
    else return (a_numero-2);
}
//OPERADOR DE FLUX-------------------------------------------------
istream& operator>>(istream &i, Jugada &j)
{
    i>>j.a_quantitat;
    i>>j.a_numero;

    return i;
}

//MODIFICADORS-----------------------------------------------------

void Jugada::inicialitzar()
{
    a_quantitat=-2;
    a_numero=-2;
}
