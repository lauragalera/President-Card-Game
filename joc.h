#ifndef JOC_H
#define JOC_H
#include "joc.h"
#include "jugador.h"
#include "pilacartes.h"
#include "jugada.h"

class Joc
{
    public:
        //CONSTRUCTORS I DESTRUCTOR--------------------------------------
        Joc();
        Joc(const Joc &j);
        ~Joc();
        //CONSULTORS-----------------------------------------------------
        void mostrarClassificacio() const;
        //Pre:--; Post: mostra la classificacio dels jugadors
        int buscarUltim() const;
        //Pre:--; Post:retorna la posicio de l'ultim jugador
        //MODIFICADORS---------------------------------------------------
        void inicialitzar();
        //Pre:--; Post:demana la llavor, num jugadors, nom jugadors i baralles a usar
        void generarCartes(ConjuntCartes *t);
        //Pre:--; Post:crea totes les cartes amb les que es jugaran de manera ordenada
        unsigned seguent();
        //Pre:--; Post: genera la seguent llavor
        int calcular_pos(int maxim);
        //Pre:--; Post: trobar la pos per intercanviar carta amb algorisme Fisher-Yates
        void barrejarCartes(ConjuntCartes *t, int);
        //Pre:Cartes ordenades; Post:barreja les cartes
        void repartirCartes(ConjuntCartes *t, int);
        //Pre:--; Post:reparteix les cartes començant per l'ultim jugador
        void generarIRepartirCartes();
        //Pre:--; Post:genera totes les cartes, les barreja i les reparteix
        void empilarCartesIEliminar(Jugada ultima, int k, int &actius);
        //Pre:jugador segur te la jugada; Post:segons la jugada, empila una a una les cartes, les elimina i, si jugador es queda sense cartes, el posa a inactiu
        void ronda();
        //Pre:--; Post: permet fer una ronda a l'esclau
        void inicialitzarRonda();
        //Pre:--; Post:esborra la pila i deixa la taula de jugadors preparada
        void intercanviarCartes();
        //Pre:--; Post:segons el criteri de classificacio s'intercanvien les cartes

        //OPERADORS REDEFEINITS------------------------------------------
        Joc& operator=(const Joc&j);
    private:
        //ATRIBUTS
        Jugador *a_j; //taula de jugadors
        Jugador *a_classificacio; //taula ordenada per guanyadors
        int a_n; //nombre de jugadors
        unsigned a_llavor; //llavor
        int a_baralla; //baralles entrades
        PilaCartes pila; //pila de cartes jugades

        static const int N_CARTES=12;
        static const int N_PALS=4;
        static const int A=1103515245;
        static const int C=12345;
        static const int M=32768;

        void alliberar();
        //Pre:--; Post:s'elimina la taula de jugadors i classificats
        void copiar(const Joc &j);
        //Pre:--; Post:es copien tots els atributs, amb especial compter les taules


};

#endif // JOC_H
