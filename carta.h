#ifndef CARTA_H
#define CARTA_H


class Carta
{
    public:
        // CONSTRUCTORS------------------------------------------------
        Carta();
        // Pre: --; Post: carta nula
        Carta(int num, int pal);
        // Pre: --; Post: nova carta

        // CONSULTORS -------------------------------------------------
        int trobar_valor() const;
        //Pre:--; Post: dona el valor de la carta essent 3 el mes petit i 2 el mes gran
        int numeroCarta() const;
        //Pre--; Post: retorna el numero de la carta
        void mostrar() const;
        // Pre: --; Post: mostra la carta

        //operadors relacionals
        bool operator ==(const Carta &c) const;

        bool operator !=(const Carta &c) const;

        bool operator <(const Carta &c) const;

        bool operator <=(const Carta &c) const;

        bool operator >(const Carta &c) const;

        bool operator >=(const Carta &c) const;
    private:
        int a_num;
        int a_pal; //index de la taula
        int a_valor; //de 3 a 2

};

#endif // CARTA_H
