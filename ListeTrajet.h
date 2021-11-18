/*************************************************************************
                           ListeTrajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <ListeTrajet> (fichier ListeTrajet.h) ----------------
#if ! defined ( ListeTrajet_H )
#define ListeTrajet_H

//--------------------------------------------------- Interfaces utilisées
#include "Maillon.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ListeTrajet>
//
//
//------------------------------------------------------------------------

class ListeTrajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    Maillon * getListe() const;


//-------------------------------------------- Constructeurs - destructeur
    ListeTrajet ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ListeTrajet ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    Maillon * Liste;

};

//-------------------------------- Autres définitions dépendantes de <ListeTrajet>

#endif // ListeTrajet_H

