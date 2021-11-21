/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $15/11/2021$
    copyright            : (C) $2021$ par $tdang,esoulier$
    e-mail               : $thanh.dang@insa-lyon.fr, erwan.soulier@insa-lyon.fr$
*************************************************************************/


//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( Catalogue_H )
#define Catalogue_H

//--------------------------------------------------- Interfaces utilisées
#include "ListeTrajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//
//
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void Menu ();
    // Mode d'emploi :
    //	Faire apparaître le menu qui permet a l'utilisateur d'avoir l'acces
    //	aux services fournis par le catalogue
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    Catalogue ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Catalogue ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

    void Afficher(void) const;
    // Mode d'emploi :
    // Faire apparaître le contenu du catalogue
    // Contrat :
    //

    /*void Rechercher() const;
    // Mode d'emploi :
    // Service qui permet de rechercher un seul trajet (simple ou compose)
    // entre deux villes,
    // Contrat :
    
    void AjouterTrajetSimple();
    // Mode d'emploi :
    // Service qui permet de ajouter un trajet simple entre deux villes,
    // Contrat :

    void AjouterTrajetCompose();
     // Mode d'emploi :
    // Service qui permet de ajouter un trajet compose entre deux villes,
    // Contrat :
*/

//----------------------------------------------------- Attributs protégés
    ListeTrajet ListeT;
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // Catalogue_H

