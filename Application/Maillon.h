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
//  Un maillon est simplement un maillon de la liste de trajet.
//  Il possède un pointeur sur un trajet et fait le lien avec le maillon suivant de la liste grace
//  à un pointeur sur un autre maillon.
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
    // Mode d'emploi :
    //  Permet de positionner le maillon suivant avec un pointeur sur un maillon
    //  donné en paramètre via suiv
    // Contrat :
    //  
    void setSuivNull();
    // Mode d'emploi :
    //  Permet de positionner le pointeur sur un autre maillon à null.
    // Contrat :
    //  
    void setTrajet(Trajet * newtrajet);
    // Mode d'emploi :
    //  Permet de positionner le pointeur de trajet sur un trajet via
    //  Un trajet donné en paramètre nommé newtrajet
    // Contrat :
    //  
    Maillon * getSuiv();
    // Mode d'emploi :
    //  Permet de récupérer le maillon suivant
    // Contrat :
    //  
    Trajet * getTrajet();
    // Mode d'emploi :
    //  Permet de récupérer le trajet pointé
    // Contrat :
    //  

//-------------------------------------------- Constructeurs - destructeur
    Maillon ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Maillon (const TrajetSimple * trajett);
    // Mode d'emploi :
    //  Constructeur de maillon à partir un pointeur sur un trajet passé
    //  En paramètre via trajett
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

