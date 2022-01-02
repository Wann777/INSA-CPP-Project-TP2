/*************************************************************************
                           FiltreInter  -  description
                             -------------------
    début                : $02/01/2022$
    copyright            : (C) $2022$ par $tdang,esoulier$
    e-mail               : $thanh.dang@insa-lyon.fr, erwan.soulier@insa-lyon.fr$
*************************************************************************/



//---------- Réalisation de la classe <FiltreInter> (fichier FiltreInter.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream> 

//------------------------------------------------------ Include personnel
#include "FiltreInter.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool FiltreInter::Valide (const Trajet& unTrajet)
{
// Algorithme :
// Chaque fois où cette méthode est appelée, l'attribut pos est incrémenté par 1
// Si pos appartient à l'intervalle [n,m], retourne true
	bool val = (pos >= n && pos<= m);
	++pos;
	 unTrajet.getDescription();//pour eviter l'avertissement "unused parameter unTrajet"
	 return val;
}//----- Fin de Valide

//-------------------------------------------- Constructeurs - destructeur

FiltreInter::FiltreInter (unsigned int borInf, unsigned int borSup): n(borInf), m(borSup), pos(0)
// Algorithme :
//
{
	
#ifdef MAP
    cout << "Appel au constructeur de <FiltreInter>" << endl;
#endif
} //----- Fin de FiltreInter


FiltreInter::~FiltreInter ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <FiltreInter>" << endl;
#endif
} //----- Fin de ~FiltreInter


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
