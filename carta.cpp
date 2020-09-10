#include "carta.h"
#include <iostream>

using namespace std;


const char nomPal[] = {'O','C','E','B'};

//CONSTRUCTORS--------------------------------------------------

Carta::Carta()
{
    a_num=a_pal=a_valor=0;

}

Carta::Carta(int num, int pal)
{
   a_num=num;
   a_pal=pal;
   a_valor=trobar_valor();
}

// CONSULTORS -------------------------------------------------
int Carta::trobar_valor() const
{
    if(a_num==1 || a_num==2) return (a_num+10);
    else return (a_num-2);
}
int Carta::numeroCarta() const
{
    return a_num;
}

void Carta::mostrar() const
{
    cout <<"["<<a_num<<nomPal[a_pal]<<"]";
}
//operadors relacionals

bool Carta::operator ==(const Carta &c) const
{
    return (a_valor== c.a_valor) && (a_pal== c.a_pal);
}

bool Carta::operator !=(const Carta &c) const
{
    return !((*this) == c);
}

bool Carta::operator <(const Carta &c) const
{
    bool petit = a_valor < c.a_valor;
    if(a_valor == c.a_valor) petit = a_pal < c.a_pal;
    return petit;
}

bool Carta::operator <=(const Carta &c) const
{
    return ((*this) < c || (*this) == c);
}

bool Carta::operator >(const Carta &c) const
{
    return !((*this) < c || (*this) == c);
}

bool Carta::operator >=(const Carta &c) const
{
    return !((*this) < c);
}

