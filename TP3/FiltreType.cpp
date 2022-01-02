/*************************************************************************
                           FiltreType  -  description
                             -------------------
    début                : $02/01/2022$
    copyright            : (C) $2022$ par $tdang,esoulier$
    e-mail               : $thanh.dang@insa-lyon.fr, erwan.soulier@insa-lyon.fr$
*************************************************************************/



//---------- Réalisation de la classe <FiltreType> (fichier FiltreType.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream> 

//------------------------------------------------------ Include personnel
#include "FiltreType.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool FiltreType::Valide (const Trajet& unTrajet)
{
// Algorithme :
// Verifie le premier caractere de la description de trajet si c'est un C ou S


	 if(filtrerTC && unTrajet.getDescription()[0] == 'C')
    {
        return true;
    }
     if(!filtrerTC && unTrajet.getDescription()[0] == 'S')
    {
        return true;
    }
    return false;
}//----- Fin de Valide

//-------------------------------------------- Constructeurs - destructeur

FiltreType::FiltreType (bool filtrerTrajCom): filtrerTC(filtrerTrajCom)
// Algorithme :
//
{
	
#ifdef MAP
    cout << "Appel au constructeur de <FiltreType>" << endl;
#endif
} //----- Fin de FiltreType


FiltreType::~FiltreType ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <FiltreType>" << endl;
#endif
} //----- Fin de ~FiltreType


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
