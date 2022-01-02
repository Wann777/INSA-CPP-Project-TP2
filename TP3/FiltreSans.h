/*************************************************************************
                           FiltreSans -  description
                             -------------------
    début                : $02/01/2022$
    copyright            : (C) $2022$ par $tdang,esoulier$
    e-mail               : $thanh.dang@insa-lyon.fr, erwan.soulier@insa-lyon.fr$
*************************************************************************/


//---------- Interface de la classe <FiltreSans> (fichier FiltreSans.h) ----------------
#if ! defined ( FiltreSans_H )
#define FiltreSans_H

//--------------------------------------------------- Interfaces utilisées
#include "Filtre.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
class Trajet;
//------------------------------------------------------------------------
// Rôle de la classe <FiltreSans>
//  La classe FiltreSans signifie un filtre sans critere de selection 
//  Elle permet de sauvegarder tous les trajets et charger la totalite du contenu de fichier
//
//
//------------------------------------------------------------------------

class FiltreSans : public Filtre
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool Valide ( const Trajet& unTrajet );
    // Mode d'emploi :
    // Détermine si le Trajet unTrajet peut passer 	 //le filtre
    // retourne true si oui
    // Contrat :
    // 
//-------------------------------------------- Constructeurs - destructeur
    FiltreSans ( const FiltreSans & unFiltreSans );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
  
    FiltreSans ();

    virtual ~FiltreSans ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
	



//----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <FiltreSans>

#endif // FiltreSans_H

