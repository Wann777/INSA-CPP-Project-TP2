/*************************************************************************
                           FiltreVille -  description
                             -------------------
    début                : $02/01/2022$
    copyright            : (C) $2022$ par $tdang,esoulier$
    e-mail               : $thanh.dang@insa-lyon.fr, erwan.soulier@insa-lyon.fr$
*************************************************************************/


//---------- Interface de la classe <FiltreVille> (fichier FiltreVille.h) ----------------
#if ! defined ( FiltreVille_H )
#define FiltreVille_H

//--------------------------------------------------- Interfaces utilisées
#include "Filtre.h"
#include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
class Trajet;
//------------------------------------------------------------------------
// Rôle de la classe <FiltreVille>
//  La classe FiltreSans signifie un filtre de ville de depart et/ou d'arrivee
//  Elle permet de n'accepter que les trajets ayant comme ville de départ (VD) ET / OU les trajets ayant comme ville d'arrivée (VA)
//
//
//------------------------------------------------------------------------

class FiltreVille : public Filtre
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
    FiltreVille ( const FiltreVille & unFiltreVille );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
  
    FiltreVille (const std::string& villeD, const std::string& villeA);
    // Mode d'emploi :
    // villeD représente la ville de départ que l'on veut avoir pour tous
    // villeA représente la ville d'arrivee que l'on veut avoir pour tous les trajets valides. 
    //Si villeD ou villeA est égal à "0", le filtre ne la prend pas en compte.
    //Si villeD = villeA = "0", aucun filtrage, ce filtre est équivalent à un FiltreSans.
    // Contrat :
    // Rien

    virtual ~FiltreVille ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
	



//----------------------------------------------------- Attributs protégés
std::string VD;
std::string VA;
};

//-------------------------------- Autres définitions dépendantes de <FiltreVille>

#endif // FiltreVille_H

