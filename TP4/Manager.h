/*************************************************************************
                           Manager  -  description
                             -------------------
    début                : $10/01/2022$
    copyright            : (C) $2022$ par $tdang,esoulier$
    e-mail               : $thanh.dang@insa-lyon.fr, erwan.soulier@insa-lyon.fr$
*************************************************************************/

//---------- Interface de la classe <Manager> (fichier Manager.h) ----------------
#if ! defined ( MANAGER_H )
#define MANAGER_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <iostream>
#include "Renseignement.h"
#include "Lecteur.h"
#include "Compteur.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Manager>
//
//
//------------------------------------------------------------------------

class Manager
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void Execution(void);
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur


    Manager (string nomFic);
    // Mode d'emploi :
    //
    // Contrat :
    //

    Manager (string nomFic, bool opte, bool optt);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Manager ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    Lecteur * lec;
    bool optionE;
    bool optionT;
    Compteur * compt;

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Manager>

#endif // MANAGER_H

