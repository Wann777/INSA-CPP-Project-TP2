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
#include <string>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "Renseignement.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
const string& Renseignement::getCible ()

// Algorithme :
//
{
    return cible;
} //----- Fin de Méthode

const string& Renseignement::getReferer ()

// Algorithme :
//
{
    return referer;
} //----- Fin de Méthode


const string& Renseignement::getHeure ()

// Algorithme :
//
{
    return unMoment.heure;
} //----- Fin de Méthode
    
//------------------------------------------------- Surcharge d'opérateurs
//Renseignement & Renseignement::operator = ( const Renseignement & unRenseignement )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
/*Renseignement::Renseignement ( const Renseignement & unRenseignement )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Renseignement>" << endl;
#endif
} //----- Fin de Renseignement (constructeur de copie)
*/

Renseignement::Renseignement ( string dest, string sour, string moment) : cible(dest), referer(sour)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Renseignement>" << endl;
#endif
    this->makeMomentPrecis(moment);
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
void Renseignement::makeMomentPrecis (const string& moment)
{
// Algorithme :
// A partir une chaine de caractere qui designe le moment de consultation
// on la decompose en elements plus precis de la structure MOMENT(date, mois, heure,..)
	
    stringstream ss;
    ss.str(moment);
    getline (ss, unMoment.date, '/');
    getline (ss, unMoment.mois, '/');
    getline (ss, unMoment.an, ':');
    getline (ss, unMoment.heure, ':');
    getline (ss, unMoment.minute, ':');
    getline (ss, unMoment.seconde, ' ');
    getline (ss, unMoment.decalage, ']');
}

