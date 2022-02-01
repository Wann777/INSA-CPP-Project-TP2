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
using namespace std;
#include <string>
#include <iostream>
#include <sstream>
#include "Renseignement.h"
#include "Lecteur.h"
#include "Compteur.h"
#include "Graphe.h"

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


    Manager (const string& nomFic);
    // Mode d'emploi :
    //
    // Contrat :
    //

    Manager (const string& nomFic, const string& nomGraphe, bool opte, bool optt, bool optg, int h);
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
 

//----------------------------------------------------- Attributs protégés
   Lecteur * lec;
    bool optionE;
    bool optionT;
    bool optionG;
    Compteur * compt;
    Graphe* graph;
    int heure;
};

//-------------------------------- Autres définitions dépendantes de <Manager>
string getExtension (const string& nomFichier); //fonction ordinaire
#endif // MANAGER_H

