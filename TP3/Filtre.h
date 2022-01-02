/*************************************************************************
                           Filtre  -  description
                             -------------------
    début                : $02/01/2022$
    copyright            : (C) $2022$ par $tdang,esoulier$
    e-mail               : $thanh.dang@insa-lyon.fr, erwan.soulier@insa-lyon.fr$
*************************************************************************/


//---------- Interface de la classe <Filtre> (fichier Filtre.h) ----------------
#if ! defined ( Filtre_H )
#define Filtre_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
class Trajet;

//------------------------------------------------------------------------
// Rôle de la classe <Filtre>
//  La classe Filtre est la classe mère de FiltreSans, FilleType, FiltreVille et FiltreInter
//  Elle permet d'utiliser le polymorphisme afin de
//ne pas différencier ses cinq classes filles
//
//------------------------------------------------------------------------

class Filtre
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

   virtual bool Valide ( const Trajet& unTrajet ) = 0;
    // Mode d'emploi :
    // unTrajet : un trajet à filtrer
    // Détermine si le Trajet unTrajet peut passer 	 //le filtre
    // Contrat :
    // 
//-------------------------------------------- Constructeurs - destructeur
    Filtre ( const Filtre & unFiltre );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
  
    Filtre ();

    virtual ~Filtre ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
	



//----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Filtre>

#endif // Filtre_H

