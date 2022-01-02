/*************************************************************************
                           Filtre  -  description
                             -------------------
    début                : $02/01/2022$
    copyright            : (C) $2022$ par $tdang,esoulier$
    e-mail               : $thanh.dang@insa-lyon.fr, erwan.soulier@insa-lyon.fr$
*************************************************************************/



//---------- Réalisation de la classe <Filtre> (fichier Filtre.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream> 

//------------------------------------------------------ Include personnel
#include "Filtre.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Trajet::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode



//-------------------------------------------- Constructeurs - destructeur

Filtre::Filtre ()
// Algorithme :
//
{
	
#ifdef MAP
    cout << "Appel au constructeur de <Filtre>" << endl;
#endif
} //----- Fin de Filtre


Filtre::~Filtre ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Filtre>" << endl;
#endif
} //----- Fin de ~Filtre


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
