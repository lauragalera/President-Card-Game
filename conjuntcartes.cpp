#include "conjuntcartes.h"
#include <iostream>

using namespace std;

//CONSTRUCTORS I DESTRUCTOR--------------------------------------
ConjuntCartes::ConjuntCartes()
{
    a_n=0;
    a_max=10;
    reservar();
}

ConjuntCartes::ConjuntCartes(int n)
{
    a_n=0;
    a_max=n;
    reservar();
}

ConjuntCartes::ConjuntCartes(const ConjuntCartes &t)
{
    copiar(t);
}

ConjuntCartes::~ConjuntCartes()
{
    alliberar();
}

// CONSULTORS -------------------------------------------------
void ConjuntCartes::mostrarCartes() const
{
    for(int i=0; i<a_n; i++){
        a_t[i].mostrar();
    }
    cout <<endl;
}

Carta ConjuntCartes::obtenirCarta(int i) const
{
    return a_t[i];
}

//Pre:--; Post:busca la primera carta de la ma que coincideix amb valor, SEGUR que hi es
int ConjuntCartes::trobarposCarta(int valor) const
{
    int i=0;
    int pos;
    bool trobat=false;
    while(i<a_n && !trobat){
        if(a_t[i].numeroCarta()==valor){
            pos=i;
            trobat=true;
        }
        i++;
    }
    return pos;
}

bool ConjuntCartes::buida() const
{
    return a_n==0;
}

int ConjuntCartes::total() const
{
    return a_n;
}
//MODIFICADORS-------------------------------------------------
void ConjuntCartes::intercanviar_cartes(int i, int j)
{
    Carta aux=a_t[i];
        a_t[i]=a_t[j];
        a_t[j]=aux;
}

void ConjuntCartes::inserirCartaOrd(Carta c)
{
    int pos=cercaDico(c,0,a_n-1); //busca la posicio
    if(a_n==a_max) expandir();
    for(int i=a_n; i>pos; i--)
        a_t[i]=a_t[i-1];
    a_t[pos]=c; //insereix c a la pos
    a_n++;
}

void ConjuntCartes::eliminarSabentPos(int pos)
{
    for(int i=pos; i<a_n-1; i++)
        a_t[i]=a_t[i+1];
    a_n--;
}

void ConjuntCartes::modificarTotal(int restar)
{
    a_n=a_n-restar;
}

// OPERADORS REDEFINITS ---------------------------------------
ConjuntCartes& ConjuntCartes::operator=(const ConjuntCartes &t)
{
    if(&t != this){
        alliberar();
        copiar(t);
    }
    return(*this);
}

ConjuntCartes& ConjuntCartes::operator +=(const Carta &c)
{
    if(a_n >= a_max){
        expandir();
    }
    a_t[a_n++] = c; //insereix c primer i despres incrementa a_n
    return(*this);
}

// PRIVATS--- -------------------------------------------------
int ConjuntCartes::cercaDico(Carta c, int esq, int dre) const
{
    int mig, pos;
    if(esq>dre) pos=esq;
    else {
        mig=(esq+dre)/2;
        if(a_t[mig]==c) pos=mig;
        else if(a_t[mig]<c) pos=cercaDico(c,mig+1,dre);
        else pos=cercaDico(c,esq,mig-1);
    }
    return pos;
}

void ConjuntCartes::alliberar()
{
    delete [] a_t;
}

void ConjuntCartes::reservar()
{
    a_t= new Carta[a_max];
}

void ConjuntCartes::copiar(const ConjuntCartes &t)
{
    a_n=t.a_n;
    a_max=t.a_max;
    reservar();
    for(int i=0; i<a_n; i++)
        a_t[i]=t.a_t[i];
}

void ConjuntCartes::expandir()
{
    a_max = 2*a_max;
    Carta *aux = new Carta[a_max];
    for(int i=0; i<a_n; i++)
        aux[i] = a_t[i];
    delete[] a_t;
    a_t = aux;
}
