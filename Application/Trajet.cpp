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

/*
Trajet::Trajet (const char * VD, const char * VA)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
    VilleDepart = new char[strlen(VD)+1];
    VilleArrive = new char[strlen(VA)+1];

    strcpy(VilleDepart,VD);
    strcpy(VilleArrive,VA);
} //----- Fin de Trajet*/

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

