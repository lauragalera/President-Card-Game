#include "joc.h"
#include "conjuntcartes.h"
#include "jugador.h"
#include "jugada.h"

//CONSTRUCTORS I DESTRUCTOR------------------------------------------------------------------
Joc::Joc()
{
    a_j=NULL;
    a_n=0;
    a_llavor=0;
    a_baralla=0;
    pila= PilaCartes();
}

Joc::Joc(const Joc &j)
{
    copiar(j);
}

Joc::~Joc()
{
    alliberar();
}

//CONSULTORS---------------------------------------------------------------------------------
void Joc::mostrarClassificacio() const
{
    int mig =(a_n-1)/2;
    for(int i=0; i<a_n; i++){
        if(i==0) cout<<"REI: ";
        else if(i>0 && ((i<mig && a_n%2==1) || (i<=mig && a_n%2==0))) cout<<"NOBLE: "; //tractem els casos que sigui parell o imparell a_n
        else if(i==mig && a_n%2==1) cout<<"BURGES: ";
        else if(i<a_n-1 && i>mig) cout <<"VASSALL: ";
        else if(i==a_n-1) cout <<"ESCLAU: ";
        cout<< a_classificacio[i].obtenirNom() <<endl;
    }
}

int Joc::buscarUltim() const
{
    int i=0, pos;
    bool trobat=false;
    while(i<a_n && !trobat){ //fem una cerca per trobar el jugador que no esta actiu, l'ultim
        if(a_j[i].estaActiu()){
            pos=i;
            trobat=true;
        }
        i++;
    }
    return pos;
}
//MODIFICADORS-------------------------------------------------------------------------------
//Pre:-- //Post:demana llavor, jugadors i num de baralles
void Joc::inicialitzar()
{
    cout <<"*** JOC DE L'ESCLAU ***" <<endl;
    cout <<"ENTRA LA LLAVOR:" <<endl;
    cin >>a_llavor;
    do{
        cout<<"ENTRA EL NOMBRE DE JUGADORS:" <<endl;
        cin >>a_n;
    }while(a_n<2 && a_n>12);
    a_j= new Jugador[a_n];
    for(int i = 0; i < a_n; i++){
        cout<<"ENTRA EL NOM DEL JUGADOR/A "<<i+1<<":" <<endl;
        string nom;
        cin >> nom;
        a_j[i] = Jugador(nom);//inserim els jugadors
    }
    do{
        cout <<"ENTRA EL NOMBRE DE BARALLES:" <<endl;
        cin >>a_baralla;
        }while(a_baralla<1 && a_baralla>3);
}

void Joc::generarCartes(ConjuntCartes *t)
{
    for(int i=0; i<a_baralla; i++)
    {
        for(int j=0; j<N_PALS; j++)
        {
            for(int k=0; k<N_CARTES; k++)
            {
                (*t)+=Carta(k+1,j); //metode de ConjuntCartes
            }
        }
    }
}

unsigned Joc::seguent()
{
    a_llavor=A*a_llavor+C;
    return a_llavor;
}

int Joc::calcular_pos(int maxim)
{
    return ((seguent()/32)%M)%maxim;
}

void Joc::barrejarCartes(ConjuntCartes *t, int n_total)
{
  for(int i=n_total-1; i>0; i--){
    int pos=calcular_pos(i+1);
    t->intercanviar_cartes(i, pos);
  }
}

void Joc::repartirCartes(ConjuntCartes *t, int n_total)
{
    int k=a_n-1; //ultim jugador
    for(int i=0; i<n_total; i++) //recorre la baralla
    {
        a_j[k].inserirCartaOrdJugador(t->obtenirCarta(i));
        k--;
        if(k<0) //torna a començar
        {
            k=a_n-1;
        }
    }

}

void Joc::generarIRepartirCartes()
{
    int n_total=a_baralla*N_PALS*N_CARTES;
    ConjuntCartes *total= new ConjuntCartes(n_total);
    generarCartes(total);
    barrejarCartes(total, n_total);
    repartirCartes(total, n_total);
}

void Joc::empilarCartesIEliminar(Jugada ultima, int k, int &actius)
{
    for(int i=0; i<ultima.rebreQuant(); i++){ //anem carta a carta (SEGUR LES TE)
    pila.empila(a_j[k].buscarCarta(ultima.rebreNum())); //empila la carta
    a_j[k].eliminarCarta(ultima.rebreNum());//elimina la carta de la ma del jugador
    }
    if(a_j[k].NoQuedenCartes()){ //comprovem si s'ha quedat sense cartes
        actius--;
        a_j[k].actualitzarEstat(); //si es aixi el posem a inactiu, no juga mes
    }
}

