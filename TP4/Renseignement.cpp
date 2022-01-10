/*************************************************************************
                           Renseignement  -  description
                             -------------------
    début                : $10/01/2022$
    copyright            : (C) $2022$ par $tdang,esoulier$
    e-mail               : $thanh.dang@insa-lyon.fr, erwan.soulier@insa-lyon.fr$
*************************************************************************/

//---------- Réalisation de la classe <Renseignement> (fichier Renseignement.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Renseignement.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Renseignement::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
//Renseignement & Renseignement::operator = ( const Renseignement & unRenseignement )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Renseignement::Renseignement ( const Renseignement & unRenseignement )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Renseignement>" << endl;
#endif
} //----- Fin de Renseignement (constructeur de copie)


Renseignement::Renseignement ( string source, string destination, string heure) : cible(source), referer(destination), date(heure)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Renseignement>" << endl;
#endif
} //----- Fin de Renseignement


Renseignement::~Renseignement ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Renseignement>" << endl;
#endif
} //----- Fin de ~Renseignement


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

