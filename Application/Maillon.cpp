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

void Maillon::setSuiv (Maillon * suiv)
// Algorithme :
//  Permet de positionner le maillon suivant
{
    MaillonSuiv=suiv;
}

void Maillon::setSuivNull()
// Algorithme :
//  Permet de positionner le maillon suivant à null
{
    MaillonSuiv=NULL;
}

void Maillon::setTrajet (Trajet * newtrajet)
// Algorithme :
//  Permet de positionner le trajet à newtrajet
{
    unTrajet=newtrajet;
}

Maillon * Maillon::getSuiv ()
// Algorithme :
//  Retourner le maillon suivant
{
    return MaillonSuiv;
}

Trajet * Maillon::getTrajet ()
// Algorithme :
//  Permet de retourner le trajet
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


Maillon::Maillon (const TrajetSimple * trajett)
// Algorithme : 
//  Construit le maillon en initialisant un nouveau trajet simple et en mettant le maillon suivant à null
{
#ifdef MAP
    cout << "Appel au constructeur de <Maillon>" << endl;
#endif
    TrajetSimple *nouvelTraj = new TrajetSimple(*trajett);
    unTrajet=nouvelTraj;
    MaillonSuiv=NULL;
} //----- Fin de Maillon


Maillon::~Maillon ( )
// Algorithme :
//  Destructeur de maillon
{
#ifdef MAP
    cout << "Appel au destructeur de <Maillon>" << endl;
#endif
} //----- Fin de ~Maillon


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

