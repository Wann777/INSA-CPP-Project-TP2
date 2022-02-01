/*************************************************************************
                           Compteur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Compteur> (fichier Compteur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Compteur.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Compteur::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void Compteur::Ajouter(Renseignement * r)
{
    if(!r->getCible().empty())
    {
		Tcompte::iterator cleAChercher;
		//On verifie si la cible est deja presentee dans la map
		cleAChercher = compteCibles.find(r->getCible());
        if(cleAChercher == compteCibles.end())
        {
			//Si on ne trouve pas la cible r->getCible, on l'ajoute dans la map
            compteCibles.insert(make_pair(r->getCible(),1));
        }
        else
        {
			//Si la cle existe deja dans la map, on augmente le nb d'occurences par 1
			++(cleAChercher->second);
        }
    }
}

void Compteur::Afficher(void)
{
    Tcomptetrier::iterator debut, fin;
    debut = compteCiblesTrier.begin();
    fin = compteCiblesTrier.end();
    int nb = 0;
    while (debut != fin && nb<10)
    {
        cout << debut->second << " (" << debut->first << " hits)" << endl;
        //cout << debut->second << endl;
        debut++;
        nb++;
    }
}

void Compteur::Trier(void)
{
    Tcompte::iterator debut, fin;
    debut = compteCibles.begin();
    fin = compteCibles.end();
    while (debut != fin)
    {
        compteCiblesTrier.insert(make_pair(debut->second,debut->first));
        //cout << debut->first << endl;
        //cout << debut->second << endl;
        debut++;
    }
}


//------------------------------------------------- Surcharge d'opérateurs
/*Compteur & Compteur::operator = ( const Compteur & unCompteur )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Compteur::Compteur ( const Compteur & unCompteur )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Compteur>" << endl;
#endif
} //----- Fin de Compteur (constructeur de copie)
*/

Compteur::Compteur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Compteur>" << endl;
#endif
} //----- Fin de Compteur


Compteur::~Compteur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Compteur>" << endl;
#endif
} //----- Fin de ~Compteur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

