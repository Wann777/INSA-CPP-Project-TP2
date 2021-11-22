/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $15/11/2021$
    copyright            : (C) $2021$ par $tdang,esoulier$
    e-mail               : $thanh.dang@insa-lyon.fr, erwan.soulier@insa-lyon.fr$
*************************************************************************/


//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TrajetSimple::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void TrajetSimple::Afficher() const
{
    cout << "Ville de Depart : " << VilleDepart << endl;
    cout << "Ville d'Arrive : " << VilleArrive << endl;
    cout << "Moyen de transport : " << MoyenDeTransport << endl;
    cout << "Nom du Trajet : " << NomTrajet << endl;
}


//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose ( const TrajetCompose & unTrajetCompose )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
#endif
    VilleDepart = new char[strlen(unTrajetSimple.VilleDepart)+1];
    VilleArrive = new char[strlen(unTrajetSimple.VilleArrive)+1];
    MoyenDeTransport = new char[strlen(unTrajetSimple.MoyenDeTransport)+1];
    NomTrajet = new char[strlen(unTrajetSimple.NomTrajet)+1];

    strcpy(VilleDepart,unTrajetSimple.VilleDepart);
    strcpy(VilleArrive,unTrajetSimple.VilleArrive);
    strcpy(MoyenDeTransport,unTrajetSimple.MoyenDeTransport);
    strcpy(NomTrajet,unTrajetSimple.NomTrajet);
} //----- Fin de TrajetSimple (constructeur de copie)


TrajetSimple::TrajetSimple (const char * VD, const char * VA, const char * MT, const char * Nom)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
    VilleDepart = new char[strlen(VD)+1];
    VilleArrive = new char[strlen(VA)+1];
    MoyenDeTransport = new char[strlen(MT)+1];
    NomTrajet = new char[strlen(Nom)+1];

    strcpy(VilleDepart,VD);
    strcpy(VilleArrive,VA);
    strcpy(MoyenDeTransport,MT);
    strcpy(NomTrajet,Nom);
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

