#ifndef PILACARTES_H
#define PILACARTES_H
#include "carta.h"
#include <iostream>

using namespace std;


class PilaCartes
{
    public:
        // CONSTRUCTORS I DESTRUCTOR ----------------------------------
        PilaCartes();
        // Pre: --; Post: pila buida
        PilaCartes(const PilaCartes &o);
        // Pre: --; Post: *this és còpia de la pila o
        ~PilaCartes();
        // Pre: --; Post: memòria alliberada

        // CONSULTORS -------------------------------------------------
        bool buida() const;
        // Pre: -- ; Post: retorna cert si la pila es buida; fals en c.c.
        Carta cim() const;
        // Pre: pila no buida; Post: retorna el valor del cim de la pila
        void mostrarDeu() const;
        //Pre:-- Post:Mostra fins a 10 cartes de la pila
        // MODIFICADORS -----------------------------------------------
        void empila(Carta c);
        // Pre: --; Post: ha afegit s a dalt de la pila
        void desempila();
        // Pre: pila no buida; Post: ha eliminat element de dalt de la pila
        void buidarTotalment();
        //Pre:--; Post: allibera tot el que hi ha a la pila
        // OPERADORS REDEFINITS ---------------------------------------
        PilaCartes& operator=(const PilaCartes& o);
        // Pre: -- ; Post: aquesta pila es copia de la pila o


    private:
        struct Node{
        Carta valor;
        Node* seg;
        };

        // ATRIBUTS
        Node* a_cim; // punter al cim de la pila


        // METODES PRIVATS
        void copia(const PilaCartes& o);
        // Pre: pila buida; Post: aquesta pila es copia de o
        void allibera();
        // Pre: --; Post: memoria alliberada
};

#endif // PILACARTES_H
