/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $15/11/2021$
    copyright            : (C) $2021$ par $tdang,esoulier$
    e-mail               : $thanh.dang@insa-lyon.fr, erwan.soulier@insa-lyon.fr$
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TrajetCompose_H )
#define TrajetCompose_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "ListeTrajet.h"
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
//  La classe trajet composé se comporte comme un trajet mais qui possède plusieurs
//  escales, donc une multitudes de trajets directs.
//
//------------------------------------------------------------------------
class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :

    void Afficher() const;
    // Mode d'emploi :
    //  Permet d'afficher tout les trajets simples du trajet composé
    // Contrat :
    //
    void AjouterTrajetSimple();
    // Mode d'emploi :
    //  Permet d'ajouter un trajet simple dans la liste de trajets
    // Contrat :
    //
    char * Rechercher(const char * VD, const char * VA) const;
    // Mode d'emploi :
    //  Permet de rechercher si ce trajet composé a pour trajet de départ VD
    //  passé en paramètre et comme ville d'arrivée ou d'escale VA
    //  passée en paramètre
    // Contrat :
    //
    char * getVilleDepart() const;
    // Mode d'emploi :
    //  Service permettant de retourner la ville de départ du trajet
    // Contrat :
    //
    char * getVilleArrive() const;
    // Mode d'emploi :
    //  Service permettant de retourner la ville d'arrivée du trajet composé
    //  cad la ville d'arrivee du dernier sous trajet
    // Contrat :
    //
    char * getNom() const;
    // Mode d'emploi :
    //  Service permettant de retourner le nom du trajet composé

    std::string getDescription () const;
    //Mode d'emploi:
    // Service permettant de retourner les infos d'un trajet compose en chaine
    // de caracteres
    // Contrat:
    // un trajet compose valide



	

//-------------------------------------------- Constructeurs - destructeur
    TrajetCompose ( const TrajetCompose & unTrajetCompose );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
	
    TrajetCompose (const string& uneDescription);
    // Mode d'emploi :
    //  Permet d'initialiser un trajet compose à partir d'une description 
    //  qui contient des infos de trajet
    //  Contrat: description est une chaine de caracteres

    TrajetCompose (const char * Nom);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~TrajetCompose ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
string convertirChar (const char* unPtrChar)const;

//----------------------------------------------------- Attributs protégés
    char * nomDeTrajet;
    ListeTrajet sousTrajets;

};

//-------------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TrajetCompose_H

