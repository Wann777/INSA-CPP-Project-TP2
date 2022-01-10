/*************************************************************************
                           Manager  -  description
                             -------------------
    début                : $10/01/2022$
    copyright            : (C) $2022$ par $tdang,esoulier$
    e-mail               : $thanh.dang@insa-lyon.fr, erwan.soulier@insa-lyon.fr$
*************************************************************************/

//---------- Réalisation de la classe <Manager> (fichier Manager.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Manager.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Manager::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Manager & Manager::operator = ( const Manager & unManager )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Manager::Manager ( const Manager & unManager )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Manager>" << endl;
#endif
} //----- Fin de Manager (constructeur de copie)


Manager::Manager ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Manager>" << endl;
#endif
} //----- Fin de Manager


Manager::~Manager ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Manager>" << endl;
#endif
} //----- Fin de ~Manager


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

