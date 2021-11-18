/*************************************************************************
                           ListeTrajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <ListeTrajet> (fichier ListeTrajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "ListeTrajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type ListeTrajet::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

Maillon * ListeTrajet::getListe() const
{
    return Liste;
}


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
ListeTrajet::ListeTrajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ListeTrajet>" << endl;
#endif
    Liste=NULL;
} //----- Fin de ListeTrajet


ListeTrajet::~ListeTrajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ListeTrajet>" << endl;
#endif
} //----- Fin de ~ListeTrajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

