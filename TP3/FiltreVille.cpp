/*************************************************************************
                           FiltreVille  -  description
                             -------------------
    début                : $02/01/2022$
    copyright            : (C) $2022$ par $tdang,esoulier$
    e-mail               : $thanh.dang@insa-lyon.fr, erwan.soulier@insa-lyon.fr$
*************************************************************************/



//---------- Réalisation de la classe <FiltreVille> (fichier FiltreVille.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <string>
#include <iostream> 

//------------------------------------------------------ Include personnel
#include "FiltreVille.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool FiltreVille::Valide (const Trajet& unTrajet)
{
// Algorithme :
//Verifier l'equivalence de la ville de depart et d'arrivee

	 if(VD != "0" && VD != unTrajet.getVilleDepart())
    {
        return false;
    }
    if(VA != "0" && VA != unTrajet.getVilleArrive())
    {
        return false;
    }
    return true;
}//----- Fin de Valide

//-------------------------------------------- Constructeurs - destructeur

FiltreVille::FiltreVille (const string& villeD, const string& villeA): VD(villeD), VA(villeA)
// Algorithme :
//
{
	
#ifdef MAP
    cout << "Appel au constructeur de <FiltreVille>" << endl;
#endif
} //----- Fin de FiltreVille


FiltreVille::~FiltreVille ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <FiltreVille>" << endl;
#endif
} //----- Fin de ~FiltreVille


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
