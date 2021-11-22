/*************************************************************************
                           Maillon  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Maillon> (fichier Maillon.h) ----------------
#if ! defined ( Maillon_H )
#define Maillon_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Maillon>
//
//
//------------------------------------------------------------------------

class Maillon
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void setSuiv (Maillon * suiv);
    void setSuivNull();
    void setTrajet(Trajet * newtrajet);
    Maillon * getSuiv();
    Trajet * getTrajet();

//-------------------------------------------- Constructeurs - destructeur
    Maillon ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Maillon (const Trajet * trajett);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Maillon ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    Trajet * unTrajet;
    Maillon * MaillonSuiv; 

};

//-------------------------------- Autres définitions dépendantes de <Maillon>

#endif // Maillon_H

