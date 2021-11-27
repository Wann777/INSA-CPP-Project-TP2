/*************************************************************************
                           Maillon  -  description
                             -------------------
    début                : $15/11/2021$
    copyright            : (C) $2021$ par $tdang,esoulier$
    e-mail               : $thanh.dang@insa-lyon.fr, erwan.soulier@insa-lyon.fr$
*************************************************************************/


//---------- Interface de la classe <Maillon> (fichier Maillon.h) ----------------
#if ! defined ( Maillon_H )
#define Maillon_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "TrajetSimple.h"

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

    Maillon (const TrajetSimple * trajett);
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

