#ifndef JUGADOR_H
#define JUGADOR_H
#include "conjuntcartes.h"
#include "jugada.h"
#include <iostream>

using namespace std;

class Jugador
{
    public:
        // CONSTRUCTORS I DESTRUCTOR ----------------------------------
        Jugador();
        //Pre:--; Post:Jugador invisible
        Jugador(string nom);
        //Pre:--; Post:crea un jugador amb el nom, actiu i amb un ConjuntCartes
        Jugador(const Jugador &j);
        //Pre:--; Post:this es una copia de j
        ~Jugador();
        //Pre:--; Post:elimina la ma de cartes del jugador

        //CONSULTORS----------------------------------------------------
        void mostrarCartesJugador() const;
        //Pre:--; Post:mostra la ma de cartes del jugador
        string obtenirNom() const;
        //Pre:--; Post:retorna el nom del jugador
        bool estaActiu() const;
        //Pre:--; Post:retorna si el jugador esta actiu durant la partida
        Jugada fer_jugada() const;
        //Pre:--; Post:el jugador fa una jugada
        bool teCartes(Jugada j) const;
        //Pre:--; Post:retorna cert si a la ma de jugador hi ha les cartes de la jugada
        bool NoQuedenCartes() const;
        //Pre:--; Post:retorna cert si el jugador no te cap carta
        void mostrarCartesjugades(Jugada j) const;
        //Pre:--; Post:mostra les cartes de la ma del jugador que corresponen a la seva jugada
        Carta buscarCarta(int) const;
        //Pre:--; Post:retorna la primera carta de la ma del jugador que coincideix amb el numero donat
        //MODIFICADORS---------------------------------------------------
        void inserirCartaOrdJugador(Carta c);
        //Pre:--; Post:insereix la carta a la ma del jugador de manera ordenada
        void actualitzarEstat();
        //Pre:estat del jugador actiu; Post: posa l'estat del jugador a inactiu
        void eliminarCarta(int);
        //Pre:--; Post:donat el numero de la carta elimina la primera de la ma que coincideix amb aquest
        void repCartes(Jugador dona, int num);
        //Pre:--; Post: copia les num millors cartes del jugador que dona al jugador this
        void eliminarFinal(int num);
        //Pre:el jugador te cartes; Post: elimina les num ultimes cartes del jugador this
        //OPERADORS REDEFINITS--------------------------------------------
        Jugador& operator=(const Jugador &j);

    private:
        string a_nom;
        bool a_actiu;
        ConjuntCartes *a_t; //cada jugador te un conjunt de cartes

        void alliberar();
        //Pre:--; Post:elimina la ma de cartes del jugador
        void copiar(const Jugador& j);
        //Pre:--; Post:this es una copia de j


};

#endif // JUGADOR_H
