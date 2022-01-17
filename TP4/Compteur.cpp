/*************************************************************************
                           Compteur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Compteur> (fichier Compteur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Compteur.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Compteur::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void Compteur::Ajouter(Renseignement * r)
{
    if(compteCibles.count(r->getCible())==0)
    {
        compteCibles.insert(make_pair(r->getCible(),1));
    }
}

void Compteur::Afficher(void)
{
    Tcompte::iterator debut, fin;
    debut = compteCibles.begin();
    fin = compteCibles.end();
    while (debut != fin)
    {
        cout << debut->first << endl;
        cout << debut->second << endl;
        debut++;
    }
}


//------------------------------------------------- Surcharge d'opérateurs
/*Compteur & Compteur::operator = ( const Compteur & unCompteur )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Compteur::Compteur ( const Compteur & unCompteur )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Compteur>" << endl;
#endif
} //----- Fin de Compteur (constructeur de copie)
*/

Compteur::Compteur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Compteur>" << endl;
#endif
} //----- Fin de Compteur


Compteur::~Compteur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Compteur>" << endl;
#endif
} //----- Fin de ~Compteur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

