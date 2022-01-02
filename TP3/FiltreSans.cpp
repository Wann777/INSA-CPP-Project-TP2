/*************************************************************************
                           FiltreSans  -  description
                             -------------------
    début                : $02/01/2022$
    copyright            : (C) $2022$ par $tdang,esoulier$
    e-mail               : $thanh.dang@insa-lyon.fr, erwan.soulier@insa-lyon.fr$
*************************************************************************/



//---------- Réalisation de la classe <FiltreSans> (fichier FiltreSans.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream> 

//------------------------------------------------------ Include personnel
#include "FiltreSans.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Trajet::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
bool FiltreSans::Valide ( const Trajet& unTrajet )
{
    unTrajet.getDescription(); // pour eviter l'avertissment 'unused parameter'
    return true;
}


//-------------------------------------------- Constructeurs - destructeur

FiltreSans::FiltreSans ()
// Algorithme :
//
{
	
#ifdef MAP
    cout << "Appel au constructeur de <FiltreSans>" << endl;
#endif
} //----- Fin de FiltreSans


FiltreSans::~FiltreSans ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <FiltreSans>" << endl;
#endif
} //----- Fin de ~FiltreSans


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
