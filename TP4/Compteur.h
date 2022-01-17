/*************************************************************************
                           Compteur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Compteur> (fichier Compteur.h) ----------------
#if ! defined ( COMPTEUR_H )
#define COMPTEUR_H

//--------------------------------------------------- Interfaces utilisées
#include "Renseignement.h"
#include <map>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Compteur>
//
//
//------------------------------------------------------------------------

class Compteur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void Ajouter(Renseignement * r);
    void Afficher(void);
    void Trier(void);


//------------------------------------------------- Surcharge d'opérateurs
    //Compteur & operator = ( const Compteur & unCompteur );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    //Compteur ( const Compteur & unCompteur );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Compteur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Compteur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    typedef map<string,int> Tcompte;
    Tcompte compteCibles;
    typedef multimap<int,string,greater<int>> Tcomptetrier;
    Tcomptetrier compteCiblesTrier;

};

//-------------------------------- Autres définitions dépendantes de <Compteur>

#endif // Compteur_H

