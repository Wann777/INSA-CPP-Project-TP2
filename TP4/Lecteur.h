/*************************************************************************
                           Lecteur  -  description
                             -------------------
    début                : $10/01/2022$
    copyright            : (C) $2021$ par $tdang,esoulier$
    e-mail               : $thanh.dang@insa-lyon.fr, erwan.soulier@insa-lyon.fr$
*************************************************************************/

//---------- Interface de la classe <Lecteur> (fichier Lecteur.h) ----------------
#if ! defined ( LECTEUR_H )
#define LECTEUR_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Renseignement.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Lecteur>
// Lire de fichier .log ligne par ligne et recuperer les informations utiles
//------------------------------------------------------------------------

class Lecteur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    Renseignement* LireLigne ( void );
    // Mode d'emploi :
    // Lire une ligne du fichier log et renvoyer un pointeur vers l'objet de type 
    // Renseignement qui est les infos du document
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Lecteur & operator = ( const Lecteur & unLecteur );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Lecteur ( const Lecteur & unLecteur );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Lecteur ( const std::string& unNomFic );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Lecteur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    std::string nomFic;
    std::ifstream ifsNomFic; //ouvrir le fichier nomme nomFic en lecture
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Lecteur>

#endif // Lecteur_H