void Joc::ronda()
{
    int actius=a_n;
    a_classificacio= new Jugador[a_n]; //inicialitzem una taula de jugadors classificats
    Jugada ultimaj;
    ultimaj.inicialitzar();//la ultima jugada seran nombres negatius
    Jugada seguentj;
    bool antAcaba;
    int comptPassen=0;
    int i=0, ant; //i es l'index de la taula a_j
        while(actius!=1){ //mentre quedi mes d'un jugador fem jugades
            if(a_j[i].estaActiu()){ //comprovem que el jugador jugui
                if(ultimaj.esDos() || comptPassen==actius-1){ //criteri per saber si cal iniciar torn de nou i QUI ho fa
                    if(ultimaj.esDos()) i=ant; //si l'ultim tira dos, qui comença la jugada es ell mateix
                    cout<<"- TORN DEL JUGADOR/A "<<a_j[i].obtenirNom()<<" -"<<endl;
                    cout<<"EL JUGADOR/A "<<a_j[i].obtenirNom()<<" INICIA TORN." <<endl;
                    ultimaj.inicialitzar();
                }
                else cout<<"- TORN DEL JUGADOR/A "<<a_j[i].obtenirNom()<<" -"<<endl;
                cout<<"MA:"<<endl;
                a_j[i].mostrarCartesJugador(); //mostra la ma del jugador
                bool esValida, usaPila;
                do{
                    seguentj=a_j[i].fer_jugada(); //jugador fa jugada
                    esValida=true;
                    usaPila=false;
                    if(seguentj.jugadorUsaPila()){ //utilitza la pila en l'actual jugada
                        cout<<"DARRERES CARTES TIRADES:" <<endl;
                        pila.mostrarDeu();
                        usaPila=true; //repeteix bucle
                    }
                    else if(seguentj.passa()){ //jugador passa
                            cout<<"EL JUGADOR/A " <<a_j[i].obtenirNom()<< " PASSA." <<endl;
                            comptPassen++;
                            if(antAcaba) comptPassen=0; //si el jugador anterior ha acabat ronda NO compta com a passada
                    }
                    else{//cal verificar jugada
                        comptPassen=0;
                        if(!a_j[i].teCartes(seguentj)){ //si te les cartes
                            cout <<"ERROR. EL JUGADOR NO TE AQUESTES CARTES" <<endl;
                            esValida=false;
                        }
                        else if(!seguentj.mesGran(ultimaj)){ //si les cartes superen les de la ultima jugada
                            cout<<"ERROR. AMB AQUESTA TIRADA NO SUPERES LES CARTES ACTUALS" <<endl;
                            esValida=false;
                        }
                    }
                }
                while(!esValida || usaPila);
                antAcaba=false;
                if(!seguentj.passa()){ //si el jugador no ha passat
                    ultimaj=seguentj; //actualitcem ultima jugada
                    a_j[i].mostrarCartesjugades(ultimaj); //mostrem les cartes
                    empilarCartesIEliminar(ultimaj, i, actius); //empilem i eliminem les cartes, actualitzant estat jugador
                    if(!a_j[i].estaActiu()){//comrpovem si s'ha quedat sense cartes en aquesta tirada
                            cout<<"EL JUGADOR/A "<<a_j[i].obtenirNom()<<" HA FINALITZAT EN LA POSICIO "<<(a_n-actius)<<"."<<endl;
                            a_classificacio[(a_n-1)-actius]=Jugador(a_j[i].obtenirNom()); //creem aquest jugador a la taula guanyadors, ja en ordre i actiu
                            antAcaba=true;

                    }
                }
                ant=i; //guardem la pos d'aquest jugador per si calgues restaurar
            }
            i++; //seguent jugador
            if(i>a_n-1) i=0; //vigilar si s'arriba a l'ultim jugador
        }
    a_classificacio[a_n-1]=Jugador(a_j[buscarUltim()].obtenirNom()); //l'ultim jugador s'ha d'inserir a la taula classificats
}

void Joc::inicialitzarRonda()
{
    delete [] a_j; //eliminem la taula jugadors
    a_j=a_classificacio; //punter a classificats
    pila.buidarTotalment(); //alliberem la pila

}

void Joc::intercanviarCartes()
{
    int numCartes=a_n/2; //quantes cartes intercanvieran
    int index=0; //index de taula jugadors
    while(numCartes>0){
        a_j[index].repCartes(a_j[a_n-1-index], numCartes);//el guanyador rep les cartes del perdedor, sempre numCartes ultimes
        a_j[a_n-1-index].eliminarFinal(numCartes); //eliminem les cartes de la ma del perdedor
        cout<<"EL JUGADOR/A "<<a_j[index].obtenirNom()<<" I EL JUGADOR/A " <<a_j[a_n-1-index].obtenirNom()<<" INTERCANVIEN "<<numCartes<<" CARTES" <<endl;
        cout<<"- JUGADOR/A "<<a_j[index].obtenirNom()<<" -"<<endl;
        a_j[index].mostrarCartesJugador();
        cout<<"QUINES CARTES VOLS INTERCANVIAR?" <<endl;
        for(int i=0; i<numCartes; i++){
            int canviar;
            cin >>canviar; //entren quines cartes vol canviar una a una
            Carta c=a_j[index].buscarCarta(canviar); //agafem la carta que vol canviar
            a_j[a_n-1-index].inserirCartaOrdJugador(c);//la inserim a la ma del perdedor
            a_j[index].eliminarCarta(canviar);//la eliminem de la ma del guanyador
        }
        numCartes--; //restem num cartes pels seguents
        index++; //ens movem als seguents jugadors
    }
}

//OPERADORS REDEFINITS------------------------------------------------------------------------
Joc& Joc::operator=(const Joc&j)
{
    if(&j != this){
        alliberar();
        copiar(j);
    }
    return(*this);
}
//PRIVATS-------------------------------------------------------------------------------------
void Joc::alliberar()
{
    delete [] a_j;
    delete [] a_classificacio;
    a_n= 0;
}

void Joc::copiar(const Joc& j)
{
    pila=j.pila;
    a_llavor=j.a_llavor;
    a_baralla=j.a_baralla;
    a_n=j.a_n;
    a_j= new Jugador[a_n];
    for(int i=0; i<a_n; i++)
        a_j[i]=j.a_j[i];
    a_classificacio= new Jugador[a_n];
    for(int i=0; i<a_n; i++)
        a_classificacio[i]=j.a_classificacio[i];
}

