#include "carta.h"
#include "pilacartes.h"

// Pre: --; Post: pila buida
// COST: O(1)
PilaCartes::PilaCartes(){
    a_cim= NULL;
}

// Pre: --; Post: aquesta pila és còpia de la pila o
// COST: O(n)
PilaCartes::PilaCartes(const PilaCartes& o){
    a_cim= NULL;
    copia(o); // crida a mètode privat
}

// Pre: --; Post: memòria alliberada
// COST: O(n)
PilaCartes::~PilaCartes(){
    allibera(); // crida a mètode privat
}

// CONSULTORS -------------------------------------------------
// Pre: --
// Post: retorna cert si la pila és buida; fals en c.c.
// COST: O(1)
bool PilaCartes::buida() const{
    return a_cim==NULL;
}

// Pre: pila no buida
// Post: retorna el valor del cim de la pila
// COST: O(1)
Carta PilaCartes::cim() const{
    return a_cim->valor;
}

void PilaCartes::mostrarDeu() const{
    Node* aux=a_cim;
    int compt=0;
    while(aux!=NULL && compt!=10){
            aux->valor.mostrar();
            compt++;
            aux=aux->seg;
    }
    cout<<endl;
}
// MODIFICADORS -----------------------------------------------
// Pre: --; Post: ha afegit s a dalt de la pila
// COST: O(1)
void PilaCartes::empila(Carta c){
    Node* nou= new Node; // necessari reservar memoria
    nou->valor= c;
    nou->seg= a_cim;
    a_cim= nou;
}

// Pre: pila no buida
// Post: ha eliminat element de dalt de la pila
// COST: O(1)
void PilaCartes::desempila(){
    Node* aux= a_cim;
    a_cim= a_cim->seg;
    delete aux;
}

//Pre:--; Post: allibera tot el que hi ha a la pila
//COST: O(n)
void PilaCartes::buidarTotalment(){
    allibera();
}

// OPERADORS ---------------------------------------------
// Pre: -- ; Post: aquesta pila es copia de o
// COST: O(n)
PilaCartes& PilaCartes::operator=(const PilaCartes& o){
    if (this != &o){
        allibera();
        copia(o);
    }
    return *this;
}

// METODES PRIVATS ------------------------------------------
// Pre: pila buida; Post: aquesta pila es copia de o
// COST: O(n)
void PilaCartes::copia(const PilaCartes& o) {
    if(!o.buida()){
        Node *p, *q, *aux;
        p = new Node; a_cim = p;
        aux = o.a_cim; p->valor = aux->valor; p->seg = NULL;
        q = p;
        while (aux->seg!=NULL) {
            aux = aux->seg;
            p = new Node; q->seg = p;
            p->valor = aux->valor; p->seg = NULL;
            q = p;
        }
    }
}

// Pre: --; Post: memòria alliberada
// COST: O(n)
void PilaCartes::allibera(){
    while (!buida()) {
        Node* aux= a_cim;
        a_cim= a_cim->seg;
        delete aux;
    }
}



