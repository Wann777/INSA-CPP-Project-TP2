/*************************************************************************
                           Compteur  -  description
                             -------------------
    début                : $10/01/2022$
    copyright            : (C) $2022$ par $tdang,esoulier$
    e-mail               : $thanh.dang@insa-lyon.fr, erwan.soulier@insa-lyon.fr$
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
//Algorithme :
// Chercher la cible dans la map Tcompte en ultisant la methode find()

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


void Compteur::Trier(void)
{
//Algorithme :
// Parcourir la map et inverser chaque couple <string,int> pour obtenir une nouvelle map de type <int,string>
// Le tri de l'ordre decroissant de hits est fait automatiquement
// grace a un conteneur specifique map <int,string, greater <int>>
    Tcompte::iterator debut, fin;
    debut = compteCibles.begin();
    fin = compteCibles.end();
    while (debut != fin)
    {
        compteCiblesTrier.insert(make_pair(debut->second,debut->first));
        debut++;
    }
}


//------------------------------------------------- Surcharge d'opérateurs
ostream & operator << (ostream & os,const Compteur &c)
{
// Algorithme :
// Parcourir la structure Tcomptetrier en utilisant les iterateurs
// On s'arrete au 10e element et faire apparaitre leur nombre de hits a la sortie standard
    Tcomptetrier::const_iterator it,debut,fin;
    debut = c.compteCiblesTrier.begin();
    fin = c.compteCiblesTrier.end();
    int i;
    for (it = debut, i=0; it!=fin && i < 10; ++it , ++i)
    {
        os << it->second << " (" << it->first << " hits)" << endl;
    }
    return os;
}

//-------------------------------------------- Constructeurs - destructeur
/*Compteur::Compteur ( const Compteur & unCompteur )
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

