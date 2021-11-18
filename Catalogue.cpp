/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Catalogue::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void Catalogue::Afficher(void) const
{
    if (ListeT.getListe()==NULL)
    {
        cout << "OK" << endl;
        return;
    }/*
    ListeTrajet temp=ListeT;
    while(temp.Liste->MaillonSuiv!=NULL)
    {
        temp.Liste->unTrajet.Afficher();
        temp=temp.Liste->MaillonSuiv;
    }*/
}

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue (int test)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
    ListeTrajet tmp();
    ListeT=tmp;
    testl=test;
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

