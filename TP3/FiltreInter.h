/*************************************************************************
                           FiltreInter -  description
                             -------------------
    début                : $02/01/2022$
    copyright            : (C) $2022$ par $tdang,esoulier$
    e-mail               : $thanh.dang@insa-lyon.fr, erwan.soulier@insa-lyon.fr$
*************************************************************************/


//---------- Interface de la classe <FiltreInter> (fichier FiltreInter.h) ----------------
#if ! defined ( FiltreInter_H )
#define FiltreInter_H

//--------------------------------------------------- Interfaces utilisées
#include "Filtre.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
class Trajet;
//------------------------------------------------------------------------
// Rôle de la classe <FiltreInter>
//  La classe FiltreType signifie un filtre d'intervalle
//  Elle permet de n'accepter que les trajets dans l'intervalle [n,m] avec n < m et m < le nombre total de trajets
//Les 2 bornes sont toujours dans l'intervalle
//
//------------------------------------------------------------------------

class FiltreInter : public Filtre
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
    FiltreInter ( const FiltreInter & unFiltreInter );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
  
    FiltreInter (unsigned int borInf, unsigned int borSup);
    // Mode d'emploi :
    // borInf est la borne inferieure
    // borSup est la borne superieure

    virtual ~FiltreInter ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
	



//----------------------------------------------------- Attributs protégés
unsigned int n;
unsigned int m;
unsigned int pos; // position d'un trajet dans listeTrajet
};

//-------------------------------- Autres définitions dépendantes de <FiltreInter>

#endif // FiltreInter_H

