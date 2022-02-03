/*************************************************************************
                           Lecteur  -  description
                             -------------------
    début                : $10/01/2022$
    copyright            : (C) $2021$ par $tdang,esoulier$
    e-mail               : $thanh.dang@insa-lyon.fr, erwan.soulier@insa-lyon.fr$
*************************************************************************/

//---------- Réalisation de la classe <Lecteur> (fichier Lecteur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Lecteur.h"
#include <string>
#include <sstream>
//------------------------------------------------------------- Constantes
#define LOCAL "http://intranet-if.insa-lyon.fr"
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Lecteur::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
Renseignement* Lecteur::LireLigne( void )
{
// Algorithme :
// Recuperer les informations utiles pour construire l'objet de type Renseignement
// en utilisants des delimiteurs ], / et "
// si la cible contient intranet..., on l'enleve
	
	string ligne, date, inutile,cible,referer;
	stringstream ss;
	if(ifsNomFic.peek()!=EOF)
	{
	
		getline (ifsNomFic,ligne);
		ss.str(ligne);
		getline (ss, inutile, '[');
		getline (ss, date, ']');				// on recupere la date
		getline (ss, inutile, '/');
		getline (ss, cible, ' ');				// on recupere la cible
		
		
		getline (ss, inutile, '"');
		getline (ss, inutile, '"');
		getline (ss, referer, '"');				// on recupere le referer
		std::size_t found = referer.find(LOCAL);
		if (found!=std::string::npos)
		{
			referer.replace(referer.find(LOCAL),sizeof(LOCAL),"");
		}
		Renseignement* r = new Renseignement ("/" + cible,"/" + referer,date);
		return r;
	}
	return NULL;
}
		
		


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Lecteur::Lecteur ( const Lecteur & unLecteur)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Lecteur>" << endl;
#endif
} //----- Fin de Lecteur (constructeur de copie)


Lecteur::Lecteur( const std::string& unNomFic) : nomFic(unNomFic)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Lecteur>" << endl;
#endif

	ifsNomFic.open(nomFic.c_str(),std::ifstream::in); //ouvrir le fichier nomme nomFic en lecture
} //----- Fin de Lecteur


Lecteur::~Lecteur( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Lecteur>" << endl;
#endif
} //----- Fin de ~Lecteur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
