/*************************************************************************
                           FiltreType -  description
                             -------------------
    début                : $02/01/2022$
    copyright            : (C) $2022$ par $tdang,esoulier$
    e-mail               : $thanh.dang@insa-lyon.fr, erwan.soulier@insa-lyon.fr$
*************************************************************************/


//---------- Interface de la classe <FiltreType> (fichier FiltreType.h) ----------------
#if ! defined ( FiltreType_H )
#define FiltreType_H

//--------------------------------------------------- Interfaces utilisées
#include "Filtre.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
class Trajet;
//------------------------------------------------------------------------
// Rôle de la classe <FiltreType>
//  La classe FiltreType signifie un filtre de type
//  Elle permet de n'accepter que les trajets simples ou les trajets composes
//
//
//------------------------------------------------------------------------

class FiltreType : public Filtre
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
    FiltreType ( const FiltreType & unFiltreType );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
  
    FiltreType (bool filtrerTrajCom = false);
    // Mode d'emploi :
    // par defaut, on valide que les trajets simples
    // si filtrerTC = true, on valide les trajets composes
    // Contrat :
    // Rien

    virtual ~FiltreType ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
	



//----------------------------------------------------- Attributs protégés
bool filtrerTC;
};

//-------------------------------- Autres définitions dépendantes de <FiltreType>

#endif // FiltreType_H

