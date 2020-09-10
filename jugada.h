#ifndef JUGADA_H
#define JUGADA_H
#include <iostream>

using namespace std;

class Jugada
{
    public:
        //CONSTRUCTOR---------------------------------------------------
        Jugada();

        //CONSULTORS----------------------------------------------------
        bool esDos() const;
        //Pre:--; Post:retorna cert si el numero de la carta es un dos
        bool jugadorUsaPila() const;
        //Pre:--; Post:retorna cert si a la jugada el jugador usa la pila
        bool passa() const;
        //Pre:--; Post:retorna cert si el jugador passa
        bool mesGran(Jugada ultima) const;
        //Pre:--; Post:retorna cert si la jugada actual es mes gran que l'anterior
        int rebreQuant() const;
        //Pre:--; Post:retorna la quantitat de cartes d'aquesta jugada
        int rebreNum() const;
        //Pre:--; Post:retorna el numero de la carta escollida en aquella jugada
        int numeroAmbValor() const;
        //OPERADOR DE FLUX----------------------------------------------
        friend istream& operator>>(istream &i, Jugada &j);
        //Pre:--; Post:operador per a llegir una jugada
        //MODIFICADORS--------------------------------------------------
        void inicialitzar();
        //Pre:--; Post:inicialitza la jugada amb numeros negatius

    private:
        //ATRIBUTS
        int a_quantitat;
        int a_numero;
};

#endif // JUGADA_H
