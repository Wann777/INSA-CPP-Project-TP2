/*************************************************************************
                           Maillon  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Maillon> (fichier Maillon.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Maillon.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Maillon::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void Maillon::setSuiv (Maillon * suiv)
{
    MaillonSuiv=suiv;
}

void Maillon::setSuivNull()
{
    MaillonSuiv=NULL;
}

void Maillon::setTrajet (Trajet * newtrajet)
{
    unTrajet=newtrajet;
}

Maillon * Maillon::getSuiv ()
{
    return MaillonSuiv;
}

Trajet * Maillon::getTrajet ()
{
    return unTrajet;
}


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Maillon::Maillon ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de Base <Maillon>" << endl;
#endif
} //----- Fin de Maillon


Maillon::Maillon (const Trajet * trajett)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Maillon>" << endl;
#endif
    Trajet *nouvelTraj = new Trajet(*trajett);
    unTrajet=nouvelTraj;
    MaillonSuiv=NULL;
} //----- Fin de Maillon


Maillon::~Maillon ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Maillon>" << endl;
#endif
} //----- Fin de ~Maillon


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

