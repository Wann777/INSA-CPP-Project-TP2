/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $15/11/2021$
    copyright            : (C) $2021$ par $tdang,esoulier$
    e-mail               : $thanh.dang@insa-lyon.fr, erwan.soulier@insa-lyon.fr$
*************************************************************************/


//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void TrajetSimple::Afficher() const
{
    cout << "TRAJET SIMPLE :" << NomTrajet <<endl;
    cout << "Ville de Depart : " << VilleDepart << endl;
    cout << "Ville d'Arrive : " << VilleArrive << endl;
    cout << "Moyen de transport : " << MoyenDeTransport << endl;
    //cout << "==============================================" << endl;
    //cout << endl;
}

string TrajetSimple::getDescription () const
{
// Algorithme :
// Retourne une chaine de caracteres qui decrit les infos de trajet
// chaque element de trajet se separe par un ,

	return "S-" + NomTrajet +":" + VilleDepart  + ","
	       	+ VilleArrive  +	","+ MoyenDeTransport+",";
}	

const string TrajetSimple::Rechercher(const string& VD, const string& VA) const
// Algorithme :
//  Vérifie si la ville de départ coresponds à VD et la ville d'arrivée à VA
//  Si oui, retourne le nom du trajet, 
// si oui pour la ville de depart mais non pour ville d'arrivee, retourne 'VD'
// Si non les 2, retourne 'non'
{
    if (VilleDepart.compare(VD)==0)
    {
		if (VilleArrive.compare(VA)==0) return NomTrajet;
		else return "VD";
    }
    return "non";
}

const string& TrajetSimple::getVilleDepart() const
{
    return VilleDepart;
}

const string& TrajetSimple::getVilleArrive() const
{
    return VilleArrive;
}

const string& TrajetSimple::getNom() const
{
    return NomTrajet;
}

const string& TrajetSimple::getMoyen() const
{
    return MoyenDeTransport;
}


//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple ( const TrajetSimple & unTrajetSimple ) :
VilleDepart(unTrajetSimple.VilleDepart), VilleArrive(unTrajetSimple.VilleArrive)
, MoyenDeTransport(unTrajetSimple.MoyenDeTransport),
NomTrajet(unTrajetSimple.NomTrajet)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
#endif
} //----- Fin de TrajetSimple (constructeur de copie)

TrajetSimple::TrajetSimple (const string& uneDescription)
// Algorithme :
// 
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple> en utilisant string&" << endl;
#endif
    stringstream ss;
    ss.str(uneDescription);
    string type;

    getline(ss,type,'-');
    getline(ss,NomTrajet,':');
    getline(ss,VilleDepart,',');
    getline(ss,VilleArrive,',');
    getline(ss,MoyenDeTransport,',');


} //----- Fin de TrajetSimple (const string&)


TrajetSimple::TrajetSimple ( const string& VD, const string& VA, 
const string& MT, const string& Nom): VilleDepart(VD), VilleArrive(VA),
MoyenDeTransport(MT), NomTrajet(Nom)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de TrajetSimple

 
TrajetSimple::~TrajetSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

