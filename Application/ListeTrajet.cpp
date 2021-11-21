/*************************************************************************
                           ListeTrajet  -  description
                             -------------------
    début                : $15/11/2021$
    copyright            : (C) $2021$ par $tdang,esoulier$
    e-mail               : $thanh.dang@insa-lyon.fr, erwan.soulier@insa-lyon.fr$
*************************************************************************/


//---------- Réalisation de la classe <ListeTrajet> (fichier ListeTrajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
//------------------------------------------------------ Include personnel
#include "ListeTrajet.h"
#include "Trajet.h"
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void ListeTrajet::AjouterElem (const Trajet* unTrajet)
// Algorithme :
// Allocation mémoire d'un nouvel maillon et copie en profondeur d'unTrajet
// Insertion en debut de liste
{
	//Allocation de memoire
	Maillon *nouvelMaill = new Maillon;
	nouvelMaill->suiv= NULL;
	//copie en profondeur
	Trajet *nouvelTraj = new Trajet(*unTrajet);
	nouvelMaill->trajet = nouvelTraj;

	//Insertion en tete
	if (racine ==NULL)
	{
		racine = nouvelMaill;
	}
	else
	{
		nouvelMaill->suiv= racine;
		racine = nouvelMaill;
	}
	
	taille++;
}	//---Fin de methode AjouterElem

const Trajet* ListeTrajet::AccederElem (unsigned int pos) const
{
	if (pos>=taille)
	{ 
		return 0; //position est invalide
	}
	else
	{
		Maillon* courant = racine;
		int posCour= 0;
		while (courant->suiv && posCour<pos)
		{
			courant = courant->suiv;
			posCour++;
		}	
		return courant->trajet;
	}
} //--Fin de methode AccederElem

unsigned int ListeTrajet::getSize () const
{
	return taille;
}



//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
ListeTrajet::ListeTrajet(): racine (0),taille(0)
{
// Constructeur par defaut
#ifdef MAP
    cout << "Appel au constructeur de <ListeTrajet>" << endl;
#endif
}//--Fin de ListeTrajet
ListeTrajet::ListeTrajet (const ListeTrajet & uneListe): racine(NULL),taille(0)
// Algorithme :Constructeur de copie 
// Copie en prof tous les elements d'uneListe
{
#ifdef MAP
    cout << "Appel au constructeur de <ListeTrajet>" << endl;
#endif
    for (unsigned int i = 0;i<uneListe.taille;i++)
	{
	    AjouterElem(uneListe.AccederElem(i));
	} //----- Fin de ListeTrajet (const ListeTrajet & uneListe)
}

ListeTrajet::~ListeTrajet ()
// Algorithme :	Parcourir la liste pour liberer la zone de memoire allouee par 
// chaque maillon
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ListeTrajet>" << endl;
#endif
    Maillon* courant = racine;
    while (courant)
    {
	    delete courant->trajet;
	    Maillon* suiv = courant->suiv;
	    delete courant;
	    courant = suiv;
    }
} //----- Fin de ~ListeTrajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

