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
        int present=compteCibles.count(r->getCible());
        if(present==0)
        {
            compteCibles.insert(make_pair(r->getCible(),1));
        }
        else if (present==1)
        {
            int occurences = compteCibles.find(r->getCible())->second;
            compteCibles.erase(r->getCible());
            compteCibles.insert(make_pair(r->getCible(),++occurences));
        }
    }
}

void Compteur::Afficher(void)
{
    Tcomptetrier::iterator debut, fin;
    debut = compteCiblesTrier.begin();
    fin = compteCiblesTrier.end();
    while (debut != fin)
    {
        cout << debut->first << endl;
        cout << debut->second << endl;
        debut++;
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

