/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream> 
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Trajet::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Trajet::Afficher(void) const{
    cout << "Check" << endl;
}

char * Trajet::Rechercher(const char * VD, const char * VA) const
{
    char * tmp=new char[4];
    strcpy(tmp,"non");
    return tmp;
}

char * Trajet::getVilleDepart() const
{
    char * tmp=new char[4];
    strcpy(tmp,"non");
    return tmp;
}

char * Trajet::getVilleArrive() const
{
    char * tmp=new char[4];
    strcpy(tmp,"non");
    return tmp;
}

//-------------------------------------------- Constructeurs - destructeur
Trajet::Trajet ( const Trajet & unTrajet )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Trajet>" << endl;
#endif
    //VilleDepart = new char[strlen(unTrajet.VilleDepart)+1];
    //VilleArrive = new char[strlen(unTrajet.VilleArrive)+1];

    //strcpy(VilleDepart,unTrajet.VilleDepart);
    //strcpy(VilleArrive,unTrajet.VilleArrive);

} //----- Fin de Trajet (constructeur de copie)


Trajet::Trajet ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
} //----- Fin de Trajet


Trajet::~Trajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
} //----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

