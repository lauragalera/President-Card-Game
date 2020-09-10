#include "jugador.h"
#include "conjuntcartes.h"
#include "jugada.h"

//CONSTRUCTORS I DESTRUCTOR----------------------------------------------
Jugador::Jugador()
{
    a_nom=" ";
    a_actiu=false;
    a_t = NULL;

}
Jugador::Jugador(string nom)
{
    a_nom=nom;
    a_actiu=true;
    a_t = new ConjuntCartes;
}

Jugador::Jugador(const Jugador &j)
{
    copiar(j);
}

Jugador::~Jugador()
{
    alliberar();
}

//CONSULTORS-----------------------------------------------------------
void Jugador::mostrarCartesJugador() const
{
    a_t->mostrarCartes();
}

string Jugador::obtenirNom() const
{
    return a_nom;
}

bool Jugador::estaActiu() const
{
    return a_actiu==true;
}

Jugada Jugador::fer_jugada() const
{
    Jugada aux;
    cout<<"QUINES CARTES VOLS TIRAR?" <<endl;
    cin >>aux;
    return aux;
}

bool Jugador::teCartes(Jugada j) const
{
    int compt=0, i=0;
    while(compt<j.rebreQuant() && (a_t->obtenirCarta(i).trobar_valor()<=j.numeroAmbValor())){
        if((a_t->obtenirCarta(i).trobar_valor())==j.numeroAmbValor()) compt++;
        i++;
    }
    return compt==j.rebreQuant();
}

bool Jugador::NoQuedenCartes() const
{
    return a_t->buida();
}
void Jugador::mostrarCartesjugades(Jugada j) const
{
    cout<<"TIRADA: ";
    int compt=0, i=0;
    while(compt<j.rebreQuant() && (a_t->obtenirCarta(i).trobar_valor()<=j.numeroAmbValor())){
        if((a_t->obtenirCarta(i).trobar_valor())==j.numeroAmbValor()){
                a_t->obtenirCarta(i).mostrar();
                compt++;
        }
        i++;
    }
    cout<<endl;
}

Carta Jugador::buscarCarta(int num) const
{
    int pos=a_t->trobarposCarta(num);
    return a_t->obtenirCarta(pos);
}

//MODIFICADORS---------------------------------------------------------

void Jugador::inserirCartaOrdJugador(Carta c)
{
    a_t->inserirCartaOrd(c);
}

void Jugador::actualitzarEstat()
{
    a_actiu=false;
}

void Jugador::eliminarCarta(int num)
{
    int pos= a_t->trobarposCarta(num);
    a_t->eliminarSabentPos(pos);
}

void Jugador::repCartes(Jugador dona, int num)
{
    int numeroCartesJug=dona.a_t->total();
    while(num>0){
        Carta c=dona.a_t->obtenirCarta(numeroCartesJug-num);
        a_t->inserirCartaOrd(c);
        num--;
    }
}

void Jugador::eliminarFinal(int num)
{
    a_t->modificarTotal(num);
}
//OPERADORS REDEFINITS-------------------------------------------------
Jugador& Jugador::operator=(const Jugador &j)
{
    if(&j != this){
        alliberar();
        copiar(j);
    }
    return(*this);
}

//PRIVATS--------------------------------------------------------------

void Jugador::alliberar()
{
    delete a_t;
    a_t=NULL;
}

void Jugador::copiar(const Jugador& j)
{
    a_nom=j.a_nom;
    a_actiu=j.a_actiu;
    a_t= new ConjuntCartes;
    (*a_t)=(*j.a_t);
}
