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
// Gerer les options de lecture / Appliquer les filtres
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
    // Faire une lecture globale du fichier .log et ajouter l'objet de type Renseignement 
    // dans le Compteur (et le Graphe)
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
    // implementer les filtres du fichier .log nomme nomFic a partir de commande -g -e -t saisie par l'utilisateur
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
 bool ComparerHeure (const int decalage, int heureCible);

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

