#ifndef CONJUNTCARTES_H
#define CONJUNTCARTES_H
#include "carta.h"


class ConjuntCartes
{
    public:
        // CONSTRUCTORS I DESTRUCTOR ----------------------------------
        ConjuntCartes();
        // Pre: --; Post:taula buida
        ConjuntCartes(int n);
        // Pre: --; Post:taula per a n elements
        ConjuntCartes(const ConjuntCartes &t);
        // Pre: --; Post:*this es copia de la taula t
        ~ConjuntCartes();
        // Pre: --; Post: allibera la taula

        // CONSULTORS -------------------------------------------------
        void mostrarCartes() const;
        //Pre:--; Post:mostra totes les cartes de la taula
        Carta obtenirCarta(int) const;
        //Pre:--; Post:retorna la carta de la pos rebuda
        int trobarposCarta(int) const;
        //Pre:--; Post:retorna la pos de la primera carta de la ma que coincideix amb num donat
        bool buida() const;
        //Pre:--;Post:cert si no hi ha cap carta
        int total() const;
        //Pre:--;Post:retorna quantes cartes hi ha

        // MODIFICADORS -----------------------------------------------
        void intercanviar_cartes(int, int);
        //Pre:A=a B=b; Post: b=A a=B
        void inserirCartaOrd(Carta c);
        //Pre:--; Post:insereix c a la taula de forma ordenada per valor
        void eliminarSabentPos(int pos);
        //Pre:--; Post:sabent la pos elimina la carta de la ma
        void modificarTotal(int);
        //Pre:--; Post:elimina el num de cartes donat començant pel final
        // OPERADORS REDEFINITS ---------------------------------------
        ConjuntCartes& operator=(const ConjuntCartes &t); //la taula es copia de t

        ConjuntCartes& operator +=(const Carta &c);//afegeix una carta a la ultima posicio i incrementa n

    private:
        int a_n;
        int a_max;
        Carta *a_t;

        int cercaDico(Carta c,int,int) const;
        //Pre:--; Post:retorna la pos per inserir
        void alliberar();
        // Pre: --; Post: memoria alliberada
        void reservar();
        // Pre: --; Post: guarda a aquesta la taula maxima
        void copiar(const ConjuntCartes &t);
        // Pre: --; Post: *this es copia de t
        void expandir();
        // Pre: --; Post: aquesta es una nova taula amb doble d'espai

};

#endif // CONJUNTCARTES_H
